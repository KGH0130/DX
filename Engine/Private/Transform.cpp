#include "Transform.h"

Transform::Transform(LPDEVICE& Device)
	: IComponent(Device)
{
	D3DXMatrixIdentity(&m_WorldMat);
}

Transform::Transform(const Transform& rhs)
	: IComponent(rhs)
	, m_WorldMat(rhs.m_WorldMat)
{}

void Transform::Render()
{
	device->SetTransform(D3DTS_WORLD, &m_WorldMat);
}

vector3 Transform::GetState(STATE State) const
{
	vector3 newPos;
	std::memcpy(&newPos, reinterpret_cast<const vector3*>(m_WorldMat.m[static_cast<size_t>(State)]), sizeof(vector3));
	return newPos;
}

void Transform::SetState(STATE State, const vector3& Value)
{
	std::memcpy(&m_WorldMat.m[static_cast<size_t>(State)], &Value, sizeof(vector3));
}

const vector3 Transform::GetScale() const
{
	vector3 right = GetState(STATE::RIGHT);
	vector3 up = GetState(STATE::UP);
	vector3 look = GetState(STATE::LOOK);

	return vector3(D3DXVec3Length(&right),
				   D3DXVec3Length(&up),
				   D3DXVec3Length(&look));
}

const matrix& Transform::GetWorldMatrix() const
{
	return m_WorldMat;
}

const matrix& Transform::GetInverseMatrix()
{
	D3DXMatrixInverse(&m_InverseMat, nullptr, &m_WorldMat);
	return m_InverseMat;
}

void Transform::Move_Forward(float DT)
{
	vector3 pos = GetState(STATE::POSITION);
	vector3 look = GetState(STATE::LOOK);
	D3DXVec3Normalize(&look, &look);
	pos += look * m_Desc.moveSpeed * DT;
	SetState(STATE::POSITION, pos);
}

void Transform::Move_Backward(float DT)
{
	vector3 pos = GetState(STATE::POSITION);
	vector3 look = GetState(STATE::LOOK);
	D3DXVec3Normalize(&look, &look);
	pos -= look * m_Desc.moveSpeed * DT;
	SetState(STATE::POSITION, pos);
}

void Transform::Move_Left(float DT)
{
	vector3 pos = GetState(STATE::POSITION);
	vector3 right = GetState(STATE::RIGHT);
	D3DXVec3Normalize(&right, &right);
	pos -= right * m_Desc.moveSpeed * DT;
	SetState(STATE::POSITION, pos);
}

void Transform::Move_Right(float DT)
{
	vector3 pos = GetState(STATE::POSITION);
	vector3 right = GetState(STATE::RIGHT);
	D3DXVec3Normalize(&right, &right);
	pos += right * m_Desc.moveSpeed * DT;
	SetState(STATE::POSITION, pos);
}

void Transform::Rotation(const vector3& Axis, float Radian)
{
	vector3 scale = GetScale();

	vector3 right = vector3(1.f, 0.f, 0.f) * scale.x;
	vector3 up = vector3(0.f, 1.f, 0.f) * scale.y;
	vector3 look = vector3(0.f, 0.f, 1.f) * scale.z;

	matrix rotateMat;

	D3DXMatrixRotationAxis(&rotateMat, &Axis, D3DXToRadian(Radian));

	D3DXVec3TransformNormal(&right, &right, &rotateMat);
	D3DXVec3TransformNormal(&up, &up, &rotateMat);
	D3DXVec3TransformNormal(&look, &look, &rotateMat);

	SetState(STATE::RIGHT, right);
	SetState(STATE::UP, up);
	SetState(STATE::LOOK, look);
}

void Transform::Turn(const vector3& Axis, float Radian, float DT)
{
	vector3 right = GetState(STATE::RIGHT);
	vector3 up= GetState(STATE::UP);
	vector3 look= GetState(STATE::LOOK);

	matrix rotateMat;
	D3DXMatrixRotationAxis(&rotateMat, &Axis, D3DXToRadian(Radian));

	D3DXVec3TransformNormal(&right, &right, &rotateMat);
	D3DXVec3TransformNormal(&up, &up, &rotateMat);
	D3DXVec3TransformNormal(&look, &look, &rotateMat);

	SetState(STATE::RIGHT, right);
	SetState(STATE::UP, up);
	SetState(STATE::LOOK, look);
}

void Transform::Look_At(const vector3& Target)
{
	vector3 scale = GetScale();
	vector3 right, up, look;
	look = Target - GetState(STATE::POSITION);
	vector3 upDir = vector3(0.f, 1.f, 0.f);
	D3DXVec3Cross(&right, &upDir, &look);
	D3DXVec3Cross(&up, &look, &right);

	D3DXVec3Normalize(&right, &right);
	D3DXVec3Normalize(&up, &up);
	D3DXVec3Normalize(&look, &look);

	SetState(STATE::RIGHT, right * scale.x);
	SetState(STATE::UP, up * scale.y);
	SetState(STATE::LOOK, look * scale.z);
}

void Transform::Move_To(const vector3& Target, float DT, float Limit)
{
	vector3 pos = GetState(STATE::POSITION);
	vector3 look = Target - pos;

	if(D3DXVec3Length(&pos) > Limit) return;
	D3DXVec3Normalize(&look, &look);
	pos += look * m_Desc.moveSpeed * DT;
	SetState(STATE::POSITION, pos);
}


void Transform::Initialize(const void* Args)
{
	if(Args)
		std::memcpy(&m_Desc, Args, sizeof(m_Desc));
}

IClone* Transform::Clone()
{
	return new Transform(*this);
}

void Transform::Free()
{}
