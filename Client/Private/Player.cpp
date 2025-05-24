#include "Player.h"

Player::Player(GameInstance& Instance)
	: IObject(Instance)
{}

Player::Player(const Player& rhs)
	: IObject(rhs)
{}

void Player::FixedUpdate(float DT)
{}

void Player::Update(float DT)
{

}

void Player::LateUpdate(float DT)
{}

void Player::Render_Begin()
{
	instance.Device->SetRenderState(D3DRS_LIGHTING, FALSE);
	instance.Device->SetRenderState(D3DRS_CULLMODE, D3DCULL_CCW);
	instance.Device->SetRenderState(D3DRS_ALPHATESTENABLE, TRUE);
	instance.Device->SetRenderState(D3DRS_ALPHAREF, 125);
	instance.Device->SetRenderState(D3DRS_ALPHAFUNC, D3DCMP_GREATER);
}

void Player::Render()
{
	m_Transform->Render();

	m_Texture->Render();

	m_Buffer->Render();
}

void Player::Render_End()
{
	instance.Device->SetRenderState(D3DRS_ALPHATESTENABLE, FALSE);
}

void Player::Initialize(const void* Args)
{
	m_Transform = static_cast<Transform*>(AddComponent("TRANSFORM"));
	m_Buffer = static_cast<VI_Buffer_Rect*>(AddComponent("RECT"));
	m_Texture = static_cast<Texture*>(AddComponent("PLAYER_TEXTURE"));
}

IClone* Player::Clone()
{
	return new Player(*this);
}

void Player::Free()
{}
