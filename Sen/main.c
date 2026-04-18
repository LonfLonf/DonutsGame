#include "raylib.h"
#include <stdlib.h>
#include <math.h>
#include "donut.h"

int main()
{
	int width = 600;
	int height = 450;
	InitWindow(width, height, "Donuts");

	Vector2 center = GetCenter(width, height);

	// Donut Stuff
	float DonutScale = 4.0f;
	Donut_T* pDonut = CreateDonut(center);
	Vector2 spawnPos = GetCenterOfDonut(center, pDonut, DonutScale);
	pDonut->position = spawnPos;

	// Hearts Donut Stuff
	Texture2D HeartTexture = LoadTexture("sprites/Heart.png");
	Vector2 heartPos[] = { { 10.0f, 10.0f }, { 50.0f, 10.0f } };
	int hearts;
	float HeartScale = 2.0f;

	// Bullet Stuff
	float BulletScale = 2.0f;
	Texture2D BulletTexture = LoadTexture("sprites/Shot.png");

	SetTargetFPS(60); 
	while (!WindowShouldClose())
	{
		hearts = GetHearts(pDonut->life);

		if (IsKeyDown(KEY_W) && IsInsideOfMap((Vector2) { pDonut->position.x , pDonut->position.y - pDonut->speed }, 
			(Vector2) { width, height }, pDonut->texture.width * DonutScale, pDonut->texture.height * DonutScale))
		{
			pDonut->position.y -= pDonut->speed;
		}

		if (IsKeyDown(KEY_S) && IsInsideOfMap((Vector2) { pDonut->position.x , pDonut->position.y + pDonut->speed }, 
			(Vector2) { width, height }, pDonut->texture.width * DonutScale, pDonut->texture.height * DonutScale))
		{
			pDonut->position.y += pDonut->speed;
		}

		if (IsKeyDown(KEY_A) && IsInsideOfMap((Vector2) { pDonut->position.x - pDonut->speed, pDonut->position.y },
			(Vector2) { width, height}, pDonut->texture.width * DonutScale, pDonut->texture.height * DonutScale))
		{
			pDonut->position.x -= pDonut->speed;
		}

		if (IsKeyDown(KEY_D) && IsInsideOfMap((Vector2) { pDonut->position.x + pDonut->speed, pDonut->position.y },
			(Vector2) { width, height }, pDonut->texture.width * DonutScale, pDonut->texture.height * DonutScale))
		{
			pDonut->position.x += pDonut->speed;
		}

		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
			Vector2 mousePos = GetMousePosition();
			FireBullet((Vector2) {pDonut->position.x + 5, pDonut->position.y + 10}, mousePos);
		}
		
		BeginDrawing();
			ClearBackground(GRAY);

			for (int i = 0; i < MAX_BULLETS; i++)
			{
				if (bullets[i].active)
				{
					UpdateBullet(i);
					DrawTextureEx(BulletTexture, bullets[i].position, 0.0f, BulletScale, WHITE);
				}
			}

			DrawTextureEx(pDonut->texture, pDonut->position, 0.0f, DonutScale, WHITE);

			for (int i = 0; i < hearts; i++)
			{
				DrawTextureEx(HeartTexture, heartPos[i], 0.0f, HeartScale, WHITE);
			}

			DrawText(TextFormat("Position Donut: %.1f - %.1f", pDonut->position.x , pDonut->position.y), 10, 50, 20, GREEN);
		EndDrawing();
	}

	DestroyDonut(pDonut);
	UnloadTexture(BulletTexture);

	CloseWindow();
	return 0;
}