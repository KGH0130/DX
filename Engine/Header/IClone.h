#pragma once
#include "Engine_Macro.h"

BEGIN(Engine)
class ENGINE_DLL IClone
{
public:
	virtual ~IClone() = default;

public:
	virtual void Initialize(const void* Args) PURE;

public:
	virtual IClone* Clone() PURE;
	virtual void Free() PURE;
};
END