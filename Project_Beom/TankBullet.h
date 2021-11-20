#pragma once
#include "GameObject.h"

class TankBullet
	: public GameObject
{
public:
	TankBullet();
	virtual ~TankBullet();

public:
	virtual bool Initialize();
	virtual int  Update(const float& TimeDelta);
	virtual void Render(HDC hdc);
	virtual void Release();
};
