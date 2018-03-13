#include "Radar.h"

Radar* Radar::_radar = 0;

Radar* Radar::Instance() {
	if (_radar == nullptr) {
		_radar = new Radar;
	}

	return _radar;
}

void Radar::Init(float _x, float _y, float _width, float _height) {
	this->x = _x;
	this->y = _y;
	this->width = _width;
	this->height = _height;
}

void Radar::DrawBackGround() {
	Rendering::Instance()->DrawField(this->x, this->y, this->width, this->height, this->backGroundColor);
	Rendering::Instance()->DrawBox(this->x, this->y, this->width, this->height, this->backGroundLineColor);

	Rendering::Instance()->DrawField(this->x + this->width / 2 - 1, this->y + this->height/6, 2, this->height - (2*this->height/6), this->backGroundLineColor);
	Rendering::Instance()->DrawField(this->x + this->width / 6, this->y + this->height / 2 - 1, this->width - (2 * this->height / 6), 2, this->backGroundLineColor);
}

vec2_t Radar::CalcPosition(entity_t* entity) {
	entity_t* myEntity = CODEngine::GetEntity(CODEngine::GetCGT()->iClientNum);
	vec2_t vec;
	float cy = (float)cos(myEntity->Yaw / 180 * 3.1415926535);
	float sy = (float)sin(myEntity->Yaw / 180 * 3.1415926535);

	float dx = entity->vOrigin.x - myEntity->vOrigin.x;
	float dy = entity->vOrigin.y - myEntity->vOrigin.y;

	vec.x = (((dy * cy - dx * sy)) / 22) * -1;
	vec.y = (((dx * cy + dy * sy)) / 22) * -1;

	return vec;
}

void Radar::Draw(float* colorEnemy, float* colorFriendly, bool enemyOnly) {
	DrawBackGround();
	cg_t* cg = CODEngine::GetCGT();
	clientinfo_t* myClient = CODEngine::GetClientInfo(cg->iClientNum);

	if (myClient != nullptr)
	{
		for (int i = 0;i < 12;i++)
		{
			if (i != cg->iClientNum && CODEngine::GetEntity(i)->isAlive())
			{
				clientinfo_t* client = CODEngine::GetClientInfo(i);
				if (client != nullptr)
				{
					vec2_t vec = this->CalcPosition(CODEngine::GetEntity(i));
					vec.x = vec.x - 4 + this->width / 2;
					vec.y = vec.y + this->height / 2 - 4;

					//Clamp
					if (vec.x <= 4)
						vec.x = 4;

					if (vec.x >= this->width - 4)
						vec.x = this->width - 12;

					if (vec.y <= 4)
						vec.y = 4;

					if (vec.y >= this->height - 4)
						vec.y = this->height - 16;

					if (vec.x >= 4 && vec.x <= this->width - 4 && vec.y >= 4 && vec.y <= this->height - 4)
					{
						if (!enemyOnly && client->iTeam == myClient->iTeam)
						{
							Rendering::Instance()->DrawField(this->x + vec.x, this-> y + vec.y, 8, 8, colorFriendly);
						}
						else
						{
							Rendering::Instance()->DrawField(this->x + vec.x, this->y + vec.y, 8, 8, colorEnemy);
						}
					}
				}
			}
		}
	}
}