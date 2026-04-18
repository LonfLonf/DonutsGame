#include "graphic.h"

#define MAX_BOMBS 15

typedef struct Bomb
{
	int damage;
	int life;
	Vector2 position;
	Vector2 delta;
	bool active;
};