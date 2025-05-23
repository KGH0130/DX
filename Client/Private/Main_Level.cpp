#include "Main_Level.h"

Main_Level::Main_Level(GameInstance& Instance)
	: ILevel(Instance)
{}

void Main_Level::Initialize()
{
	auto cameraDesc = Camera::CAMERA_DESC(vector3(0.f, 0.f, -20.f), vector3(0.f, 0.f, 0.f));
	instance.Object.Add_Object(RENDER_TYPE::NONE, "CAMERA", &cameraDesc);
	instance.Object.Add_Object(RENDER_TYPE::BLEND, "PLAYER");
}

void Main_Level::Loding()
{
	instance.Prototype.Register_Prototype(PROTO_TYPE::COMPONENT, "TRANSFORM", new Transform(instance.Device));
	instance.Prototype.Register_Prototype(PROTO_TYPE::COMPONENT, "RECT", new VI_Buffer_Rect(instance.Device));
	instance.Prototype.Register_Prototype(PROTO_TYPE::COMPONENT, "PLAYER_TEXTURE", new Texture(instance.Device, TEXT("../Bin/Resources/Textures/Player/Player0.png")));

	instance.Prototype.Register_Prototype(PROTO_TYPE::OBJECT, "PLAYER", new Player(instance));
	instance.Prototype.Register_Prototype(PROTO_TYPE::OBJECT, "CAMERA", new Camera(instance));
}
