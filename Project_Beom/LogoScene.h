#pragma once
class LogoScene
	: public Scene
{
public:
	LogoScene();
	virtual ~LogoScene();

public:
	virtual bool Initialize();
	virtual int Update(const float& TimeDelta);
	virtual void Render(HDC hDC);
	virtual void Release();

private:
	HWND	m_hVideo; // ������ ����� �ϱ����� ������â �ڵ�.

};

