#pragma once
class GdiImage
{
public:
	GdiImage();
	virtual ~GdiImage();

public:
	//HDC GetMemDC() { return m_hMemDC; }
	HDC GetGdiImageDefault();
	HDC GetGdiImageFromIndex(int index);

public:
	GdiImage* LoadGdiImage(const TCHAR* pFilePath);
	GdiImage* LoadGdiImageFromFolder(bstr_t folderPath);

private:
	// ���ͷ� ��� ������ ��������Ʈ ���� ��쿡�� ���� �̹����� �ʿ��ϱ� �����̴�.
	vector<GDIINFO> m_vecImages;
};



