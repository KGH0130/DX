#pragma once

class Sky : public IObject
{
public:
	Sky(GameInstance& Instance);
	Sky(const Sky& rhs);

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
	Texture* m_Texture = nullptr;
	VI_Buffer* m_Buffer = nullptr;
};

