#include "Main_Level.h"

void Main_Level::Initialize()
{

}

void Main_Level::Loding()
{
	instance->Prototype.Register_Prototype(PROTO_TYPE::COMPONENT, "TRANSFORM", new Transform(instance->Device));
	instance->Prototype.Register_Prototype(PROTO_TYPE::COMPONENT, "RECT", new VI_Buffer_Rect(instance->Device));
	instance->Prototype.Register_Prototype(PROTO_TYPE::COMPONENT, "PLAYER_TEXTURE", new Texture(instance->Device, TEXT("../Bin/Resources/Textures/Player/Player0.png")));
}
