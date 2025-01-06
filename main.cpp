#include "raylib.h"
#include "raymath.h"
#include <iostream>
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

void DrawGrid(std::vector<std::vector<int>> grid) {

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

void AddSegment(std::vector<Vector2> &segs) {
  Vector2 new_seg = segs.at(segs.size() - 1);
  segs.push_back(new_seg);
}

int main() {

  SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);

  InitWindow(640, 480, "Snake");
  SetTargetFPS(120);

  Timer move_timer{};
  Vector2 direction{0, 0};
  Vector2 size{40, 40};
  Vector2 grid_min{0, 0};
  Vector2 grid_max{680, 520};

  std::vector<std::vector<int>> grid = {{}, {}};
  std::vector<Vector2> snake;
  std::vector<Vector2> starting_pos = {{200, 200}, {240, 200}, {280, 200}};

  for (auto position : starting_pos) {
    Vector2 pos = position;
    snake.push_back(pos);
  }

  for (std::size_t i = 0; i < 680; i += 40) {
    grid[0].push_back(i);
  }

  for (std::size_t i = 0; i < 520; i += 40) {
    grid[1].push_back(i);
  }

  while (!WindowShouldClose()) {
    if (IsKeyDown(KEY_W)) {
      direction = {0, -1};
    }
    if (IsKeyDown(KEY_S)) {
      direction = {0, 1};
    }
    if (IsKeyDown(KEY_A)) {
      direction = {-1, 0};
    }
    if (IsKeyDown(KEY_D)) {
      direction = {1, 0};
    }
    if (IsKeyPressed(KEY_E)) {
      AddSegment(snake);
    }

    ClearBackground(BLACK);
    BeginDrawing();

    UpdateTimer(&move_timer);
    if (TimerDone(&move_timer)) {
      for (int i{1}; i < snake.size(); i++) {
        snake.at(i) = snake.at(i - 1);
      }
      snake.at(0) = Vector2Add(snake.at(0), Vector2Scale(direction, 40));
      StartTimer(&move_timer, 0.5f);
    }

    for (auto segment : snake) {
      /*segment = Vector2Clamp(segment, grid_min, grid_max);*/
      DrawRectangleV(segment, size, WHITE);
    }

    DrawGrid(grid);

    EndDrawing();
  }

  CloseWindow();
  return 0;
}
