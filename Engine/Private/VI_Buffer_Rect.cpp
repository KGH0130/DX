#include "VI_Buffer_Rect.h"

VI_Buffer_Rect::VI_Buffer_Rect(LPDEVICE& Device)
	: VI_Buffer(Device)
{
	m_VTX = VTX_DESC(4, D3DPT_TRIANGLELIST, 2, sizeof(VTXPOSTEX), VTXPOSTEX::FVF);
	m_IDX = IDX_DESC(6);

	if(FAILED(device->CreateVertexBuffer(m_VTX.numVertices * m_VTX.stride, 0, m_VTX.fvf, D3DPOOL_MANAGED, &m_VB, nullptr)))
		assert(false);

	VTXPOSTEX* vtx = nullptr;
	m_VB->Lock(0, 0, reinterpret_cast<void**>(&vtx), 0);
	vtx[0].pos = vector3(-0.5f, 0.5, 0.f);
	vtx[0].tex = vector2(0.f, 0.f);

	vtx[1].pos = vector3(0.5f, 0.5f, 0.f);
	vtx[1].tex = vector2(1.f, 0.f);

	vtx[2].pos = vector3(0.5f, -0.5f, 0.f);
	vtx[2].tex = vector2(1.f, 1.f);

	vtx[3].pos = vector3(-0.5f, -0.5f, 0.f);
	vtx[3].tex = vector2(0.f, 1.f);
	m_VB->Unlock();

	if(FAILED(device->CreateIndexBuffer(m_IDX.numIndices * m_IDX.stride, 0, m_IDX.indexFormat, D3DPOOL_MANAGED, &m_IB, nullptr)))
		assert(false);

	uint16_t* idx = nullptr;
	m_IB->Lock(0, 0, reinterpret_cast<void**>(&idx), 0);
	idx[0] = 0;
	idx[1] = 1;
	idx[2] = 2;

	idx[3] = 0;
	idx[4] = 2;
	idx[5] = 3;
	m_IB->Unlock();
}

VI_Buffer_Rect::VI_Buffer_Rect(const VI_Buffer_Rect& rhs)
	: VI_Buffer(rhs)
{}

void VI_Buffer_Rect::Initialize(const void* Args)
{}

IClone* VI_Buffer_Rect::Clone()
{
	return new VI_Buffer_Rect(*this);
}
