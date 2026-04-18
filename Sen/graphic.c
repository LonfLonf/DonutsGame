#include "graphic.h"
#include <stdio.h>
#include <math.h>

Vector2 GetCenter(int width, int height)
{
	return (Vector2) { width / 2.0f, height / 2.0f };
}

bool IsInsideOfMap(Vector2 destPosition, Vector2 screen, float width, float height)
{
	if (destPosition.x < 0 || destPosition.y < 0 || (destPosition.x + width) > screen.x || (destPosition.y + height) > screen.y)
	{
		return false;
	}
	return true;
}

Vector2 GetDelta(Vector2 donutPos, Vector2 mousePos, float speed)
{
	Vector2 delta = Vector2Subtract(mousePos, donutPos);

	float angle = atan2(delta.y, delta.x);

	return (Vector2) { cos(angle)* speed, sin(angle)* speed };
}