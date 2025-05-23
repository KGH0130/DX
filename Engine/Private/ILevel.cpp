#include "ILevel.h"

void ILevel::OnLoding(GameInstance* Instance)
{
	instance = Instance;
	Loding();
	Initialize();
}