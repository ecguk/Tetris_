#include "console.h"

#define BOARD_SIZE 10
#define MOVE_DELAY 15
#define WALL_VERTICAL_STRING "¦­"
#define WALL_HORIZONTAL_STRING "¦¬"
#define WALL_RIGHT_TOP_STRING "¦¯"
#define WALL_LEFT_TOP_STRING "¦®"
#define WALL_RIGHT_BOTTOM_STRING "¦°"
#define WALL_LEFT_BOTTOM_STRING "¦±"
#define SNAKE_STRING "¡á"
#define SNAKE_BODY_STRING "¡á"
#define APPLE_STRING "¡Ü"

int x = 0;
int y = 0;

void handleInput() {
  if (console::key(console::K_LEFT)) {
    x--;
  }
  if (console::key(console::K_RIGHT)) {
    x++;
  }
  if (console::key(console::K_UP)) {
    y--;
  }
  if (console::key(console::K_DOWN)) {
    y++;
  }
}

void restrictInScreen() {
 
  if (x < 0)
    x = 0;
  if (x >= console::SCREEN_WIDTH)
    x = console::SCREEN_WIDTH - 1;
  if (y < 0)
    y = 0;
  if (y >= console::SCREEN_HEIGHT)
    y = console::SCREEN_HEIGHT - 1;
}

void drawStar() {

  console::draw(x, y, "*");
}

void game() {

  console::init();

  while (true) {

    console::clear();

    handleInput();
    restrictInScreen();
    drawStar();

    console::wait();
  }
}

int main() { game(); }