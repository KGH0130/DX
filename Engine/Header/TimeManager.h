#pragma once
#include "Engine_Macro.h"

BEGIN(Engine)
class ENGINE_DLL TimeManager
{
public:
	TimeManager(int Fixed, int Update);

public:
	void Update();

	bool FixedLimit();
	bool UpdateLimit();
	void FPS_INFO(HWND Hwnd);

private:
	LARGE_INTEGER m_Frequency{};
	LARGE_INTEGER m_PrevTime{}, m_CurTime{};

	int m_FPS = 0;
	int m_FixedLimit = 0, m_UpdateLimit = 0;

	float m_FixedLimitDt = 0.f, m_UpdateLimitDt = 0.f;
	float m_DT = 0.f;
	float m_AccDt = 0.f, m_AccUDt = 0.f, m_AccFDt = 0.f;

	bool firstFixed = true, firstUpdate = true;
};
END