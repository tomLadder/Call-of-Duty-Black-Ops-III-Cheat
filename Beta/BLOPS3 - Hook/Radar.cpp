#include "Radar.h"

void Radar::Init(float _x, float _y, float _width, float _height)
{
	this->x = _x;
	this->y = _y;
	this->width = _width;
	this->height = _height;
}

void Radar::DrawBackGround(Rendering rendering)
{
	rendering.DrawField(this->x, this->y, this->width, this->height, this->backGroundColor);
	rendering.DrawBox(this->x, this->y, this->width, this->height, this->backGroundLineColor);

	rendering.DrawField(this->x + this->width / 2 - 1, this->y + this->height/6, 2, this->height - (2*this->height/6), this->backGroundLineColor);
	rendering.DrawField(this->x + this->width / 6, this->y + this->height / 2 - 1, this->width - (2 * this->height / 6), 2, this->backGroundLineColor);
}

vec2_t Radar::CalcPosition(entity_t* entity)
{
	vec2_t vec;
	float cy = (float)cos(entities[cg->iClientNum].fYaw / 180 * 3.1415926535);
	float sy = (float)sin(entities[cg->iClientNum].fYaw / 180 * 3.1415926535);

	float dx = entity->vecOrigin.x - entities[cg->iClientNum].vecOrigin.x;
	float dy = entity->vecOrigin.y - entities[cg->iClientNum].vecOrigin.y;

	vec.x = (((dy * cy - dx * sy)) / 22) * -1;
	vec.y = (((dx * cy + dy * sy)) / 22) * -1;

	return vec;
}

void Radar::Draw(float* colorEnemy, float* colorFriendly, bool enemyOnly, Rendering rendering)
{
	DrawBackGround(rendering);

	clientinfo_t* myClient = CODEngine::GetClientInfo(cg->iClientNum);

	if (myClient != nullptr)
	{
		for (int i = 0;i < 12;i++)
		{
			if (i != cg->iClientNum && entities[i].isAlive())
			{
				clientinfo_t* client = CODEngine::GetClientInfo(i);
				if (client != nullptr)
				{
					vec2_t vec = this->CalcPosition(&entities[i]);
					vec.x = vec.x - 4 + this->width / 2;
					vec.y = vec.y + this->height / 2 - 4;
					if (vec.x >= 4 && vec.x <= this->width - 4 && vec.y >= 4 && vec.y <= this->height - 4)
					{
						if (!enemyOnly && client->iTeam == myClient->iTeam)
						{
							rendering.DrawField(this->x + vec.x, this-> y + vec.y, 8, 8, colorFriendly);
						}
						else
						{
							rendering.DrawField(this->x + vec.x, this->y + vec.y, 8, 8, colorEnemy);
						}
					}
				}
			}
		}
	}
}