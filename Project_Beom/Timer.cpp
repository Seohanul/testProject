#include "pch.h"
#include "Timer.h"

Timer::Timer()
{
}


Timer::~Timer()
{
}

bool Timer::Initialize()
{
	QueryPerformanceCounter(&m_FrameTime);	//���� CPU�� ī������ �ð��� �޾ƿ´�.

	QueryPerformanceCounter(&m_FixTime);    //�ʱ�ȭ
	QueryPerformanceCounter(&m_LastTime);

	QueryPerformanceFrequency(&m_CpuTick);   //CPU �ʴ� �������� ���´�.

	return true;
}

void Timer::Compute_Timer()
{
	// DeltaTime�� ���ϴ� �Լ�

	// �� ������ �ð��� �����Ѵ�.
	QueryPerformanceCounter(&m_FrameTime);

	// �� ������ �ð��� �� ���� ������ ���� ũ�ٸ� -> ���� �Ͻ������� ó���� �ȵǾ��ٴ°�
	// ���μ��� ���ϰ� �ɷ��� ��� �ð��� �ڷ� �и��� ���� ����
	if ((m_FrameTime.QuadPart - m_LastTime.QuadPart) > m_CpuTick.QuadPart)
	{
		// CPU �������� �ٽ� ���
		QueryPerformanceFrequency(&m_CpuTick);

		// ������ �ð��� �����Ѵ�.
		m_LastTime.QuadPart = m_FrameTime.QuadPart;
	}

	// �� ������ ������ �ð��� �ʴ� �������� ������ �� �����Ӵ� �����̴� ���� ����ȴ�.
	m_TimeDelta = float(m_FrameTime.QuadPart - m_FixTime.QuadPart) / m_CpuTick.QuadPart;

	m_FixTime = m_FrameTime;
}