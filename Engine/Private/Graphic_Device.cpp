#include "Graphic_Device.h"

Graphic_Device::Graphic_Device(const GRAPHIC_DESC& Desc)
{
	m_SDK = Direct3DCreate9(D3D_SDK_VERSION);
	assert(m_SDK);

	D3DPRESENT_PARAMETERS d3dpp{};

	d3dpp.BackBufferWidth = Desc.wincx;
	d3dpp.BackBufferHeight = Desc.wincy;

	d3dpp.BackBufferFormat = D3DFMT_A8R8G8B8;
	d3dpp.BackBufferCount = 1;

	d3dpp.MultiSampleType = D3DMULTISAMPLE_NONE;
	d3dpp.MultiSampleQuality = 0;

	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	d3dpp.hDeviceWindow = Desc.hwnd;
	d3dpp.Windowed = Desc.windowed;

	d3dpp.EnableAutoDepthStencil = TRUE;
	d3dpp.AutoDepthStencilFormat = D3DFMT_D24S8;

	d3dpp.Flags = 0;

	d3dpp.FullScreen_RefreshRateInHz = D3DPRESENT_RATE_DEFAULT;
	d3dpp.PresentationInterval = D3DPRESENT_INTERVAL_IMMEDIATE;

	if(FAILED(m_SDK->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, Desc.hwnd,
								  D3DCREATE_HARDWARE_VERTEXPROCESSING | D3DCREATE_MULTITHREADED, &d3dpp, &m_Device)))
		assert(false);
}

Graphic_Device::~Graphic_Device()
{
	m_SDK->Release();
	m_Device->Release();
}

LPDIRECT3DDEVICE9 Graphic_Device::GetDevice() const
{
	return m_Device;
}
