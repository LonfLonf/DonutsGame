#include "donut.h"
#include <stdio.h>

Bullet_T bullets[MAX_BULLETS] = { 0 };
unsigned int SpeedBullet = 2;

Donut_T* CreateDonut(Vector2 startPos)
{
	Donut_T* pDonut = (Donut_T*)malloc(sizeof(Donut_T));
	
	if (pDonut == NULL)
	{
		return NULL;
	}

	pDonut->life = 100;
	pDonut->speed = 2;
	pDonut->position = startPos;
	pDonut->texture = LoadTexture("sprites/Donut.png");

	return pDonut;
}

void DestroyDonut(Donut_T* pDonut)
{
	UnloadTexture(pDonut->texture);
	free(pDonut);
}

Vector2 GetCenterOfDonut(Vector2 center, Donut_T* pDonut, float scale)
{
	return (Vector2) { center.x - ((pDonut->texture.width * scale) / 2), center.y - ((pDonut->texture.width * scale) / 2)};
}

void FireBullet(Vector2 donutPos, Vector2 mousePos)
{
	for (int i = 0; i < MAX_BULLETS; i++)
	{
		if (!bullets[i].active)
		{
			bullets[i].active = true;
			bullets[i].position = donutPos;
			bullets[i].delta = GetDelta(donutPos, mousePos, 5);
			break;
		}
	}
}

void UpdateBullet(int i)
{
	bullets[i].position.x += bullets[i].delta.x;
	bullets[i].position.y += bullets[i].delta.y;

	if (bullets[i].position.x > GetScreenWidth() || bullets[i].position.y > GetScreenHeight())
	{
		bullets[i].active = false;
	}
}

int GetHearts(int life)
{
	return (life + 49) / 50;
}