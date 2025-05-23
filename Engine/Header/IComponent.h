#pragma once
#include "Engine_Macro.h"
#include "IClone.h"

BEGIN(Engine)
class ENGINE_DLL IComponent : public IClone
{
public:
	IComponent(LPDEVICE& Device);

private:
	void Initialize(const void* Args) override PURE;
	IClone* Clone() override PURE;
	void Free() override PURE;

protected:
	LPDEVICE& device;
};
END