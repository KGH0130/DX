#include "VI_Buffer_Cube.h"

VI_Buffer_Cube::VI_Buffer_Cube(LPDEVICE& Device)
	: VI_Buffer(Device)
{
	m_VTX = VTX_DESC(8, D3DPT_TRIANGLELIST, 12, sizeof(VTXCUBETEX), VTXCUBETEX::FVF);
	m_IDX = IDX_DESC(36);

	if(FAILED(device->CreateVertexBuffer(m_VTX.numVertices * m_VTX.stride, 0, m_VTX.fvf, D3DPOOL_MANAGED, &m_VB, nullptr)))
		assert(false);
	VTXCUBETEX* vtx = nullptr;
	m_VB->Lock(0, 0, reinterpret_cast<void**>(&vtx), 0);
	vtx[0].pos = vector3(-0.5f, 0.5f, -0.5f);
	vtx[0].tex = vtx[0].pos;
	vtx[1].pos = vector3(0.5f, 0.5f, -0.5f);
	vtx[1].tex = vtx[1].pos;
	vtx[2].pos = vector3(0.5f, -0.5f, -0.5f);
	vtx[2].tex = vtx[2].pos;
	vtx[3].pos = vector3(-0.5f, -0.5f, -0.5f);
	vtx[3].tex = vtx[3].pos;

	vtx[4].pos = vector3(-0.5f, 0.5f, 0.5f);
	vtx[4].tex = vtx[4].pos;
	vtx[5].pos = vector3(0.5f, 0.5f, 0.5f);
	vtx[5].tex = vtx[5].pos;
	vtx[6].pos = vector3(0.5f, -0.5f, 0.5f);
	vtx[6].tex = vtx[6].pos;
	vtx[7].pos = vector3(-0.5f, -0.5f, 0.5f);
	vtx[7].tex = vtx[7].pos;
	m_VB->Unlock();

	if(FAILED(device->CreateIndexBuffer(m_IDX.numIndices * m_IDX.stride, 0, m_IDX.indexFormat, D3DPOOL_MANAGED, &m_IB, nullptr)))
		assert(false);
	uint16_t* idx = nullptr;
	m_IB->Lock(0, 0, reinterpret_cast<void**>(&idx), 0);
	// ¾Õ¸é
	*idx++ = 0; *idx++ = 1; *idx++ = 2;
	*idx++ = 0; *idx++ = 2; *idx++ = 3;

	// µÞ¸é
	*idx++ = 5; *idx++ = 4; *idx++ = 7;
	*idx++ = 5; *idx++ = 7; *idx++ = 6;

	// ¿ÞÂÊ¸é
	*idx++ = 4; *idx++ = 0; *idx++ = 3;
	*idx++ = 4; *idx++ = 3; *idx++ = 7;

	// ¿À¸¥ÂÊ¸é
	*idx++ = 1; *idx++ = 5; *idx++ = 6;
	*idx++ = 1; *idx++ = 6; *idx++ = 2;

	// ¹Ù´Ú¸é
	*idx++ = 4; *idx++ = 5; *idx++ = 1;
	*idx++ = 4; *idx++ = 1; *idx++ = 0;

	// À­¸é
	*idx++ = 3; *idx++ = 2; *idx++ = 6;
	*idx++ = 3; *idx++ = 6; *idx++ = 7;
	m_IB->Unlock();
}

VI_Buffer_Cube::VI_Buffer_Cube(const VI_Buffer_Cube& rhs)
	: VI_Buffer(rhs)
{}

void VI_Buffer_Cube::Initialize(const void* Args)
{}

IClone* VI_Buffer_Cube::Clone()
{
	return new VI_Buffer_Cube(*this);
}
