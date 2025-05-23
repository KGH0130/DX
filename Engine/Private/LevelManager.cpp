#include "LevelManager.h"

LevelManager::LevelManager(GameInstance& Instance)
	: m_Instance(Instance)
{}

LevelManager::~LevelManager()
{
	SAFE_DELETE(m_CurLevel);
}

void LevelManager::OpenLevel(ILevel* Level)
{
	m_NextLevel = Level;
}

void LevelManager::SyncLevel()
{
	if(m_NextLevel == nullptr) return;

	if(m_CurLevel)
	{
		SAFE_DELETE(m_CurLevel);
		Reset();
	}

	m_CurLevel = m_NextLevel;
	m_NextLevel = nullptr;
	std::thread t1([&]
	{
		m_CurLevel->OnLoding(&m_Instance);
	});

	t1.join();
}

void LevelManager::FixedUpdate(float DT)
{
	m_Instance.Object.FixedUpdate(DT);
}

void LevelManager::Update(float DT)
{
	m_Instance.Input.Update();
	m_Instance.Object.Update(DT);
}

void LevelManager::LateUpdate(float DT)
{
	m_Instance.Object.LateUpdate(DT);
}

void LevelManager::Render()
{
	Render_Begin();
	m_Instance.Object.Render();
	Render_End();
}

void LevelManager::EndFrame()
{}

void LevelManager::Reset()
{
	m_Instance.Prototype.Clear();
	m_Instance.Object.Clear();
}


void LevelManager::Render_Begin()
{
	m_Instance.Device->Clear(0, nullptr,
							 D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER | D3DCLEAR_STENCIL, D3DCOLOR(0xFF0000FF), 1.f, 0);
	m_Instance.Device->BeginScene();
}

void LevelManager::Render_End()
{
	m_Instance.Device->EndScene();
	m_Instance.Device->Present(nullptr, nullptr, nullptr, nullptr);
}
