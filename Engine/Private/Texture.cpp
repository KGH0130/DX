#include "Texture.h"

Texture::Texture(LPDEVICE& Device, const std::wstring& FilePath, uint32_t NumTexture)
	: IComponent(Device)
{
	for(size_t i = 0; i < NumTexture; ++i)
	{
		IDirect3DBaseTexture9* texture = nullptr;
		wchar_t textureFilePath[MAX_PATH]{};

		swprintf_s(textureFilePath, MAX_PATH, FilePath.c_str(), i);

		if(FAILED(D3DXCreateTextureFromFile(device, textureFilePath, reinterpret_cast<LPDIRECT3DTEXTURE9*>(&texture))))
			assert(false);

		m_Textures.emplace_back(texture);
	}
}

Texture::Texture(const Texture& rhs)
	: IComponent(rhs)
	, m_Textures(rhs.m_Textures)
{}

void Texture::Render(uint32_t TextureIndex)
{
	if(m_Textures.size() <= TextureIndex)
		assert(false);

	if(FAILED(device->SetTexture(0, m_Textures[TextureIndex])))
		assert(false);
}

void Texture::Initialize(const void* Args)
{}

IClone* Texture::Clone()
{
	return new Texture(*this);
}

void Texture::Free()
{
	for(auto& var : m_Textures)
	{
		var->Release();
	}
}