#pragma once

// �׳� �⺻���� ����� ����
typedef struct BaseInfo
{
	float X;
	float Y;

	void operator=(const BaseInfo& other)
	{
		this->X = other.X;
		this->Y = other.Y;
	}

	bool operator==(const BaseInfo& other)
	{
		if (this->X == other.X &&
			this->Y == other.Y)
			return true;
		else
			return false;
	}

	BaseInfo operator+(const BaseInfo& other)
	{
		return BaseInfo{ this->X + other.X, this->Y + other.Y };
	}

	void operator+=(const BaseInfo& other)
	{
		this->X += other.X; this->Y += other.Y;
	}

	BaseInfo operator-(const BaseInfo& other)
	{
		return BaseInfo{ this->X - other.X, this->Y - other.Y };
	}

	BaseInfo operator*(const float& other)
	{
		return BaseInfo{ this->X * other, this->Y * other };
	}

	BaseInfo operator/(const float& other)
	{
		return BaseInfo{ this->X / other, this->Y / other };
	}

}POSITION, RESOLUTION, OFFSET;

// ���� ������Ʈ ����
typedef struct GameObjectInfo
{
	float Pos_X;
	float Pos_Y;
	int Size_X;
	int Size_Y;
}GAMEOBJINFO;

// ��������Ʈ ����
typedef struct SpriteInfo
{
	// ��������Ʈ �̹��� �̸�
	const TCHAR* key;
	// ��������Ʈ y���� ������
	int StateIndex;
	// ����
	int CurState;
	int PreState;
	// ���Ÿ��
	SPRITETYPE Type;
	// Max
	int   MaxFrame;
	// ���ǵ�
	float Speed;
	// ���� �ε��� ��ġ
	float SpriteIndex;
}SPRITEINFO;

// GDI �̹��� ���� (GDI+�� �ش����� ����)
typedef struct GdiImageInfo
{
	HDC		hDC;
	HDC		hMemDC;

	HBITMAP Bitmap;
	HBITMAP OldBmp;
}GDIINFO;

// �ȼ� ����
typedef struct _tagPixel24
{
	unsigned char	b;
	unsigned char	g;
	unsigned char	r;

	bool operator==(_tagPixel24& other)
	{
		return other.r == r && other.g == g && other.b == b;
	}
}PIXEL24;

typedef struct _tagPixelColliderInfo
{
	vector<PIXEL24>		vecPixel;
	UINT				Width;
	UINT				Height;
	vector<PIXEL24>		CollPixels;
	POSITION			IntersectPos;
}PIXELCOLLIDERINFO;

