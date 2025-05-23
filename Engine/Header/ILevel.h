#pragma once
#include "Engine_Macro.h"

BEGIN(Engine)
struct GameInstance;

class ENGINE_DLL ILevel
{
public:
	virtual ~ILevel() = default;

public:
	void OnLoding(GameInstance* Instance);

private:
	virtual void Initialize() PURE;
	virtual void Loding() PURE;

protected:
	GameInstance* instance = nullptr;
};
END