#include "ObjectManager.h"

ObjectManager::~ObjectManager()
{
	Clear();
}

IObject* ObjectManager::Register_Object(RENDER_TYPE Type, const std::string& Name, IObject* Obj)
{
	auto iter = m_ObjectMap.find(Name);
	assert(iter == m_ObjectMap.end());
	m_ObjectMap.emplace(Name, Obj);
	m_Objects.emplace_back(Obj);
	if(Type != RENDER_TYPE::NONE)
		m_Renders[static_cast<size_t>(Type)].emplace_back(Obj);
	return Obj;
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