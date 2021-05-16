#pragma once

#include "Oberon.h"

class ExampleLayer : public Oberon::Layer
{
public:
	ExampleLayer();
	virtual ~ExampleLayer() = default;

	virtual void OnAttach() override;
	virtual void OnDetach() override;

	void OnUpdate(Oberon::Timestep ts) override;
	virtual void OnImGuiRender() override;
	void OnEvent(Oberon::Event& e) override;
private:
	Oberon::ShaderLibrary m_ShaderLibrary;
	Oberon::Ref<Oberon::Shader> m_Shader;
	Oberon::Ref<Oberon::VertexArray> m_VertexArray;

	Oberon::Ref<Oberon::Shader> m_FlatColorShader;
	Oberon::Ref<Oberon::VertexArray> m_SquareVA;

	Oberon::Ref<Oberon::Texture2D> m_Texture, m_ChernoLogoTexture;

	Oberon::OrthographicCameraController m_CameraController;
	glm::vec3 m_SquareColor = { 0.2f, 0.3f, 0.8f };
};