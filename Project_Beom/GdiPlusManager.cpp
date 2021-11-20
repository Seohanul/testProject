#include "pch.h"
#include "GdiPlusManager.h"

GdiPlusManager::GdiPlusManager()
{
	// Gdi+ ���̺귯�� �ʱ�ȭ
	GdiplusStartupInput m_gdiPlusStartupInput;
	GdiplusStartup(&m_gdiPlusToken, &m_gdiPlusStartupInput, NULL);

	// Graphics �ʱ�ȭ
	//g_pGraphic = new Graphics()
}

GdiPlusManager::~GdiPlusManager()
{
	ResetContainer();
	GdiplusShutdown(m_gdiPlusToken);
}

void GdiPlusManager::LoadImageBySceneState(SCENESTATE SceneState)
{
	switch (SceneState)
	{
	case SCENESTATE::SCENE_TEST:
	case SCENESTATE::SCENE_STAGE:
		break;
	}
}

GdiPlusImage* GdiPlusManager::FindImage(const TCHAR* tag)
{
	MAPIMAGES::const_iterator iter = m_mapImages.find(tag);

	if (m_mapImages.end() == iter)
		return nullptr;

	return iter->second;
}

void GdiPlusManager::LoadGdiPlusImage(const TCHAR* tag, const TCHAR* filePath)
{
	m_mapImages.emplace(MAPIMAGES::value_type(tag, (new GdiPlusImage)->LoadGdiPlusImage(filePath)));
}

void GdiPlusManager::LoadGdiPlusImageFromFolder(const TCHAR* tag, bstr_t folderPath)
{
	m_mapImages.emplace(MAPIMAGES::value_type(tag, (new GdiPlusImage)->LoadGdiPlusImageFromFolder(folderPath)));
}

void GdiPlusManager::ResetContainer()
{
	for (auto& image : m_mapImages)
	{
		delete image.second;
		image.second = nullptr;
	}

	m_mapImages.clear();
}