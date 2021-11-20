#include "pch.h"
#include "Maingame.h"

Maingame::Maingame()
{
}

Maingame::~Maingame()
{
	
}

bool Maingame::Initialize()
{
	// ����� �Ŵ��� �ʱ�ȭ
	m_GdiPlusMgr = GETMGR(GdiPlusManager);
	m_SceneMgr = GETMGR(SceneManager);
	m_SoundMgr = GETMGR(SoundManager);

	//if (!m_SceneMgr->ChangeSceneState(SCENE_MENU))
	//if (!m_SceneMgr->ChangeSceneState(SCENE_TOOL))
	if (!m_SceneMgr->ChangeSceneState(SCENE_LOGO))
		return false;

	// �׸� DC�ڵ��� �������� �ڵ�� ���� �����´�.
	m_hDC = GetDC(g_hWnd);


	return true;
}

int Maingame::Update(const float& TimeDelta)
{
	if (1.f <= TimeDelta)
		return 0;

	m_SoundMgr->UpdateSound();

	if (m_SceneMgr)
	{
		if (-1 == m_SceneMgr->Update(TimeDelta))
			return -1;
	}

	return 0;
}

void Maingame::Render()
{
	// ���� ���۸��� �ϴ� �۾��̴�. 
	HDC Memhdc;
	HBITMAP Membitmap;

	// m_hDC�� ȣȯ�Ǵ� ���ο� DC�� �����.
	// ȣȯ : �����ġ ���� or �׷��� ����̹� ����
	Memhdc = CreateCompatibleDC(m_hDC);
	// ���ڷ� �־��� DC�� ȣȯ�ϴ� ��Ʈ���� �����Ͽ� ��ȯ
	Membitmap = CreateCompatibleBitmap(m_hDC, WINSIZE_X, WINSIZE_Y);
	// Memhdc���� GDI Object�� �����Ѵ�.
	SelectObject(Memhdc, Membitmap);

	// ����� �׸� DC�� m_hDC�� �����Ѵ�.
	BitBlt(Memhdc, 0, 0, WINSIZE_X, WINSIZE_Y,
		m_hDC, 0, 0, SRCCOPY);

	// �׸� �ڵ�� ���ʿ� �´�.
	///////////////////////////////////////////////////
	if (m_SceneMgr)
	{
		m_SceneMgr->Render(Memhdc);
	}
	///////////////////////////////////////////////////

	// ����� �׸� DC�� m_hDC�� �����Ѵ�.
	BitBlt(m_hDC, 0, 0, WINSIZE_X, WINSIZE_Y,
		Memhdc, 0, 0, SRCCOPY);

	DeleteObject(Membitmap);
	DeleteDC(Memhdc);
}

void Maingame::Release()
{
	m_SceneMgr->DestroyInstance();
	m_GdiPlusMgr->DestroyInstance();
	GETMGR(ObjectManager)->DestroyInstance();
	GETMGR(CameraManager)->DestroyInstance();
	GETMGR(SoundManager)->DestroyInstance();
	GETMGR(CollisionManager)->DestroyInstance();
	GETMGR(FileManager)->DestroyInstance();

	ReleaseDC(g_hWnd, m_hDC);
}
