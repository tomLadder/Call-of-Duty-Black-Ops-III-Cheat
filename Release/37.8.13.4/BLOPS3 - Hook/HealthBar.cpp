#include "HealthBar.h"

void HealthBar::Draw()
{
	refdef_t* refdef = CODEngine::GetRefDef();
	cg_t* cg = CODEngine::GetCGT();

	Rendering::Instance()->DrawBox(refdef->iWidth / 2 - this->width / 2 - 4, refdef->iHeight - 10 - this->height - 4, this->width + 8, this->height + 4, this->HealthBarSurroundColor);
	Rendering::Instance()->DrawField(refdef->iWidth / 2 - this->width / 2, refdef->iHeight - 10 - this->height, this->width, this->height, this->HealthBarBackGroundColor);

	int health = cg->iHealth;
	
	if (health >= 90 && health <= 100)
	{
		Rendering::Instance()->DrawField(refdef->iWidth / 2 - this->width / 2, refdef->iHeight - 10 - this->height, (this->width/100)*health, this->height, this->HealthBarColor90To100);
	}
	else if (health >= 80 && health < 90)
	{
		Rendering::Instance()->DrawField(refdef->iWidth / 2 - this->width / 2, refdef->iHeight - 10 - this->height, (this->width / 100)*health, this->height, this->HealthBarColor80To90);
	}
	else if (health >= 70 && health < 80)
	{
		Rendering::Instance()->DrawField(refdef->iWidth / 2 - this->width / 2, refdef->iHeight - 10 - this->height, (this->width / 100)*health, this->height, this->HealthBarColor70To80);
	}
	else if (health >= 60 && health < 70)
	{
		Rendering::Instance()->DrawField(refdef->iWidth / 2 - this->width / 2, refdef->iHeight - 10 - this->height, (this->width / 100)*health, this->height, this->HealthBarColor60To70);
	}
	else if (health >= 50 && health < 60)
	{
		Rendering::Instance()->DrawField(refdef->iWidth / 2 - this->width / 2, refdef->iHeight - 10 - this->height, (this->width / 100)*health, this->height, this->HealthBarColor50To60);
	}
	else if (health >= 40 && health < 50)
	{
		Rendering::Instance()->DrawField(refdef->iWidth / 2 - this->width / 2, refdef->iHeight - 10 - this->height, (this->width / 100)*health, this->height, this->HealthBarColor40To50);
	}
	else if (health >= 30 && health < 40)
	{
		Rendering::Instance()->DrawField(refdef->iWidth / 2 - this->width / 2, refdef->iHeight - 10 - this->height, (this->width / 100)*health, this->height, this->HealthBarColor30To40);
	}
	else if (health >= 20 && health < 30)
	{
		Rendering::Instance()->DrawField(refdef->iWidth / 2 - this->width / 2, refdef->iHeight - 10 - this->height, (this->width / 100)*health, this->height, this->HealthBarColor20To30);
	}
	else if (health >= 10 && health < 20)
	{
		Rendering::Instance()->DrawField(refdef->iWidth / 2 - this->width / 2, refdef->iHeight - 10 - this->height, (this->width / 100)*health, this->height, this->HealthBarColor10To20);
	}
	else if (health >= 0 && health < 10)
	{
		Rendering::Instance()->DrawField(refdef->iWidth / 2 - this->width / 2, refdef->iHeight - 10 - this->height, (this->width / 100)*health, this->height, this->HealthBarColor0To10);
	}
}