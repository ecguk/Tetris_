#include "game.h"
#include "console.h"
#include <cstdlib>
#include <ctime>
using namespace std;
Game::Game() {
    private:
        bool board_[BOARD_WIDTH][BOARD_HEIGHT]; // 게임 보드

        Tetromino currentTetromino_; // 현재 떨어지고 있는 테트로미노
        int tetrominoX_; // 현재 테트로미노의 x 위치
        int tetrominoY_; // 현재 테트로미노의 y 위치
    public:
    // 생성자
    Game();

    // 한 프레임마다 게임 상태를 업데이트하는 함수
    void update();

    // 게임 화면을 그리는 함수
    void draw();

    // 게임 종료 조건을 확인하는 함수
    bool shouldExit();

    // 현재 테트로미노를 게임 보드에 고정시키는 함수
    void placeTetromino(const Tetromino& tetromino, int x, int y);

    // 테트로미노가 다음 위치로 이동할 때 충돌을 검사하는 함수
    bool checkCollision(const Tetromino& tetromino, int x, int y);
    // 게임 보드 초기화
    for (int i = 0; i < BOARD_WIDTH; ++i) {
        for (int j = 0; j < BOARD_HEIGHT; ++j) {
            board_[i][j] = false;
        }
    }

    // 첫 번째 테트로미노 생성
    tetrominoX_ = BOARD_WIDTH / 2;
    tetrominoY_ = 0;
    currentTetromino_ = Tetromino::getRandomTetromino();
}

void Game::update() {
   if (!checkCollision(currentTetromino_, tetrominoX_, tetrominoY_ + 1)) {
        // 충돌하지 않으면 테트로미노를 한 칸 아래로 이동시킨다.
        ++tetrominoY_;
    } else {
        // 충돌하면 테트로미노를 고정시킨다.
        placeTetromino(currentTetromino_, tetrominoX_, tetrominoY_);
        // 새로운 테트로미노 생성
        tetrominoX_ = BOARD_WIDTH / 2;
        tetrominoY_ = 0;
        currentTetromino_ = Tetromino::getRandomTetromino();
        // 게임 종료 조건 확인
        if (tetrominoY_ == 0) {
            // 게임 종료
            console::log("Game Over!");
            return;
        }
    }
}

void Game::draw() {
    console::clear();

    // 게임 보드 그리기
    for (int i = 0; i < BOARD_HEIGHT; ++i) {
        for (int j = 0; j < BOARD_WIDTH; ++j) {
            if (board_[j][i]) {
                console::draw(j, i, "■");
            }
        }
    }

    // 현재 테트로미노 그리기
    for (int i = 0; i < currentTetromino_.size(); ++i) {
        for (int j = 0; j < currentTetromino_.size(); ++j) {
            if (currentTetromino_.shape()[i][j]) {
                console::draw(tetrominoX_ + j, tetrominoY_ + i, "■");
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
    srand(static_cast<unsigned int>(time(nullptr))); // 랜덤 시드 초기화

    console::init();

    Game game;

    while (!game.shouldExit()) {
        game.update();
        game.draw();
    }

    return 0;
}