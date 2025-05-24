#pragma once
#include "Engine_Macro.h"
#include "IComponent.h"

BEGIN(Engine)
class ENGINE_DLL Texture : public IComponent
{
public:
	Texture(LPDEVICE& Device, const std::wstring& FilePath, uint32_t NumTexture = 1u);
	Texture(const Texture& rhs);

public:
	void Render(uint32_t TextureIndex = 0);

private:
	void Initialize(const void* Args) override;
	IClone* Clone() override;
	void Free() override;

private:
	std::vector<IDirect3DBaseTexture9*> m_Textures;
};
END