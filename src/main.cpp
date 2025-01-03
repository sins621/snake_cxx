#include "grid.h"
#include "raylib.h"
#include "square.h"
#include <vector>

int main() {

  SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);

  InitWindow(640, 480, "Snake");
  SetTargetFPS(10);

  std::vector<std::vector<int>> grid = {{}, {}};
  for (std::size_t i = 0; i < 680; i += 40) {
    grid[0].push_back(i);
  }

  for (std::size_t i = 0; i < 520; i += 40) {
    grid[1].push_back(i);
  }

  Square square;
  square.grid = grid;

  Grid draw_grid;
	draw_grid.grid = grid;

  while (!WindowShouldClose()) {
    ClearBackground(BLACK);

    if (IsKeyDown(KEY_D))
      square.posX += 1;
    if (IsKeyDown(KEY_A))
      square.posX -= 1;
    if (IsKeyDown(KEY_W))
      square.posY += -1;
    if (IsKeyDown(KEY_S))
      square.posY += 1;

    BeginDrawing();
    square.update();
		draw_grid.update();
    EndDrawing();
  }

  CloseWindow();
  return 0;
}
