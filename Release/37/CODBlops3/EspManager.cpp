#include "EspManager.h"

unsigned int j_helmet;
unsigned int j_head;
unsigned int j_neck;
unsigned int j_shoulder_le;
unsigned int j_elbow_le;
unsigned int j_wrist_le;
unsigned int j_shoulder_ri;
unsigned int j_elbow_ri;
unsigned int j_wrist_ri;
unsigned int j_spineupper;
unsigned int j_spinelower;
unsigned int j_hip_le;
unsigned int j_knee_le;
unsigned int j_ankle_le;
unsigned int j_hip_ri;
unsigned int j_knee_ri;
unsigned int j_ankle_ri;

EspManager* EspManager::_espManager = 0;

void EspManager::draw()
{
	BO3Engine* engine = BO3Engine::getInstance();
	cg_t* cg = engine->GetCGT(0);
	clientinfo_t* myclient = engine->GetClientInfo(cg->iClientNum);

	if (myclient != nullptr)
	{
		for (int i = 0; i < 18; i++)
		{
			entity_t* entity = engine->GetEntity(i);
			if (i !=cg->iClientNum && entity->isAlive())
			{
				clientinfo_t* clientinfo = engine->GetClientInfo(i);

				if (this->nameEsp_enabled)
					this->nameEsp->draw(entity, clientinfo, myclient->iTeam == clientinfo->iTeam, true);
			}
		}
	}
}