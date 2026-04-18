#include "raylib.h"
#include "raymath.h"
#include <stdlib.h>

Vector2 GetCenter(int width, int height);
bool IsInsideOfMap(Vector2 destPosition, Vector2 screen, float width, float height);
Vector2 GetDelta(Vector2 donutPos, Vector2 mousePos, float speed);