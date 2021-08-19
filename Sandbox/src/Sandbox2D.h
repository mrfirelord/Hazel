#pragma once

#include "Hazel.h"

class Sandbox2D : public Hazel::Layer {
public:
	void OnAttach() override;
	void OnDetach() override;

	void OnUpdate(Hazel::Timestep timestep) override;
	void OnEvent(Hazel::Event& event) override;
	void OnImGuiRender() override;
private:
	Hazel::Ref<Hazel::Shader> m_Shader;
	Hazel::OrthographicCameraController m_CameraController;
	Hazel::Ref<Hazel::VertexArray> m_VertexArray;

	glm::vec3 m_SquareColor = { 0.2f, 0.3f, 0.8f };
};