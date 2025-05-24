#pragma once
#pragma warning(disable: 4251)

#include <Windows.h>
#include <array>
#include <cassert>
#include <cstdint>
#include <d3d9.h>
#include <d3dx9.h>
#include <functional>
#include <string>
#include <thread>
#include <unordered_map>
#include <vector>

#include "Engine_Function.h"
#include "Engine_Macro.h"
#include "Engine_Struct.h"
#include "Engine_Typedef.h"

#include "GameInstance.h"

#include "Graphic_Device.h"
#include "IClone.h"
#include "IComponent.h"
#include "ILevel.h"
#include "IObject.h"
#include "InputManager.h"
#include "LevelManager.h"
#include "ObjectManager.h"
#include "PrototypeManager.h"
#include "Texture.h"
#include "TimeManager.h"
#include "Transform.h"
#include "VI_Buffer.h"
#include "VI_Buffer_Cube.h"
#include "VI_Buffer_Rect.h"
#include "VI_Buffer_Terrain.h"