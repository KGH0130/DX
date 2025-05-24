#pragma once
#include "Sky.h"

class Camera : public IObject
{
public:
	struct CAMERA_DESC
	{
		CAMERA_DESC() = default;
		CAMERA_DESC(const vector3& Eye, const vector3& At, float Fov = 60)
			: eye(Eye), at(At)
			, fov(D3DXToRadian(Fov))
		{}
		vector3 eye, at;
		float fov = 0.f, camNear = 0.1f, camFar = 1000.f;
		float aspect = static_cast<float>(WINCX) / static_cast<float>(WINCY);
	};

public:
	Camera(GameInstance& Instance);
	Camera(const Camera& rhs);

private:
	void FixedUpdate(float DT) override;
	void Update(float DT) override;
	void LateUpdate(float DT) override;
	void Render_Begin() override;
	void Render() override;
	void Render_End() override;
private:
	void Initialize(const void* Args) override;
	IClone* Clone() override;
	void Free() override;

private:
	matrix m_ProjectionMat;
	CAMERA_DESC m_Desc;
	Sky* m_Sky = nullptr;;
};

