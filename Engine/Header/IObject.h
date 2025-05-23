#pragma once
#include "Engine_Macro.h"
#include "IClone.h"

BEGIN(Engine)
class IComponent;
class Transform;

class ENGINE_DLL IObject : public IClone
{
public:
	IObject(GameInstance& Instance);

public:
	virtual void FixedUpdate(float DT)	PURE;
	virtual void Update(float DT)		PURE;
	virtual void LateUpdate(float DT)	PURE;
	virtual void Render_Begin()			PURE;
	virtual void Render()				PURE;
	virtual void Render_End()			PURE;

public:
	IComponent* AddComponent(const std::string& Name, void* Args = nullptr);
	IComponent* GetComponent(const std::string& Name);

private:
	void Initialize(const void* Args) override PURE;
	IClone* Clone() override PURE;
	void Free() override PURE;

private:
	std::unordered_map<std::string, IComponent*> m_ComponentMap;

protected:
	GameInstance& instance;
	Transform* m_Transform = nullptr;
};
END