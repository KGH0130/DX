#include "TimeManager.h"

TimeManager::TimeManager(int Fixed, int Update)
	: m_FixedLimit(Fixed), m_UpdateLimit(Update)
	, m_FixedLimitDt(1.f / static_cast<float>(Fixed)), m_UpdateLimitDt(1.f / static_cast<float>(Update))
{
	QueryPerformanceFrequency(&m_Frequency);
	QueryPerformanceCounter(&m_PrevTime);
}

void TimeManager::Update()
{
	QueryPerformanceCounter(&m_CurTime);
	m_DT = static_cast<float>(m_CurTime.QuadPart - m_PrevTime.QuadPart) / static_cast<float>(m_Frequency.QuadPart);
	m_PrevTime = m_CurTime;
}

bool TimeManager::FixedLimit()
{
	if(firstFixed)
	{
		firstFixed = false;
		return true;
	}

	m_AccFDt += m_DT;
	if(m_AccFDt >= m_FixedLimitDt)
	{
		m_AccFDt -= m_FixedLimitDt;
		return true;
	}

	return false;
}
bool TimeManager::UpdateLimit()
{
	if(firstUpdate)
	{
		firstUpdate = false;
		return true;
	}

	m_AccUDt += m_DT;
	if(m_AccUDt >= m_UpdateLimitDt)
	{
		m_AccUDt -= m_FixedLimitDt;
		return true;
	}

	return false;
}

void TimeManager::FPS_INFO(HWND Hwnd)
{
	++m_FPS;
	m_AccDt += m_DT;
	if(m_AccDt >= 1.f)
	{
		wchar_t title[0xFF];
		swprintf_s(title, L"FPS: %d", m_FPS);
		SetWindowText(Hwnd, title);

		m_FPS = 0;
		m_AccDt = 0.f;
	}
}