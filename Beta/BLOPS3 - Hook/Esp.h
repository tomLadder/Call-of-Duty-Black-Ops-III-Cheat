#pragma once
#include "Rendering.h"
#include "CODEngine.h"

enum LineEspType {Top, Bottom, Middle};

class Esp
{
private:
	bool WorldToScreen(vec3_t world, float *x, float *y);
	void DrawBoneDot(clientinfo_t* myClient, clientinfo_t* enemyClient, entity_t* entity, __int64 tag, bool enemyOnly, Rendering rendering, float* colorEnemy, float* colorFriendly);
	void DrawBoneLine(clientinfo_t* myClient, clientinfo_t* enemyClient, entity_t* entity, __int64 tag1, __int64 tag2, bool enemyOnly, Rendering rendering, float* colorEnemy, float* colorFriendly);
public:
	void DrawBoxEsp(float* colorEnemy, float* colorFriendly, bool enemyOnly, Rendering rendering);
	void DrawBoneEspLine(float* colorEnemy, float* colorFriendly, bool enemyOnly, Rendering rendering);
	void DrawBoneEspDot(float* colorEnemy, float* colorFriendly, bool enemyOnly, Rendering rendering);
	void DrawLineEsp(float* colorEnemy, float* colorFriendly, LineEspType lineEspType, bool enemyOnly, Rendering rendering);
};