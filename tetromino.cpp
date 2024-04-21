#include "tetromino.h"
Tetromino Tetromino::I("I", 4, "0000111100000000");
Tetromino Tetromino::O("O", 2, "0011001100000000");
Tetromino Tetromino::T("T", 3, "0010111000000000");
Tetromino Tetromino::S("S", 3, "0001100110000000");
Tetromino Tetromino::Z("Z", 3, "0110011000000000");
Tetromino Tetromino::J("J", 3, "1001110000000000");
Tetromino Tetromino::L("L", 3, "0011101000000000");

Tetromino::Tetromino(std::string name, int size, std::string shape)
    : name_(name), size_(size), original_(this) {
    int index = 0;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            shape_[i][j] = (shape[index++] == '1');
        }
    }
}

Tetromino Tetromino::rotatedCW() {
    Tetromino rotated(name_, size_, "");
    for (int i = 0; i < size_; ++i) {
        for (int j = 0; j < size_; ++j) {
            rotated.shape_[j][size_ - 1 - i] = shape_[i][j];
        }
    }
    return rotated;
}

Tetromino Tetromino::rotatedCCW() {
    Tetromino rotated(name_, size_, "");
    for (int i = 0; i < size_; ++i) {
        for (int j = 0; j < size_; ++j) {
            rotated.shape_[size_ - 1 - j][i] = shape_[i][j];
        }
    }
    return rotated;
}

void Tetromino::drawAt(std::string s, int x, int y) {
    for (int i = 0; i < size_; ++i) {
        for (int j = 0; j < size_; ++j) {
            if (shape_[i][j]) {
                int index = (y + i) * 10 + (x + j);
                s[index] = BLOCK_STRING[0];
            }
        }
    }
}