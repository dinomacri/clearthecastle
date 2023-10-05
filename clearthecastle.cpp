#include <iostream>
// TODO: Add required file includes here

void startupMessage() {
  // TODO: Will enter ASCII art here
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
  characterSelection();
  mainGameLoop();
}

void main() {
  startGame();

  return 0;
}
