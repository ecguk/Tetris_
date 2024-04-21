#ifndef TETROMINO_H
#define TETROMINO_H

#include <string>

#define SHADOW_STRING "?"
#define BLOCK_STRING "бс"

class Tetromino {
  static const int MAX_SIZE = 4;

 
  std::string name_;

 
  bool shape_[MAX_SIZE][MAX_SIZE];

  
  Tetromino *original_;

 
  int size_;

public:
 
  Tetromino(std::string name, int size, std::string shape);

 
  std::string name() { return name_; }

  
  int size() { return size_; }

  
  Tetromino *original() { return original_; }

  
  Tetromino rotatedCW();

  
  Tetromino rotatedCCW();

  
  void drawAt(std::string s, int x, int y);

  
  bool check(int x, int y) { return shape_[x][y]; }


  static Tetromino I, O, T, S, Z, J, L;
};

#endif