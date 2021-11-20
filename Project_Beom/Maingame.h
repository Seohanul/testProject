#pragma once

class Maingame
{
public:
	Maingame();
	~Maingame();

public:
	bool Initialize();
	int  Update(const float& TimeDelta);
	void Render();
	void Release();

private:
	HDC		m_hDC;

	SceneManager* m_SceneMgr = nullptr;
	GdiPlusManager* m_GdiPlusMgr = nullptr;
	SoundManager* m_SoundMgr = nullptr;
};

