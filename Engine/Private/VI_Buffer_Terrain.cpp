#include "VI_Buffer_Terrain.h"

VI_Buffer_Terrain::VI_Buffer_Terrain(LPDEVICE& DEVICE, uint32_t NumverticesX, uint32_t NumverticesZ)
	: VI_Buffer(DEVICE)
{
	m_VTX = VTX_DESC(NumverticesX * NumverticesZ, D3DPT_TRIANGLELIST, ((NumverticesX - 1) * (NumverticesZ - 1) * 2), sizeof(VTXPOSTEX), VTXPOSTEX::FVF);
	m_IDX = IDX_DESC(m_VTX.numPrimitive * 3, D3DFMT_INDEX32);

	if(FAILED(device->CreateVertexBuffer(m_VTX.numVertices * m_VTX.stride, 0, m_VTX.fvf, D3DPOOL_MANAGED, &m_VB, nullptr)))
		assert(false);

	VTXPOSTEX* vtx = nullptr;
	m_VB->Lock(0, 0, reinterpret_cast<void**>(&vtx), 0);
	for(uint32_t z = 0; z < NumverticesZ; z++)
	{
		for(uint32_t x = 0; x < NumverticesX; ++x)
		{
			uint32_t index = z * NumverticesX + x;

			vtx[index].pos = vector3(static_cast<float>(x), 0, static_cast<float>(z));
			vtx[index].tex = vector2(static_cast<float>(x) / static_cast<float>(NumverticesX - 1),
									 1.0f - static_cast<float>(z) / static_cast<float>(NumverticesZ - 1));
		}
	}
	m_VB->Unlock();

	if(FAILED(device->CreateIndexBuffer(m_IDX.numIndices * m_IDX.stride, 0, m_IDX.indexFormat, D3DPOOL_MANAGED, &m_IB, nullptr)))
		assert(false);

	uint32_t* idx = nullptr;
	size_t numIdx = 0;
	m_IB->Lock(0, 0, reinterpret_cast<void**>(&idx), 0);
	for(uint32_t z = 0; z < NumverticesZ - 1; ++z)
	{
		for(uint32_t x = 0; x < NumverticesX - 1; ++x)
		{
			uint32_t index = z * NumverticesX + x;

			idx[numIdx++] = index + NumverticesX;
			idx[numIdx++] = index + NumverticesX + 1;
			idx[numIdx++] = index + 1;

			idx[numIdx++] = index + NumverticesX;
			idx[numIdx++] = index + 1;
			idx[numIdx++] = index;
		}
	}
	m_IB->Unlock();
}

VI_Buffer_Terrain::VI_Buffer_Terrain(const VI_Buffer_Terrain& rhs)
	: VI_Buffer(rhs)
{}

void VI_Buffer_Terrain::Initialize(const void* Args)
{}

IClone* VI_Buffer_Terrain::Clone()
{
	return new VI_Buffer_Terrain(*this);
}
