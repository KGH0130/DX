#include "Main_Level.h"

Main_Level::Main_Level(GameInstance& Instance)
	: ILevel(Instance)
{}

void Main_Level::Initialize()
{
	auto cameraDesc = Camera::CAMERA_DESC(vector3(0.f, 10.f, -10.f), vector3(0.f, 0.f, 0.f));
	instance.Object.Add_Object(RENDER_TYPE::NONE, "CAMERA", &cameraDesc);
	instance.Object.Add_Object(RENDER_TYPE::BLEND, "PLAYER");
	instance.Object.Add_Object(RENDER_TYPE::NO_BLEND, "TERRAIN");
	//instance.Object.Add_Object(RENDER_TYPE::PRIORITY, "SKY");
}

void Main_Level::Loding()
{
	instance.Prototype.Register_Prototype(PROTO_TYPE::COMPONENT, "TRANSFORM", new Transform(instance.Device));
	instance.Prototype.Register_Prototype(PROTO_TYPE::COMPONENT, "RECT", new VI_Buffer_Rect(instance.Device));
	instance.Prototype.Register_Prototype(PROTO_TYPE::COMPONENT, "TERRAIN", new VI_Buffer_Terrain(instance.Device, 200, 200));
	instance.Prototype.Register_Prototype(PROTO_TYPE::COMPONENT, "CUBE", new VI_Buffer_Cube(instance.Device));

	instance.Prototype.Register_Prototype(PROTO_TYPE::COMPONENT, "PLAYER_TEXTURE", new Texture(instance.Device, TEXT("Resources/Textures/Player/Player0.png")));
	instance.Prototype.Register_Prototype(PROTO_TYPE::COMPONENT, "TERRAIN_TEXTURE", new Texture(instance.Device, TEXT("Resources/Textures/Terrain/Tile0.jpg")));
	instance.Prototype.Register_Prototype(PROTO_TYPE::COMPONENT, "SKY_TEXTURE", new Texture(instance.Device, TEXT("Resources/Textures/SkyBox/Sky_%d.dds"), 4, TEXTURE_TYPE::CUBE));

	instance.Prototype.Register_Prototype(PROTO_TYPE::OBJECT, "PLAYER", new Player(instance));
	instance.Prototype.Register_Prototype(PROTO_TYPE::OBJECT, "CAMERA", new Camera(instance));
	instance.Prototype.Register_Prototype(PROTO_TYPE::OBJECT, "TERRAIN", new Terrain(instance));
	instance.Prototype.Register_Prototype(PROTO_TYPE::OBJECT, "SKY", new Sky(instance));
}
