#include "PrototypeManager.h"

PrototypeManager::~PrototypeManager()
{
	Clear();

	for(auto& [type, clone] : m_ProtoMap[static_cast<size_t>(PROTO_TYPE::COMPONENT)])
	{
		clone->Free();
		SAFE_DELETE(clone);
	}
	m_ProtoMap[static_cast<size_t>(PROTO_TYPE::COMPONENT)].clear();
}

void PrototypeManager::Register_Prototype(PROTO_TYPE Type, const std::string& Name, IClone* Clone)
{
	auto iter = m_ProtoMap[static_cast<size_t>(Type)].find(Name);
	assert(iter == m_ProtoMap[static_cast<size_t>(Type)].end());
	m_ProtoMap[static_cast<size_t>(Type)].emplace(Name, Clone);

}

IClone* PrototypeManager::Clone(PROTO_TYPE Type, const std::string& Name, const void* Args)
{
	auto iter = m_ProtoMap[static_cast<size_t>(Type)].find(Name);
	assert(iter != m_ProtoMap[static_cast<size_t>(Type)].end());
	auto* newObj = iter->second->Clone();
	newObj->Initialize(Args);
	m_Clones.emplace_back(newObj);
	return newObj;
}

void PrototypeManager::Clear()
{
	for(auto& var : m_Clones)
	{
		var->Free();
		SAFE_DELETE(var);
	}
	m_Clones.clear();

	for(auto& [type, clone] : m_ProtoMap[static_cast<size_t>(PROTO_TYPE::OBJECT)])
	{
		clone->Free();
		SAFE_DELETE(clone);
	}
	m_ProtoMap[static_cast<size_t>(PROTO_TYPE::OBJECT)].clear();
}
