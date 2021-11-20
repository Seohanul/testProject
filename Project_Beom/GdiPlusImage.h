#pragma once

class GdiPlusImage
{
public:
	GdiPlusImage();
	virtual ~GdiPlusImage();

public:
	Gdiplus::Image* GetGdiPlusImageDefault();
	Gdiplus::Image* GetGdiPlusImageFromIndex(int index);

public:
	GdiPlusImage* LoadGdiPlusImage(const TCHAR* filePath);
	GdiPlusImage* LoadGdiPlusImageFromFolder(bstr_t folderPath);

private:
	// GDI�� �ٸ��� �̹��� ��ü�� ���� �����̳ʿ� ���� �� �����Ƿ� 
	// �̹����� ��θ� �־���� ��θ� ���� �ε��Ѵ�.
	vector<const TCHAR*> m_vecFilePath;
};



