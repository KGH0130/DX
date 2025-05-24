#pragma once

class Terrain : public IObject
{
public:
	Terrain(GameInstance& Instance);
	Terrain(const Terrain& rhs);

private:
	void FixedUpdate(float DT) override;
	void Update(float DT) override;
	void LateUpdate(float DT) override;
	void Render_Begin() override;
	void Render() override;
	void Render_End() override;
	void Initialize(const void* Args) override;
	IClone* Clone() override;
	void Free() override;

private:
	VI_Buffer* m_Buffer = nullptr;
	Texture* m_Texture = nullptr;
};

