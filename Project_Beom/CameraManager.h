#pragma once

class GameObject;
class CameraManager : public Singleton<CameraManager>
{
public:
	CameraManager();
	virtual ~CameraManager();

public:
	void SetPos(float x, float y);

public:
	const POSITION& GetPos() { return m_Pos; }
	const RESOLUTION& GetResolution() { return m_Resolution; }

public:
	void SetTarget(GameObject* target);
	void SetResolution(int x, int y);
	void SetFixPos(int x, int y);
	void SetOffset(int left, int top, int right, int bottom);

public:
	int  Update(const float& TimeDelta);
	void Release();

private:
	GameObject* m_Target = nullptr;
	POSITION	m_Pos;		// ���� ī�޶� ��ġ
	POSITION	m_DestPos;	// ī�޶� �̵��ؾ� �� ��ġ
	POSITION	m_FixPos;	// ī�޶� ��Ŀ���ؾ� �� ��ġ ����
	RECT		m_Offset;	// ��Ŀ�� ��ġ�� ���� ��������
							// ��Ŀ�� ��ġ���� �̹����� ����� ī�޶� �̵�

	RESOLUTION	m_Resolution;

	float		m_TimeX = 0.f;	// ī�޶� �̵��ӵ� ������ ���� Ÿ�Ӱ�
	float		m_TimeY = 0.f;
	float		m_Rate = 0.25f; // Ÿ�Ӱ��� �ִ밪(���ϼ��� �̵����ӵ� ������
};

