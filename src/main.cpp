#include "raylib.h"
#include <stdio.h>
#include <vector>

typedef struct {
  float Lifetime;
} Timer;

void StartTimer(Timer *timer, float lifetime) {
  if (timer != NULL)
    timer->Lifetime = lifetime;
}

void UpdateTimer(Timer *timer) {
  if (timer != NULL && timer->Lifetime > 0)
    timer->Lifetime -= GetFrameTime();
}

bool TimerDone(Timer *timer) {
  if (timer != NULL)
    return timer->Lifetime <= 0;

  return false;
}

int main() {

  SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);

  InitWindow(640, 480, "Snake");
  SetTargetFPS(120);

  Timer move_timer{};

  std::vector<std::vector<int>> grid = {{}, {}};
  for (std::size_t i = 0; i < 680; i += 40) {
    grid[0].push_back(i);
  }

  for (std::size_t i = 0; i < 520; i += 40) {
    grid[1].push_back(i);
  }

  while (!WindowShouldClose()) {
    if (IsKeyDown(KEY_W)) {
    }
    if (IsKeyDown(KEY_S)) {
    }
    if (IsKeyDown(KEY_A)) {
    }
    if (IsKeyDown(KEY_D)) {
    }

    ClearBackground(BLACK);
    BeginDrawing();

    UpdateTimer(&move_timer);
    if (TimerDone(&move_timer)) {
      StartTimer(&move_timer, 0.5f);
      printf("Tick");
    }

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

    EndDrawing();
  }

  CloseWindow();
  return 0;
}
