#include "console/console.h"
#include "game.h"
#include <cstdlib>
#include <ctime>

int main() {
  srand((unsigned int)time(nullptr));
  console::init();

  Game game;

  while (!game.shouldExit()) {
    console::clear();

    game.update();
    game.draw();


    console::wait();
  }
}