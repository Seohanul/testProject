#include "pch.h"
#include "GdiImage.h"

GdiImage::GdiImage()
{
}


GdiImage::~GdiImage()
{
	// ���� ���� ����
	// DC�� ���õ� GDI ������Ʈ�� �ٷ� ������ �Ұ����ϴ�.
	// ����, OldBmp�� �̿��� �ع� ��Ų �� �����ؾ��Ѵ�.
	for (auto& image : m_vecImages)
	{
		SelectObject(image.hMemDC, image.OldBmp);
		DeleteObject(image.Bitmap);
		DeleteDC(image.hMemDC);
	}
	m_vecImages.clear();
}

HDC GdiImage::GetGdiImageDefault()
{
	if (m_vecImages.empty())
		return NULL;

	return m_vecImages[0].hMemDC;
}

HDC GdiImage::GetGdiImageFromIndex(int index)
{
	// �ε��� ������ �Ѱų� �����̳ʰ� ��� ������ �̹����� �����Ǹ� �̹����� �������� �ʴ´�.
	if (index >= (int)m_vecImages.size() || m_vecImages.empty())
		return NULL;

	return m_vecImages[index].hMemDC;
}

GdiImage* GdiImage::LoadGdiImage(const TCHAR* pFilePath)
{
	// �̹����� �ε��Ͽ� �����̳ʿ� �����Ѵ�.
	GDIINFO info;
	ZeroMemory(&info, sizeof(GDIINFO));

	info.hDC = GetDC(g_hWnd);
	// ���� ��� DC�� ȣȯ�� �Ǵ� MemDC�� �о�� ��Ʈ���� �̸� �׷��־� ����
	info.hMemDC = CreateCompatibleDC(info.hDC);
	info.Bitmap = (HBITMAP)LoadImage(NULL, pFilePath, IMAGE_BITMAP
		, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	if (NULL == info.Bitmap)
	{
		ERRORMSG(pFilePath);
		return NULL;
	}
	info.OldBmp = (HBITMAP)SelectObject(info.hMemDC, info.Bitmap);
	ReleaseDC(g_hWnd, info.hDC);

	m_vecImages.emplace_back(info);
	return this;
}

GdiImage* GdiImage::LoadGdiImageFromFolder(bstr_t folderPath)
{
	// �̹����� ��� ������ ��ü �̹������� �ε��Ͽ� �����̾�ʿ� �ִ´�.
	vector<bstr_t> fileNames;
	GET_MANAGER<FileManager>()->GetFileListFromFolder(folderPath + "/*.*", fileNames);

	TCHAR originPath[MAX_BUFFER];
	memset(originPath, 0, sizeof(TCHAR) * MAX_BUFFER);

	lstrcpy(originPath, (TCHAR*)(folderPath + "/"));

	for (auto& file : fileNames)
	{
		TCHAR* tmpPath = new TCHAR[MAX_BUFFER];
		memset(tmpPath, 0, sizeof(TCHAR) * MAX_BUFFER);

		lstrcpy(tmpPath, originPath);
		lstrcat(tmpPath, (TCHAR*)file);

		GDIINFO info;
		ZeroMemory(&info, sizeof(GDIINFO));

		info.hDC = GetDC(g_hWnd);
		// ���� ��� DC�� ȣȯ�� �Ǵ� MemDC�� �о�� ��Ʈ���� �̸� �׷��־� ����
		info.hMemDC = CreateCompatibleDC(info.hDC);
		info.Bitmap = (HBITMAP)LoadImage(NULL, tmpPath, IMAGE_BITMAP
			, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
		if (NULL == info.Bitmap)
		{
			ERRORMSG(tmpPath);
			return NULL;
		}
		info.OldBmp = (HBITMAP)SelectObject(info.hMemDC, info.Bitmap);
		ReleaseDC(g_hWnd, info.hDC);

		m_vecImages.emplace_back(info);
	}

	return this;
}
