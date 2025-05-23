#pragma once
#include "Engine_Enum.h"
#include "Engine_Macro.h"

BEGIN(Engine)
class ENGINE_DLL InputManager
{
public:
	void Update();
	bool GetKey(Key Key) const;
	bool GetKeyDown(Key Key) const;
	bool GetKeyUp(Key Key) const;

private:
	bool m_PrevKey[VK_MAX]{}, m_CurKey[VK_MAX]{};
};
END