#include "raylib.h"
#include <iostream>
#include <vector>

class Square {
public:
  std::vector<int> pos{0, 0};
  std::vector<std::vector<int>> grid = {{}, {}};

  int speed{1};
  int size{40};
  int posX{0};
  int posY{0};

  void update() {
    move();
    DrawRectangle(pos[0], pos[1], size, size, WHITE);
  }

  void move() { pos = {grid[0][posX], grid[1][posY]}; }
};
