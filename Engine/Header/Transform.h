#pragma once
#include "Engine_Macro.h"
#include "IComponent.h"

BEGIN(Engine)
class ENGINE_DLL Transform : public IComponent
{
public:
	struct TRANSFORM_DESC
	{
		TRANSFORM_DESC() = default;
		TRANSFORM_DESC(float MoveSpeed, float RotateSpeed)
			: moveSpeed(MoveSpeed), rotateSpeed(D3DXToRadian(RotateSpeed))
		{}
		float moveSpeed = 0.f;
		float rotateSpeed = 0.f;
	};

public:
	Transform(LPDEVICE Device);
	Transform(const Transform& rhs);

public:
	vector3 GetState(STATE State) const;
	void SetState(STATE State, const vector3& Value);
	const vector3 GetScale() const;

	const matrix& GetWorldMatrix() const;
	const matrix GetInverseMatrix() const;

public:
	void Move_Forward(float DT);
	void Move_Backward(float DT);
	void Move_Left(float DT);
	void Move_Right(float DT);

public:
	void Rotation(const vector3& Axis, float Radian);
	void Turn(const vector3& Axis, float Radian, float DT);
public:
	void Look_At(const vector3& Target);
	void Move_To(const vector3& Target, float DT, float Limit = 0.01f);

private:
	void Initialize(const void* Args) override;
	IClone* Clone() override;
	void Free() override;

private:
	matrix m_WorldMat;

	TRANSFORM_DESC m_Desc;
};
END