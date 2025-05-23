#pragma once
#include "Engine_Macro.h"
#include "IComponent.h"

BEGIN(Engine)
class ENGINE_DLL VI_Buffer : public IComponent
{
public:
	VI_Buffer(LPDEVICE& Device);
	VI_Buffer(const VI_Buffer& rhs);

public:
	void Render();

private:
	void Initialize(const void* Args) override PURE;
	IClone* Clone() override PURE;
	void Free() override;

protected:
	LPDIRECT3DVERTEXBUFFER9	m_VB = nullptr;
	LPDIRECT3DINDEXBUFFER9 m_IB = nullptr;

	VTX_DESC m_VTX;
	IDX_DESC m_IDX;
};
END