#include "Camera.h"

Camera::Camera(GameInstance& Instance)
	: IObject(Instance)
{}

Camera::Camera(const Camera& rhs)
	: IObject(rhs)
	, m_Desc(rhs.m_Desc)
{}

void Camera::FixedUpdate(float DT)
{}

void Camera::Update(float DT)
{
	if(instance.Input.GetKey(W))
	{
		m_Transform->Move_Forward(DT);
	}
	if(instance.Input.GetKey(S))
	{
		m_Transform->Move_Backward(DT);
	}
	if(instance.Input.GetKey(A))
	{
		m_Transform->Move_Left(DT);
	}
	if(instance.Input.GetKey(D))
	{
		m_Transform->Move_Right(DT);
	}
}

void Camera::LateUpdate(float DT)
{}

void Camera::Render()
{}

void Camera::Render_Begin()
{}

void Camera::Render_End()
{}

IClone* Camera::Clone()
{
	return new Camera(*this);
}

void Camera::Free()
{}

void Camera::Initialize(const void* Args)
{
	auto tfDesc = Transform::TRANSFORM_DESC(20, 20);
	m_Transform = static_cast<Transform*>(AddComponent("TRANSFORM", &tfDesc));
	if(!Args) return;

	std::memcpy(&m_Desc, Args, sizeof(m_Desc));

}
