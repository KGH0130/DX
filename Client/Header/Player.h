#pragma once

class Player : public IObject
{
public:
	Player(GameInstance& Instance);
	Player(const Player& rhs);

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

