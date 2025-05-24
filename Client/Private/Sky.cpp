#include "Sky.h"

Sky::Sky(GameInstance& Instance)
	: IObject(Instance)
{}

Sky::Sky(const Sky& rhs)
	: IObject(rhs)
{}

void Sky::FixedUpdate(float DT)
{}

void Sky::Update(float DT)
{}

void Sky::LateUpdate(float DT)
{}

void Sky::Render_Begin()
{
	instance.Device->SetRenderState(D3DRS_ZENABLE, FALSE);
	instance.Device->SetRenderState(D3DRS_ZWRITEENABLE, FALSE);
	instance.Device->SetRenderState(D3DRS_LIGHTING, FALSE);
	instance.Device->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE);
}

void Sky::Render()
{
	m_Transform->Render();
	m_Texture->Render(3);
	m_Buffer->Render();
}

void Sky::Render_End()
{
	instance.Device->SetRenderState(D3DRS_ZENABLE, TRUE);
	instance.Device->SetRenderState(D3DRS_ZWRITEENABLE, TRUE);
	instance.Device->SetRenderState(D3DRS_LIGHTING, TRUE);
	instance.Device->SetRenderState(D3DRS_CULLMODE, D3DCULL_CCW);
}

void Sky::Initialize(const void* Args)
{
	m_Transform = static_cast<Transform*>(AddComponent("TRANSFORM"));
	m_Texture = static_cast<Texture*>(AddComponent("SKY_TEXTURE"));
	m_Buffer = static_cast<VI_Buffer_Cube*>(AddComponent("CUBE"));
}

IClone* Sky::Clone()
{
	return new Sky(*this);
}

void Sky::Free()
{}
