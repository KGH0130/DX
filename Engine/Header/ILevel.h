#pragma once
#include "Engine_Macro.h"

BEGIN(Engine)
struct GameInstance;

class ENGINE_DLL ILevel
{
public:
	ILevel(GameInstance& Instance);
	virtual ~ILevel() = default;

public:
	void OnLoding();

private:
	virtual void Initialize() PURE;
	virtual void Loding() PURE;

protected:
	GameInstance& instance;
};
END