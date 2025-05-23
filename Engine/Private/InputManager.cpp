#include "InputManager.h"

void InputManager::Update()
{
	std::memcpy(&m_PrevKey, &m_CurKey, sizeof(m_PrevKey));
	for(int i = 0; i < VK_MAX; ++i)
	{
		m_CurKey[i] = (GetAsyncKeyState(i) & 0x8000) != 0;
	}
}

bool InputManager::GetKey(Key Key) const
{
	return m_CurKey[Key];
}

bool InputManager::GetKeyDown(Key Key) const
{
	return m_CurKey[Key] && !m_PrevKey[Key];
}

bool InputManager::GetKeyUp(Key Key) const
{
	return !m_CurKey[Key] && m_PrevKey[Key];
}
