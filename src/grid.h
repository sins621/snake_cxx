#include "raylib.h"
#include <vector>

class Grid {
public:
  std::vector<std::vector<int>> grid = {{}, {}};
  void update() {
    for (std::size_t i{0}; i < grid[0].size() - 1; i++) {
      std::size_t posX = grid[0][i];
      std::size_t posY_start = grid[1][0];
      std::size_t posY_end = grid[1][grid[1].size() - 1];
      DrawLine(posX, posY_start, posX, posY_end, WHITE);
    }

    for (std::size_t j{0}; j < grid[1].size() - 1; j++) {
      std::size_t posY = grid[1][j];
      std::size_t posX_start = grid[0][0];
      std::size_t posX_end = grid[0][grid[0].size() - 1];
      DrawLine(posX_start, posY, posX_end, posY, WHITE);
    }
  }
};
