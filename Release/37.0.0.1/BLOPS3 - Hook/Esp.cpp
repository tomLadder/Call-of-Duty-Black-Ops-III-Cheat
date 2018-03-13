#include "Esp.h"

__int64 j_helmet;
__int64 j_head;
__int64 j_neck;
__int64 j_shoulder_le;
__int64 j_elbow_le;
__int64 j_wrist_le;
__int64 j_shoulder_ri;
__int64 j_elbow_ri;
__int64 j_wrist_ri;
__int64 j_spineupper;
__int64 j_spinelower;
__int64 j_hip_le;
__int64 j_knee_le;
__int64 j_ankle_le;
__int64 j_hip_ri;
__int64 j_knee_ri;
__int64 j_ankle_ri;

Esp* Esp::_esp = 0;

Esp* Esp::Instance() {
	if (_esp == nullptr) {
		_esp = new Esp;
	}
	return _esp;

}

bool Esp:: WorldToScreen(vec3_t world, float *x, float *y) {
	vec3_t Position = world.VectorSubtract(refdef->vecOrigin);
	vec3_t Transform;

	// get our dot products from viewAxis
	Transform.x = Position.DotProduct(refdef->vecAxisY);
	Transform.y = Position.DotProduct(refdef->vecAxisZ);
	Transform.z = Position.DotProduct(refdef->vecAxisX);

	// make sure it is in front of us
	if (Transform.z < 0.1f)
		return false;

	// get the center of the screen
	vec2_t Center;
	Center.x = (float)(refdef->iWidth * 0.5f);
	Center.y = (float)(refdef->iHeight * 0.5f);

	*x = Center.x * (1 - (Transform.x / refdef->fFovX / Transform.z));
	*y = Center.y * (1 - (Transform.y / refdef->fFovY / Transform.z));
	return true;
}

void Esp::DrawBoxEsp(float* colorEnemy, float* colorFriendly, bool enemyOnly) {
	float headX, headY;
	float baseX, baseY;
	clientinfo_t* myclient = CODEngine::GetClientInfo(cg->iClientNum);

	for (int i = 0;i<12;i++)
	{
		entity_t* entity = CODEngine::GetEntity(i);
		if (i != cg->iClientNum && entity->isAlive())
		{
			vec3_t vecHead = CODEngine::GetTagPos(entity, j_helmet);
			if (this->WorldToScreen(vecHead, &headX, &headY) && this->WorldToScreen(entity->vOrigin, &baseX, &baseY))
			{
				float height = baseY - headY;
				float width = height / 1.5f;
				clientinfo_t* client = CODEngine::GetClientInfo(i);
				if (client != nullptr && myclient != nullptr && !enemyOnly && client->iTeam == myclient->iTeam)
				{
					Rendering::Instance()->DrawBox(headX - width / 2, headY, width, height, colorFriendly);
				}
				else if (client != nullptr && myclient != nullptr)
				{
					Rendering::Instance()->DrawBox(headX - width / 2, headY, width, height, colorEnemy);
				}
			}
		}
	}
}

void Esp::DrawBoneDot(clientinfo_t* myClient, clientinfo_t* enemyClient, entity_t* entity, __int64 tag, bool enemyOnly, float* colorEnemy, float* colorFriendly) {
	float boneX, boneY;
	vec3_t j_helmetPos = CODEngine::GetTagPos(entity, tag);
	if (WorldToScreen(j_helmetPos, &boneX, &boneY))
	{
		if (!enemyOnly && myClient->iTeam == enemyClient->iTeam)
		{
			Rendering::Instance()->DrawField(boneX-2, boneY-2, 4, 4, colorFriendly);
		}
		else
		{
			Rendering::Instance()->DrawField(boneX-2, boneY-2, 4, 4, colorEnemy);
		}
	}
}

void Esp::DrawBoneEspDot(float* colorEnemy, float* colorFriendly, bool enemyOnly) {
	clientinfo_t* myclient = CODEngine::GetClientInfo(cg->iClientNum);

	if (myclient != nullptr)
	{
		for (int i = 0;i < 12;i++)
		{
			entity_t* entity = CODEngine::GetEntity(i);
			if (i != cg->iClientNum && entity->isAlive())
			{
				this->DrawBoneDot(myclient, CODEngine::GetClientInfo(i), entity, j_helmet, false, colorEnemy, colorFriendly);
				this->DrawBoneDot(myclient, CODEngine::GetClientInfo(i), entity, j_head, false, colorEnemy, colorFriendly);
				this->DrawBoneDot(myclient, CODEngine::GetClientInfo(i), entity, j_neck, false, colorEnemy, colorFriendly);
				this->DrawBoneDot(myclient, CODEngine::GetClientInfo(i), entity, j_shoulder_le, false, colorEnemy, colorFriendly);
				this->DrawBoneDot(myclient, CODEngine::GetClientInfo(i), entity, j_elbow_le, false, colorEnemy, colorFriendly);
				this->DrawBoneDot(myclient, CODEngine::GetClientInfo(i), entity, j_wrist_le, false, colorEnemy, colorFriendly);
				this->DrawBoneDot(myclient, CODEngine::GetClientInfo(i), entity, j_shoulder_ri, false, colorEnemy, colorFriendly);
				this->DrawBoneDot(myclient, CODEngine::GetClientInfo(i), entity, j_elbow_ri, false, colorEnemy, colorFriendly);
				this->DrawBoneDot(myclient, CODEngine::GetClientInfo(i), entity, j_wrist_ri, false, colorEnemy, colorFriendly);
				this->DrawBoneDot(myclient, CODEngine::GetClientInfo(i), entity, j_spineupper, false, colorEnemy, colorFriendly);
				this->DrawBoneDot(myclient, CODEngine::GetClientInfo(i), entity, j_spinelower, false, colorEnemy, colorFriendly);
				this->DrawBoneDot(myclient, CODEngine::GetClientInfo(i), entity, j_hip_le, false, colorEnemy, colorFriendly);
				this->DrawBoneDot(myclient, CODEngine::GetClientInfo(i), entity, j_knee_le, false, colorEnemy, colorFriendly);
				this->DrawBoneDot(myclient, CODEngine::GetClientInfo(i), entity, j_ankle_le, false,  colorEnemy, colorFriendly);
				this->DrawBoneDot(myclient, CODEngine::GetClientInfo(i), entity, j_hip_ri, false, colorEnemy, colorFriendly);
				this->DrawBoneDot(myclient, CODEngine::GetClientInfo(i), entity, j_knee_ri, false, colorEnemy, colorFriendly);
				this->DrawBoneDot(myclient, CODEngine::GetClientInfo(i), entity, j_ankle_ri, false, colorEnemy, colorFriendly);
			}
		}
	}
}

void Esp::DrawBoneLine(clientinfo_t* myClient, clientinfo_t* enemyClient, entity_t* entity, __int64 tag1, __int64 tag2, bool enemyOnly, float* colorEnemy, float* colorFriendly) {
	float boneX1, boneY1, boneX2, boneY2;
	vec3_t vec1 = CODEngine::GetTagPos(entity, tag1);
	vec3_t vec2 = CODEngine::GetTagPos(entity, tag2);
	if (WorldToScreen(vec1, &boneX1, &boneY1) && WorldToScreen(vec2, &boneX2, &boneY2))
	{
		if (!enemyOnly && myClient->iTeam == enemyClient->iTeam)
		{
			Rendering::Instance()->DrawLine(boneX1, boneY1, boneX2, boneY2, 2, colorFriendly);
		}
		else
		{
			Rendering::Instance()->DrawLine(boneX1, boneY1, boneX2, boneY2, 2, colorEnemy);
		}
	}
}

void Esp::DrawBoneEspLine(float* colorEnemy, float* colorFriendly, bool enemyOnly) {
	clientinfo_t* myclient = CODEngine::GetClientInfo(cg->iClientNum);

	if (myclient != nullptr)
	{
		for (int i = 0;i < 12;i++)
		{
			entity_t* entity = CODEngine::GetEntity(i);
			if (i != cg->iClientNum && entity->isAlive())
			{
				clientinfo_t* client = CODEngine::GetClientInfo(i);
				DrawBoneLine(myclient, client, entity, j_head, j_neck, false, colorEnemy, colorFriendly);
				DrawBoneLine(myclient, client, entity, j_neck, j_shoulder_le, false, colorEnemy, colorFriendly);
				DrawBoneLine(myclient, client, entity, j_neck, j_shoulder_ri, false, colorEnemy, colorFriendly);
				DrawBoneLine(myclient, client, entity, j_shoulder_le, j_elbow_le, false, colorEnemy, colorFriendly);
				DrawBoneLine(myclient, client, entity, j_shoulder_ri, j_elbow_ri, false, colorEnemy, colorFriendly);
				DrawBoneLine(myclient, client, entity, j_elbow_le, j_wrist_le, false, colorEnemy, colorFriendly);
				DrawBoneLine(myclient, client, entity, j_elbow_ri, j_wrist_ri, false, colorEnemy, colorFriendly);
				DrawBoneLine(myclient, client, entity, j_neck, j_spineupper, false, colorEnemy, colorFriendly);
				DrawBoneLine(myclient, client, entity, j_spineupper, j_spinelower, false, colorEnemy, colorFriendly);
				DrawBoneLine(myclient, client, entity, j_spinelower, j_hip_le, false, colorEnemy, colorFriendly);
				DrawBoneLine(myclient, client, entity, j_spinelower, j_hip_ri, false, colorEnemy, colorFriendly);
				DrawBoneLine(myclient, client, entity, j_hip_le, j_knee_le, false, colorEnemy, colorFriendly);
				DrawBoneLine(myclient, client, entity, j_hip_ri, j_knee_ri, false, colorEnemy, colorFriendly);
				DrawBoneLine(myclient, client, entity, j_knee_le, j_ankle_le, false, colorEnemy, colorFriendly);
				DrawBoneLine(myclient, client, entity, j_knee_ri, j_ankle_ri, false, colorEnemy, colorFriendly);
			}
		}
	}
}

void Esp::DrawLineEsp(float* colorEnemy, float* colorFriendly, LineEspType lineEspType, bool enemyOnly) {
	clientinfo_t* myclient = CODEngine::GetClientInfo(cg->iClientNum);

	if (myclient != nullptr)
	{
		for (int i = 0;i < 12;i++)
		{
			entity_t* entity = CODEngine::GetEntity(i);
			if (i != cg->iClientNum && entity->isAlive())
			{
				float x, y;
				if (WorldToScreen(entity->vOrigin, &x, &y))
				{
					clientinfo_t* client = CODEngine::GetClientInfo(i);
					if (client != nullptr)
					{
						
						if (!enemyOnly && client->iTeam == myclient->iTeam)
						{
							Rendering::Instance()->DrawLine(refdef->iWidth / 2.f, refdef->iHeight - (60.f), x, y, 1, colorFriendly);
						}
						else
						{
							Rendering::Instance()->DrawLine(refdef->iWidth / 2.f, refdef->iHeight - (60.f), x, y, 1, colorEnemy);
						}
					}
				}
			}
		}
	}
}