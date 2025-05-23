#pragma once
#include "ILevel.h"

class Main_Level : public ILevel
{
public:
	Main_Level(GameInstance& Instance);

private:
	void Initialize() override;
	void Loding() override;
};

