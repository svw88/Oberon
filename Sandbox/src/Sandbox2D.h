#pragma once

#include "Oberon.h"

class Sandbox2D : public Oberon::Layer
{
public:
	Sandbox2D();
	virtual ~Sandbox2D() = default;

	virtual void OnAttach() override;
	virtual void OnDetach() override;

	void OnUpdate(Oberon::Timestep ts) override;
	virtual void OnImGuiRender() override;
	void OnEvent(Oberon::Event& e) override;
private:
	Oberon::OrthographicCameraController m_CameraController;

	// Temp
	Oberon::Ref<Oberon::VertexArray> m_SquareVA;
	Oberon::Ref<Oberon::Shader> m_FlatColorShader;

	Oberon::Ref<Oberon::Texture2D> m_CheckerboardTexture;

	glm::vec4 m_SquareColor = { 0.2f, 0.3f, 0.8f, 1.0f };
};