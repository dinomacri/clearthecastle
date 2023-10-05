#include <iostream>

// UI files
#include <sys/ioctl.h>
#include <unistd.h>
#include <curses.h>

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
  for (int i = 0; i < sizeof(title) / sizeof(title[0]); i++) {
      mvprintw(i,(terminal_window[1]/2)-(47/2),title[i]);
  }
  // Text 1
  attron(COLOR_PAIR(3));
  mvprintw(13, (terminal_window[1]/2)-(24)/2, "By Dino, Darcy, and Will");
    
  // Sword
  attron(COLOR_PAIR(2));
  for (int i = 0; i < sizeof(sword) / sizeof(sword[0]); i++) {
      mvprintw(12+i,(terminal_window[1]/2)-(76/2),sword[i]);
  }

  // Text 2
  attron(COLOR_PAIR(2)); // Change text colour to white
  mvprintw(terminal_window[0]-3, (terminal_window[1]/2)-14, "[ Press any key to continue ]");

  /* WAITING FOR KEY STROKE TO FINISH */
  refresh(); getch();
  return;
}

void menuSelection() {
  clear();
}

void characterSelection() {
  // TODO: Enter character selection screen UI elements here
}

void mainGameLoop() {
  // TODO: Enter main game logic/elements here, including battle, inventory, map etc.
  // Could require more functions like renderMap() or a changeView() function etc.
}

void startGame() {
  startupMessage();
  menuSelection();
  characterSelection();
  mainGameLoop();
}

int main(void) {
  startGame();

  return 0;
}