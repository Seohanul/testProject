#pragma once
#include "State.h"

class PlayerTopRunJumpAttState
	: public State
{
public:
	PlayerTopRunJumpAttState();
	virtual ~PlayerTopRunJumpAttState();

public:
	virtual void Enter(GameObject* object);
	virtual State* HandleInput(GameObject* object, KeyManager* input);
	virtual void Update(GameObject* object, const float& TimeDelta);

private:
	DIRECTION  m_originDir = DIR_END;
	int m_count = 0;
};
