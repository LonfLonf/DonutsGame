#pragma once
#include "graphic.h"

typedef struct Donut
{
	int life;
	int speed;
	Vector2 position;
	Texture2D texture;
}Donut_T;

typedef struct Bullet {
    int damage;
    Vector2 delta;
    Vector2 position;
    bool active;
} Bullet_T;

#define MAX_BULLETS 100
extern Bullet_T bullets[MAX_BULLETS];

Donut_T* CreateDonut(Vector2 startPos);
void DestroyDonut(Donut_T* pDonut);
Vector2 GetCenterOfDonut(Vector2 center, Donut_T* pDonut, float scale);
void FireBullet(Vector2 donutPos, Vector2 mousePos);
void UpdateBullet(int index);
int GetHearts(int life);