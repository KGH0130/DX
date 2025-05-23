#include "IObject.h"

IObject::IObject(GameInstance& Instance)
	:instance(Instance)
{}

IComponent* IObject::AddComponent(const std::string& Name, void* Args)
{
	auto* newComponent = static_cast<IComponent*>(instance.Prototype.Clone(PROTO_TYPE::COMPONENT, Name, Args));
	m_ComponentMap.emplace(Name, newComponent);
	return newComponent;
}

IComponent* IObject::GetComponent(const std::string& Name)
{
	auto iter = m_ComponentMap.find(Name);
	assert(iter != m_ComponentMap.end());
	return iter->second;
}