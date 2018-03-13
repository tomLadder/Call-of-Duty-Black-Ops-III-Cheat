#include "NameEsp.h"
#include "Color.h"

void NameEsp::draw(entity_t* entity, clientinfo_t* clientinfo, bool isFriendly, bool isVisible)
{
	float x, y;
	if (CODMath::getInstance()->WorldToScreen(entity->vecOrigin, &x, &y))
	{
		Color* color = this->getCorrectColor(isFriendly, isVisible);
		float scale = 700 / entity->vecOrigin.GetDistance(BO3Engine::getInstance()->GetRefDef()->vecOrigin);
		//Clamp
		if (scale < 0.9f)
			scale = 0.9f;

		if (scale > 1.7f)
			scale = 1.7f;

		BO3Render::getInstance()->DrawEngineTextFormatted(BO3Render::MIDDLE, x - 50, y, 100, 30, scale, clientinfo->cName, color->toFloat());
	}
}
