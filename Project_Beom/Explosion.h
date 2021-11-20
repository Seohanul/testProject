#pragma once
#include "GameObject.h"

class Explosion
	: public GameObject
{
public:
	Explosion();
	virtual ~Explosion();

public:
	virtual bool Initialize();
	virtual int  Update(const float& TimeDelta);
	virtual void Render(HDC hdc);
	virtual void Release();
};



