#include "VI_Buffer.h"

VI_Buffer::VI_Buffer(LPDEVICE& Device)
	: IComponent(Device)
{}

VI_Buffer::VI_Buffer(const VI_Buffer& rhs)
	: IComponent(rhs)
	, m_VB(rhs.m_VB)
	, m_IB(rhs.m_IB)
	, m_VTX(rhs.m_VTX)
	, m_IDX(rhs.m_IDX)
{}

void VI_Buffer::Render()
{
	device->SetStreamSource(0, m_VB, 0, m_VTX.stride);
	device->SetFVF(m_VTX.fvf);
	device->SetIndices(m_IB);

	device->DrawIndexedPrimitive(m_VTX.primitiveType, 0, 0, m_VTX.numVertices, 0, m_VTX.numPrimitive);
}

void VI_Buffer::Free()
{
	m_VB->Release();
	m_IB->Release();
}
