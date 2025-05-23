#include "ILevel.h"

ILevel::ILevel(GameInstance& Instance)
	: instance(Instance)
{}

void ILevel::OnLoding()
{
	Loding();
	Initialize();
}