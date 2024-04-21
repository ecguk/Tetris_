
#ifndef GAME_H
#define GAME_H

#include "tetromino.h"

#define BOARD_WIDTH 10
#define BOARD_HEIGHT 20
#define LINES 40

#define DROP_DELAY 60

class Game {
private:
  // ���� ���� ��Ÿ���� �迭
  // board[x][y]�� true �� ��� x, y ��ġ�� ������ ����� �����ϴ� ���� �ǹ��Ѵ�
  bool board_[BOARD_WIDTH][BOARD_HEIGHT];

public:
  // ������ �� �������� ó���Ѵ�.
  void update();

  // ���� ȭ���� �׸���.
  void draw();

  // ���� ������ ����Ǿ�� �ϴ��� ���θ� ��ȯ�Ѵ�.
  bool shouldExit();

  Game();
};
#endif