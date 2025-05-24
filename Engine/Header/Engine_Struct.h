#pragma once
#include "Engine_Typedef.h"

namespace Engine
{
struct GRAPHIC_DESC
{
	GRAPHIC_DESC() = default;
	GRAPHIC_DESC(HWND Hwnd, bool Windowed, uint32_t Wincx, uint32_t Wincy)
		: hwnd(Hwnd)
		, windowed(Windowed)
		, wincx(Wincx), wincy(Wincy)
	{}

	HWND hwnd = nullptr;
	bool windowed = true;
	uint32_t wincx = 0u, wincy = 0u;
};

struct VTX_DESC
{
	VTX_DESC() = default;
	VTX_DESC(uint32_t NumVertices, D3DPRIMITIVETYPE Type, uint32_t NumPrimitive, uint32_t Stride, uint32_t FVF)
		: numVertices(NumVertices)
		, primitiveType(Type)
		, numPrimitive(NumPrimitive)
		, stride(Stride)
		, fvf(FVF)
	{}

	uint32_t numVertices = 0;
	D3DPRIMITIVETYPE primitiveType{};
	uint32_t numPrimitive = 0;
	uint32_t stride = 0;
	uint32_t fvf = 0;
};

struct IDX_DESC
{
	IDX_DESC() = default;
	IDX_DESC(uint32_t NumIndices, D3DFORMAT Format = D3DFMT_INDEX16)
		: numIndices(NumIndices)
		, indexFormat(Format)
	{
		stride = Format == D3DFMT_INDEX16 ? sizeof(int16_t) : sizeof(int32_t);
	}
	uint32_t numIndices = 0;
	D3DFORMAT indexFormat{};
	uint32_t stride = 0;
};

struct VTXPOSTEX
{
	vector3 pos{};
	vector2 tex{};

	enum { FVF = D3DFVF_XYZ | D3DFVF_TEX1 };
};

struct VTXCUBETEX
{
	vector3 pos{};
	vector3 tex{};
	enum { FVF = D3DFVF_XYZ | D3DFVF_TEX1 | D3DFVF_TEXCOORDSIZE3(0) };
};

}