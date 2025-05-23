#pragma once
#include "Engine_Macro.h"

BEGIN(Engine)
struct GameInstance;
class ILevel;

class ENGINE_DLL LevelManager
{
public:
	LevelManager(GameInstance& Instance);
	~LevelManager();

public:
	void OpenLevel(ILevel* Level);
	void SyncLevel();

public:
	void FixedUpdate(float DT);
	void Update(float DT);
	void LateUpdate(float DT);
	void Render();
	void EndFrame();
	void Reset();

private:
	void Render_Begin();
	void Render_End();

private:
	GameInstance& m_Instance;

	ILevel* m_CurLevel = nullptr;
	ILevel* m_NextLevel = nullptr;
};
END