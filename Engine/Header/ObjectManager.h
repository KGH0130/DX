#pragma once
#include "Engine_Enum.h"
#include "Engine_Macro.h"

BEGIN(Engine)
class IObject;

class ENGINE_DLL ObjectManager
{
public:
	~ObjectManager();

public:
	IObject* Register_Object(RENDER_TYPE Type, const std::string& Name, IObject* Obj);

public:
	void FixedUpdate(float DT);
	void Update(float DT);
	void LateUpdate(float DT);
	void Render();

	void Clear();
private:
	std::unordered_map<std::string, IObject*> m_ObjectMap;

	std::vector<IObject*> m_Objects;
	std::array<std::vector<IObject*>, static_cast<size_t>(RENDER_TYPE::NONE)> m_Renders;
};
END