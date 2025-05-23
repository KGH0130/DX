#pragma once
#include "Engine_Macro.h"
#include "Engine_Struct.h"

BEGIN(Engine)
class ENGINE_DLL Graphic_Device
{
public:
	Graphic_Device(const GRAPHIC_DESC& Desc);
	~Graphic_Device();

public:
	LPDIRECT3DDEVICE9& GetDevice();

private:
	LPDIRECT3D9 m_SDK = nullptr;
	LPDIRECT3DDEVICE9 m_Device = nullptr;
};
END