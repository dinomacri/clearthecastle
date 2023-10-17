#include <iostream>

// UI files
//    - For linux: apt install libncurses5-dev 
//    - compile with -lncurses 
#include <sys/ioctl.h>
#include <unistd.h>
#include <curses.h>
#include <fstream>

#include "Boss.h"
#include "Player.h"
#include "Mob.h"
#include "Item.h"
#include "Entity.h"
#include "Room.h"
#include "Logger.h"

// Declare logger globally
Logger logger;

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

// returns:
// 0: Load Character
// 1: Create Character
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
            logger.print_debug("Loading menu");
            return 0;
        } else {
            endwin();
            exit(0);
        }
      }
    }
}


Player characterSelection() {
    // enum CharacterType { WIZARD, WARRIOR, MONK };

    // Set total base attributes
    int totalBaseAttributes = 30;
    std::string characterFile = "player.txt";

    struct Character {
        std::string name="HELLO";
        // CharacterType type;
        int health=0;
        int damage=0;
        int armour=0;
      
    };
    Character newCharacter;

    Player player;
    // player selects Load
    if (menu() == 0) {
        logger.print("Loading from file\n");

        std::ifstream input(characterFile);
        if (!input.is_open()) {
          logger.print_error("Error opening " + characterFile);
          exit(1);
        }

        std::string line1, line2, line3, line4, line5;

        while(input >> line1 >> line2 >> line3 >> line4)
        {
            if ((std::stoi(line2) + std::stoi(line3) + std::stoi(line4)) > totalBaseAttributes )
            {
                logger.print_error("The total attributes in " + characterFile + " exceed " + std::to_string(totalBaseAttributes) + ". Ensure total attributes add up to 30.");

            }

            newCharacter.name = line1;
            newCharacter.health = std::stoi(line2);
            newCharacter.damage = std::stoi(line3);
            newCharacter.armour = std::stoi(line4);
            
        }

        input.close();
    }
    // player selects New
    else {
        clear();
        refresh();

        char name[100];
        int nameIndex = 0;
        int ch;
        int *terminal_window = getTerminalSize();

        while (1) {
          mvprintw((terminal_window[0]) / 2, (terminal_window[1] / 2) - 12, "Enter characters name: ");
          ch = getch();

          if (ch == '\n' || ch == '\r') {
              if (nameIndex == 0)
              {
                continue;
              }
              else
              {
                break; // Exit the loop on Enter key
              }
          } else if (ch == 127 && nameIndex > 0) {
              // Handle backspace (ASCII 127) to delete the last character
              nameIndex--;
              name[nameIndex] = '\0';
          } else if (nameIndex < 99) {
              name[nameIndex] = ch;
              nameIndex++;
              name[nameIndex] = '\0';
          }

          clear();
          mvprintw((terminal_window[0]) / 2, (terminal_window[1] / 2) + 11, name);
          refresh();
        }
        newCharacter.name = std::string(name);

       
        
        clear();
        refresh();

        int pointsRemaining = totalBaseAttributes;
        while (pointsRemaining > 0) {
            clear();

            for (int i = 0; i < 40; i++)
            {
              mvprintw((terminal_window[0] / 2) - 3, ((terminal_window[1] / 2) - 20) + i, "=");
              mvprintw((terminal_window[0] / 2) + 1, ((terminal_window[1] / 2) - 20) + i, "=");
            }

            mvprintw((terminal_window[0] / 2) - 4, (terminal_window[1] / 2) - 10, "Points remaining: %d\n", pointsRemaining);
            mvprintw((terminal_window[0] / 2) - 2, (terminal_window[1] / 2) - 7, "1. Health: %d\n", newCharacter.health);
            mvprintw((terminal_window[0] / 2) - 1, (terminal_window[1] / 2) - 7, "2. Damage: %d\n", newCharacter.damage);
            mvprintw((terminal_window[0] / 2), (terminal_window[1] / 2) - 7, "3. Armour: %d\n", newCharacter.armour);
            refresh();
         
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
                    attributeToUpdate = &newCharacter.health;
                    break;
                case 2:
                    attributeToUpdate = &newCharacter.damage;
                    break;
                case 3:
                    attributeToUpdate = &newCharacter.armour;
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

        // Save new character to file
        logger.print("Writing to file\n");

        std::ofstream output("player.txt");
        if (!output.is_open()) {
          logger.print_error("Error opening file\n");
        }

        output << newCharacter.name << "\n";
        output << newCharacter.health << "\n";
        output << newCharacter.damage << "\n";
        output << newCharacter.armour << "\n";

        output.close();

        logger.print_debug("Data written to file.\n");
    }
        player = Player(newCharacter.name, newCharacter.health, newCharacter.damage, newCharacter.armour);

        printw("Character created!\n");
        printw("Name: %s\n", player.getName().c_str());
        // printw("Type: %s\n", player.type == WIZARD ? "Wizard" : (player.type == WARRIOR ? "Warrior" : "Monk"));
        printw("Health: %d\n", player.getCurrentHealth());
        printw("Damage: %d\n", player.getCurrentDamage());
        printw("Armour: %d\n", player.getCurrentArmour());
        
        refresh();

        getch();

        return player;
}


void mainGameLoop(Player* player) {
  // All initialisation might go into initialise() function later

  // Initialise rooms
  Room room1("Room 1");
  Room room2("Room 2");
  Room room3("Room 3");

  // Initialise bosses
  Boss* boss1 = new Boss("geoff", 20, 3, 5, "NOOOOOO!");
  Boss* boss2 = new Boss("frank", 30, 9, 10, "frank screams, you will not get away with this! With his last breath\nYou have defeated the bosses that have roamed the castles walls for years. Your achievements will be remembered for generations\n");

  // Initialise items
  Item* item1 = new Item("Wooden sword", 10, 0, 0);

  // Place bosses and items in rooms
  room1.addBoss(boss1);
  room2.addItem(item1);
  room3.addBoss(boss2);
  
  // Begin story
  room1.enterRoom(*player);
  sleep(2);
  room2.enterRoom(*player);
  sleep(2);
  room3.enterRoom(*player);

 

  
}

int main(void) {

    #ifdef DEBUG
    logger = Logger(true);
    #else
    logger = Logger(false);
    #endif

  startupMessage();
  Player player;
  player = characterSelection();
  endwin();
  mainGameLoop(&player);

  return 0;
}
