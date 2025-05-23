#pragma once
#include "Engine_Macro.h"
#include "VI_Buffer.h"

BEGIN(Engine)
class ENGINE_DLL VI_Buffer_Rect : public VI_Buffer
{
public:
	VI_Buffer_Rect(LPDEVICE& Device);
	VI_Buffer_Rect(const VI_Buffer_Rect& rhs);

private:
	void Initialize(const void* Args) override;
	IClone* Clone() override;
};
END