#include "CODMath.h"

CODMath* CODMath::_CODMath = 0;

bool CODMath::WorldToScreen(vec3 world, float *x, float *y) {
	refdef_t* refdef = BO3Engine::getInstance()->GetRefDef();

	vec3 Position = world.VectorSubtract(refdef->vecOrigin);
	vec3 Transform = vec3(
		Position.DotProduct(refdef->vecAxisY),
		Position.DotProduct(refdef->vecAxisZ),
		Position.DotProduct(refdef->vecAxisX));

	if (Transform.z < 0.1f)
		return false;

	vec2 Center = vec2((float)(refdef->iWidth * 0.5f), (float)(refdef->iHeight * 0.5f));

	*x = Center.x * (1 - (Transform.x / refdef->fFovX / Transform.z));
	*y = Center.y * (1 - (Transform.y / refdef->fFovY / Transform.z));
	return true;
}