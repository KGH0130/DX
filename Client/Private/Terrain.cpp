#include "Terrain.h"

Terrain::Terrain(GameInstance& Instance)
	: IObject(Instance)
{}

Terrain::Terrain(const Terrain& rhs)
	: IObject(rhs)
{}

void Terrain::FixedUpdate(float DT)
{}

void Terrain::Update(float DT)
{
	if(instance.Input.GetKeyDown(SPACE))
	{
		vector3 pos = m_Transform->GetState(STATE::POSITION);
		pos.y -= 1.f;
		m_Transform->SetState(STATE::POSITION, pos);
	}
}

void Terrain::LateUpdate(float DT)
{}

void Terrain::Render_Begin()
{
	instance.Device->SetRenderState(D3DRS_LIGHTING, FALSE);
	instance.Device->SetRenderState(D3DRS_CULLMODE, D3DCULL_CCW);
}

void Terrain::Render()
{
	m_Transform->Render();

	m_Texture->Render();

	m_Buffer->Render();
}

void Terrain::Render_End()
{
	instance.Device->SetRenderState(D3DRS_LIGHTING, TRUE);
}

void Terrain::Initialize(const void* Args)
{
	m_Transform = static_cast<Transform*>(AddComponent("TRANSFORM"));
	m_Buffer = static_cast<VI_Buffer_Terrain*>(AddComponent("TERRAIN"));
	m_Texture = static_cast<Texture*>(AddComponent("TERRAIN_TEXTURE"));
}

IClone* Terrain::Clone()
{
	return new Terrain(*this);
}

void Terrain::Free()
{}
