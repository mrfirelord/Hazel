#pragma once

#include "Hazel.h"

class Sandbox2D : public Hazel::Layer {
public:
	Sandbox2D();
	virtual ~Sandbox2D() = default;

	void OnAttach() override;
	void OnDetach() override;

	void OnUpdate(Hazel::Timestep timestep) override;
	void OnEvent(Hazel::Event& event) override;
	void OnImGuiRender() override;
private:
	Hazel::Ref<Hazel::Shader> m_FlatColorShader;
	Hazel::OrthographicCameraController m_CameraController;
	Hazel::Ref<Hazel::VertexArray> m_SquareVA;

	glm::vec4 m_SquareColor = { 0.6f, 0.3f, 0.8f, 1.0f };
};