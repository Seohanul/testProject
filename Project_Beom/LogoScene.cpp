#include "pch.h"
#include "LogoScene.h"

LogoScene::LogoScene()
{
}

LogoScene::~LogoScene()
{
}

bool LogoScene::Initialize()
{
	// MCI (Media Control Interface)
	// ����� �� ���� �ֺ� ��ġ�� �����ϴ� �������� ����� �������α׷��� �����ϴ� �������̽���.
	m_hVideo = MCIWndCreate(g_hWnd, NULL, MCIWNDF_NOPLAYBAR | WS_VISIBLE | WS_CHILD
		, L"../Video/Logo.wmv");

	MoveWindow(m_hVideo, 0, 0, WINSIZE_X, WINSIZE_Y, FALSE);
	MCIWndPlay(m_hVideo); // �̵�� ���
	return true;
}

int LogoScene::Update(const float& TimeDelta)
{
	if (GETMGR(KeyManager)->GetKeyState(STATE_DOWN, VK_RETURN))
	{
		GETMGR(SceneManager)->ChangeSceneState(SCENE_MENU);
		return 0;
	}

	return 0;
}

void LogoScene::Render(HDC hDC)
{
}

void LogoScene::Release()
{
	MCIWndClose(m_hVideo);
}
