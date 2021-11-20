#include "pch.h"
#include "CreditScene.h"

CreditScene::CreditScene()
{
}

CreditScene::~CreditScene()
{
}

bool CreditScene::Initialize()
{
	// MCI (Media Control Interface)
	// ����� �� ���� �ֺ� ��ġ�� �����ϴ� �������� ����� �������α׷��� �����ϴ� �������̽���.
	m_hVideo = MCIWndCreate(g_hWnd, NULL, MCIWNDF_NOPLAYBAR | WS_VISIBLE | WS_CHILD
		, L"../Video/Ending.wmv");

	MoveWindow(m_hVideo, 0, 0, WINSIZE_X, WINSIZE_Y, FALSE);
	MCIWndPlay(m_hVideo); // �̵�� ���

	return true;
}

int CreditScene::Update(const float& TimeDelta)
{
	if (GETMGR(KeyManager)->GetKeyState(STATE_DOWN, VK_RETURN))
	{
		GETMGR(SceneManager)->ChangeSceneState(SCENE_LOGO);
		return 0;
	}

	return 0;
}

void CreditScene::Render(HDC hDC)
{
}

void CreditScene::Release()
{
	MCIWndClose(m_hVideo);
}
