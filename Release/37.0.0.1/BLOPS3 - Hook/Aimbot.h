#pragma once
#include "CODEngine.h"
#include "GlobalVars.h"

class Aimbot
{
public:
#define M_PI 3.141592653589
#define RAD2DEG(a) (((a) * 180.0f) / M_PI);

	static int GetBestPlayerDistance()
	{
		int index = -1;
		float distance = 9999999.9f;
		clientinfo_t* myClient = CODEngine::GetClientInfo(cg->iClientNum);

		if (myClient != nullptr)
		{
			for (int i = 0;i < 12;i++)
			{
				entity_t* entity = CODEngine::GetEntity(i);
				if (i != cg->iClientNum && entity->isAlive())
				{
					clientinfo_t* client = CODEngine::GetClientInfo(i);
					if (client != nullptr && client->iTeam != myClient->iTeam)
					{
						float dis = entity->vOrigin.GetDistance(refdef->vecOrigin);
						if (dis < distance)
						{
							distance = dis;
							index = i;
						}
					}
				}
			}
		}

		return index;
	}

	static void doSilentAim(usercmd_t* usercmd, usercmd_t* oldusercmd, usercmd_t* newusercmd)
	{
		int index = GetBestPlayerDistance();
		if (index != -1)
		{
			vec3_t vecHead = CODEngine::GetTagPos(CODEngine::GetEntity(index), *(__int64*)(0x147342DDC));
			vecHead = vecHead.VectorSubtract(refdef->vecOrigin);
			vecHead.VectorNormalize(&vecHead);

			usercmd->iViewAngleX += (int)RAD2DEG(asin(refdef->vecAxisY.DotProduct(vecHead)));
			usercmd->iViewAngleY += (int)RAD2DEG(-asin(refdef->vecAxisZ.DotProduct(vecHead)));

			oldusercmd->iViewAngleX += (int)RAD2DEG(asin(refdef->vecAxisY.DotProduct(vecHead)));
			oldusercmd->iViewAngleY += (int)RAD2DEG(-asin(refdef->vecAxisZ.DotProduct(vecHead)));

			newusercmd->iViewAngleX += (int)RAD2DEG(asin(refdef->vecAxisY.DotProduct(vecHead)));
			newusercmd->iViewAngleY += (int)RAD2DEG(-asin(refdef->vecAxisZ.DotProduct(vecHead)));
		}
	}
};