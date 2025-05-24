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

	instance.Device->SetTransform(D3DTS_VIEW, &m_Transform->GetInverseMatrix());
	instance.Device->SetTransform(D3DTS_PROJECTION, D3DXMatrixPerspectiveFovLH(&m_ProjectionMat, m_Desc.fov, m_Desc.aspect, m_Desc.camNear, m_Desc.camFar));
	Transform* skytf = static_cast<Transform*>(m_Sky->GetComponent("TRANSFORM"));
	skytf->SetState(STATE::POSITION, m_Transform->GetState(STATE::POSITION));
}

void Camera::LateUpdate(float DT)
{}

void Camera::Render_Begin()
{}

void Camera::Render()
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
	auto tfDesc = Transform::TRANSFORM_DESC(20.f, 20.f);
	m_Transform = static_cast<Transform*>(AddComponent("TRANSFORM", &tfDesc));
	m_Sky = static_cast<Sky*>(instance.Object.Add_Object(RENDER_TYPE::PRIORITY, "SKY"));
	if(!Args) return;

	std::memcpy(&m_Desc, Args, sizeof(CAMERA_DESC));
	m_Transform->SetState(STATE::POSITION, m_Desc.eye);
	m_Transform->Look_At(m_Desc.at);
}
