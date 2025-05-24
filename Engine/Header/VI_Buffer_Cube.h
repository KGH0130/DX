#pragma once
#include "Engine_Macro.h"

BEGIN(Engine)
class ENGINE_DLL VI_Buffer_Cube : public VI_Buffer
{
public:
	VI_Buffer_Cube(LPDEVICE& Device);
	VI_Buffer_Cube(const VI_Buffer_Cube& rhs);

private:
	void Initialize(const void* Args) override;
	IClone* Clone() override;
};
END