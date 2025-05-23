#pragma once
#include "Engine_Macro.h"
#include "InputManager.h"
#include "LevelManager.h"
#include "ObjectManager.h"
#include "PrototypeManager.h"

BEGIN(Engine)
struct GameInstance
{
	GameInstance(LPDIRECT3DDEVICE9 DEVICE)
		: Device(DEVICE), Level(*this)
	{}

	LPDIRECT3DDEVICE9 Device;
	LevelManager Level;
	PrototypeManager Prototype;
	ObjectManager Object;
	InputManager Input;
};
END