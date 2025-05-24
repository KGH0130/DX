#pragma once
#include "Engine_Macro.h"
#include "VI_Buffer.h"

BEGIN(Engine)
class ENGINE_DLL VI_Buffer_Terrain : public VI_Buffer
{
public:
	VI_Buffer_Terrain(LPDEVICE& DEVICE, uint32_t NumverticesX, uint32_t NumverticesZ);
	VI_Buffer_Terrain(const VI_Buffer_Terrain& rhs);

private:
	void Initialize(const void* Args) override;
	IClone* Clone() override;
};
END