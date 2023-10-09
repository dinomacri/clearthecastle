#include <iostream>

// UI files
//    - For linux: apt install libncurses5-dev 
//    - compile with -lncurses 
#include <sys/ioctl.h>
#include <unistd.h>
#include <curses.h>

#include "Boss.h"
#include "Player.h"
#include "Mob.h"
#include "Item.h"
#include "Entity.h"
#include "Room.h"
#include "Logger.h"

// TODO: Add required file includes here
int *getTerminalSize() {
    static int terminalSize[2]; // Sets return variable to reserve 2 spaces in memory
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);

    terminalSize[0] = w.ws_row; terminalSize[1] = w.ws_col;
    return terminalSize;
} // from https://stackoverflow.com/questions/23369503/get-size-of-terminal-window-rows-columns

void startupMessage() {
  /* INITIALISATION and ARGUMENTS */
  const char *title[] = {" _____ _                   _   _               ","/  __ \\ |                 | | | |             ","| /  \\/ | ___  __ _ _ __  | |_| |__   ___     ","| |   | |/ _ \\/ _` | '__| | __| '_ \\ / _ \\  ","| \\__/\\ |  __/ (_| | |    | |_| | | |  __/   "," \\____/_|\\___|\\__,_|_|     \\__|_| |_|\\___|","        _____           _   _                  ","       /  __ \\         | | | |                ","       | /  \\/ __ _ ___| |_| | ___            ","       | |    / _` / __| __| |/ _ \\           ","       | \\__/\\ (_| \\__ \\ |_| |  __/        ","        \\____/\\__,_|___/\\__|_|\\___| 0.0.1     "};
  const char *sword[] = {"             />","            /<","           /<"," |\\_______{o}----------------------------------------------------------_","[\\\\\\\\\\\\\\{*}:::<=============================================-           >"," |/~~~~~~~{o}----------------------------------------------------------~","           \\>","            \\>","             \\>"};

  int* terminal_window = getTerminalSize(); // Returns [rows, cols]

  initscr(); cbreak(); noecho(); clear(); start_color(); // Initialising nCurses

  init_pair(1, COLOR_CYAN, COLOR_BLACK); // -|
  init_pair(2, COLOR_WHITE, COLOR_BLACK);//  |- Colours Initialisation
  init_pair(3, COLOR_GREEN, COLOR_BLACK);// -|
    
  /* MAIN ASCII ART */
  // Title
  attron(COLOR_PAIR(1)); // Change text colour to cyan
  for (int i = 0; i < static_cast<int>(sizeof(title) / sizeof(title[0])); i++) {
      mvprintw(i,(terminal_window[1]/2)-(47/2),title[i]);
  }
  // Text 1
  attron(COLOR_PAIR(3));
  mvprintw(13, (terminal_window[1]/2)-(24)/2, "By Dino, Darcy, and Will");
    
  // Sword
  attron(COLOR_PAIR(2));
  for (int i = 0; i < static_cast<int>(sizeof(sword) / sizeof(sword[0])); i++) {
      mvprintw(12+i,(terminal_window[1]/2)-(76/2),sword[i]);
  }

  // Text 2
  attron(COLOR_PAIR(2)); // Change text colour to white
  mvprintw(terminal_window[0]-3, (terminal_window[1]/2)-14, "[ Press any key to continue ]");

  /* WAITING FOR KEY STROKE TO FINISH */
  refresh(); getch();
  return;
}

enum CharacterType { WIZARD, WARRIOR, MONK };

struct Character {
    std::string name;
    CharacterType type;
    int health;
    int strength;
    int specialAttribute;
};

Character characterSelection() {
Character character;
    clear();
    printw("Enter your character name: ");
    refresh();

    char name[100];
    getstr(name);
    character.name = name;

    clear();
    printw("Choose your character type:\n");
    printw("1. Wizard\n");
    printw("2. Warrior\n");
    printw("3. Monk\n");
    refresh();

    int typeChoice;
    while (1) {
        typeChoice = getch() - '0';
        if (typeChoice >= 1 && typeChoice <= 3) {
            break;
        }
    }
    character.type = static_cast<CharacterType>(typeChoice - 1);

    clear();
    printw("Distribute 10 points between Health, Strength, and Special Attribute:\n");
    refresh();

    int pointsRemaining = 10;
    while (pointsRemaining > 0) {
        clear();
        printw("Points remaining: %d\n", pointsRemaining);
        printw("1. Health: %d\n", character.health);
        printw("2. Strength: %d\n", character.strength);
        printw("3. Special Attribute: %d\n", character.specialAttribute);
        refresh();

        int attributeChoice;
        while (1) {
            attributeChoice = getch() - '0';
            if (attributeChoice >= 1 && attributeChoice <= 3) {
                break;
            }
        }

        int* attributeToUpdate = nullptr;
        switch (attributeChoice) {
            case 1:
                attributeToUpdate = &character.health;
                break;
            case 2:
                attributeToUpdate = &character.strength;
                break;
            case 3:
                attributeToUpdate = &character.specialAttribute;
                break;
        }

        clear();
        printw("Enter points to add (0-%d): ", pointsRemaining);
        refresh();

        int pointsToAdd;
        while (1) {
            pointsToAdd = getch() - '0';
            if (pointsToAdd >= 0 && pointsToAdd <= pointsRemaining) {
                break;
            }
        }
        *attributeToUpdate += pointsToAdd;
        pointsRemaining -= pointsToAdd;
    }

    return character;
}

int menu() {

    const char * menuTitle[] = {"   __  ___             ","  /  |/  /__ ___  __ __"," / /|_/ / -_) _ \\/ // /","/_/  /_/\\__/_//_/\\_,_/ "};

    clear();
    refresh();
    int * terminal_window = getTerminalSize(); // Returns [rows, cols]

    noecho(); // Don't echo user input
    cbreak(); // Disable line buffering (receive input character-by-character)
    keypad(stdscr, TRUE); // Enable keypad for arrow keys

    int selectedOption = 0;

    int ch;
    while (1) {
      clear(); // Clear the screen

      for (int i = 0; i < 4; i++) {
        mvprintw(1+i, (terminal_window[1]/2)-12, menuTitle[i]);
      }

      // Display your menu options
      mvprintw(terminal_window[0] / 2 - 4, (terminal_window[1] / 2) - 8, "Select an option:");

      for (int i = 0; i < 40; i++) {
        mvprintw((terminal_window[0] / 2) - 6, ((terminal_window[1] / 2) - 20) + i, "=");
        mvprintw((terminal_window[0] / 2) + 6, ((terminal_window[1] / 2) - 20) + i, "=");
      }

      for (int i = 0; i <= 2; i++) {
        if (i == selectedOption) {
          if (i == 0) {
            mvprintw((terminal_window[0] / 2) - 2, (terminal_window[1] / 2) - 5, "=> Start <=\n");
          } else if (i == 1) {
            mvprintw((terminal_window[0] / 2) + 1, ((terminal_window[1] / 2) - 5), "=> Load <=");
          } else {
            mvprintw((terminal_window[0] / 2) + 4, (terminal_window[1] / 2) - 5, "=> Quit <=\n");
          }
        } else {
          if (i == 0) {
            mvprintw((terminal_window[0] / 2) - 2, (terminal_window[1] / 2) - 5, "   Start\n");
          } else if (i == 1) {
            mvprintw((terminal_window[0] / 2) + 1, ((terminal_window[1] / 2)) - 5, "   Load\n");
          } else {
            mvprintw((terminal_window[0] / 2) + 4, (terminal_window[1] / 2) - 5, "   Quit\n");
          }
        }
      }

      refresh(); // Refresh the screen

      ch = getch(); // Get user input

      switch (ch) {
      case KEY_UP:
        if (selectedOption > 0) {
          selectedOption--;
        }
        break;
      case KEY_DOWN:
        if (selectedOption < 2) {
          selectedOption++;
        }
        break;
      case 10: // ASCII code for Enter
        clear();
        if (selectedOption == 0) {
          return 1;
        } else if (selectedOption == 1) {
            printw("Loading Menu");
            return 0;
        } else {
            endwin();
            exit(0);
        }
      }
    }
}

// Declare logger globally
Logger logger;

void mainGameLoop() {
  clear(); refresh();

  // All initialisation might go into initialise() function later

  // Initialise Logger
  #ifdef DEBUG
  logger = Logger(true);
  #else
  logger = Logger(false);
  #endif

  // Initialise rooms
  Room room1("Room 1");
  Room room2("Room 2");
  Room room3("Room 3");

  // Initialise bosses
  Boss* boss1 = new Boss("geoff", 20, 10, 10, "NOOOOOO!");
  Boss* boss2 = new Boss("frank", 100, 10, 5, "you will not get away with this!");

  // Initialise items
  Item* item1 = new Item("Wooden sword", 10, 0, 0, 0);

  // Place bosses and items in rooms
  room1.addBoss(boss1);
  room2.addItem(item1);
  room3.addBoss(boss2);

  // Declare player (might be referenced from characterSelection() later on)
  Player steve("Steve", 20, 20, 10, 0);
  
  // Begin story
  room1.enterRoom(steve);
  sleep(1);
  room2.enterRoom(steve);

  std::cout << "players base damage is " << steve.getBaseDamage() << std::endl;
  std::cout << "players total damage is " << steve.getTotalDamage() << std::endl;
  std::cout << "\n";
}

void startGame() {
  Character player;
  startupMessage();
  if (menu() == 1) {
    player = characterSelection();
  }

    printw("Character created!\n");
    printw("Name: %s\n", player.name.c_str());
    printw("Type: %s\n", player.type == WIZARD ? "Wizard" : (player.type == WARRIOR ? "Warrior" : "Monk"));
    printw("Health: %d\n", player.health);
    printw("Strength: %d\n", player.strength);
    printw("Special Attribute: %d\n", player.specialAttribute);
    refresh();

    getch();
  mainGameLoop();
}

int main(void) {
  startGame();

  return 0;
}
