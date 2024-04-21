#include "game.h"
#include "console.h"
#include <cstdlib>
#include <ctime>
using namespace std;
Game::Game() {
    private:
        bool board_[BOARD_WIDTH][BOARD_HEIGHT]; // ���� ����

        Tetromino currentTetromino_; // ���� �������� �ִ� ��Ʈ�ι̳�
        int tetrominoX_; // ���� ��Ʈ�ι̳��� x ��ġ
        int tetrominoY_; // ���� ��Ʈ�ι̳��� y ��ġ
    public:
    // ������
    Game();

    // �� �����Ӹ��� ���� ���¸� ������Ʈ�ϴ� �Լ�
    void update();

    // ���� ȭ���� �׸��� �Լ�
    void draw();

    // ���� ���� ������ Ȯ���ϴ� �Լ�
    bool shouldExit();

    // ���� ��Ʈ�ι̳븦 ���� ���忡 ������Ű�� �Լ�
    void placeTetromino(const Tetromino& tetromino, int x, int y);

    // ��Ʈ�ι̳밡 ���� ��ġ�� �̵��� �� �浹�� �˻��ϴ� �Լ�
    bool checkCollision(const Tetromino& tetromino, int x, int y);
    // ���� ���� �ʱ�ȭ
    for (int i = 0; i < BOARD_WIDTH; ++i) {
        for (int j = 0; j < BOARD_HEIGHT; ++j) {
            board_[i][j] = false;
        }
    }

    // ù ��° ��Ʈ�ι̳� ����
    tetrominoX_ = BOARD_WIDTH / 2;
    tetrominoY_ = 0;
    currentTetromino_ = Tetromino::getRandomTetromino();
}

void Game::update() {
   if (!checkCollision(currentTetromino_, tetrominoX_, tetrominoY_ + 1)) {
        // �浹���� ������ ��Ʈ�ι̳븦 �� ĭ �Ʒ��� �̵���Ų��.
        ++tetrominoY_;
    } else {
        // �浹�ϸ� ��Ʈ�ι̳븦 ������Ų��.
        placeTetromino(currentTetromino_, tetrominoX_, tetrominoY_);
        // ���ο� ��Ʈ�ι̳� ����
        tetrominoX_ = BOARD_WIDTH / 2;
        tetrominoY_ = 0;
        currentTetromino_ = Tetromino::getRandomTetromino();
        // ���� ���� ���� Ȯ��
        if (tetrominoY_ == 0) {
            // ���� ����
            console::log("Game Over!");
            return;
        }
    }
}

void Game::draw() {
    console::clear();

    // ���� ���� �׸���
    for (int i = 0; i < BOARD_HEIGHT; ++i) {
        for (int j = 0; j < BOARD_WIDTH; ++j) {
            if (board_[j][i]) {
                console::draw(j, i, "��");
            }
        }
    }

    // ���� ��Ʈ�ι̳� �׸���
    for (int i = 0; i < currentTetromino_.size(); ++i) {
        for (int j = 0; j < currentTetromino_.size(); ++j) {
            if (currentTetromino_.shape()[i][j]) {
                console::draw(tetrominoX_ + j, tetrominoY_ + i, "��");
            }
        }
    }

    console::wait();
}

bool Game::shouldExit() {
  
    return console::key(console::K_ESC);
}
void Game::placeTetromino(const Tetromino& tetromino, int x, int y) {
    for (int i = 0; i < tetromino.size(); ++i) {
        for (int j = 0; j < tetromino.size(); ++j) {
            if (tetromino.shape()[i][j]) {
                board_[x + j][y + i] = true;
            }
        }
    }
}

bool Game::checkCollision(const Tetromino& tetromino, int x, int y) {
    for (int i = 0; i < tetromino.size(); ++i) {
        for (int j = 0; j < tetromino.size(); ++j) {
            if (tetromino.shape()[i][j]) {
                if (x + j < 0 || x + j >= BOARD_WIDTH || y + i >= BOARD_HEIGHT || board_[x + j][y + i]) {
                    return true;
                }
            }
        }
    }
    return false;
}

int main() {
    srand(static_cast<unsigned int>(time(nullptr))); // ���� �õ� �ʱ�ȭ

    console::init();

    Game game;

    while (!game.shouldExit()) {
        game.update();
        game.draw();
    }

    return 0;
}