#include "ObjectManager.h"

ObjectManager::ObjectManager(PrototypeManager& Prototype)
	: m_Prototype(Prototype)
{}

ObjectManager::~ObjectManager()
{
	Clear();
}

IObject* ObjectManager::Add_Object(RENDER_TYPE Type, const std::string& Name, const void* Args)
{
	auto* newClone = static_cast<IObject*>(m_Prototype.Clone(PROTO_TYPE::OBJECT, Name, Args));
	m_ObjectMap.emplace(Name, newClone);
	m_Objects.emplace_back(newClone);
	if(Type != RENDER_TYPE::NONE)
		m_Renders[static_cast<size_t>(Type)].emplace_back(newClone);
	return newClone;
}

void ObjectManager::FixedUpdate(float DT)
{
	for(auto& var : m_Objects)
	{
		var->FixedUpdate(DT);
	}
}

void ObjectManager::Update(float DT)
{
	for(auto& var : m_Objects)
	{
		var->Update(DT);
	}
}

void ObjectManager::LateUpdate(float DT)
{
	for(auto& var : m_Objects)
	{
		var->LateUpdate(DT);
	}
}

void ObjectManager::Render()
{
	for(auto& array : m_Renders)
	{
		for(auto& var : array)
		{
			var->Render_Begin();
			var->Render();
			var->Render_End();
		}
	}
}

void ObjectManager::Clear()
{
	m_ObjectMap.clear();
	m_Objects.clear();
	for(auto& array : m_Renders)
	{
		array.clear();
	}
}