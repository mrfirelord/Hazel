#include <hzpch.h>

#include "Sandbox2D.h"

#include "Platform/OpenGL/OpenGLShader.h"

#include "imgui/imgui.h"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

Sandbox2D::Sandbox2D() : Layer("Sanbox2D"), m_CameraController(1.5f, true) {

}

void Sandbox2D::OnAttach() {
	m_CheckerboardTexture = Hazel::Texture2D::Create("assets/textures/Checkerboard.png");
}

void Sandbox2D::OnDetach() {
}

void Sandbox2D::OnUpdate(Hazel::Timestep ts) {
	// Update
	m_CameraController.OnUpdate(ts);

	// Render
	Hazel::RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1 });
	Hazel::RenderCommand::Clear();

	Hazel::Renderer2D::BeginScene(m_CameraController.GetCamera());

	Hazel::Renderer2D::DrawQuad({ -1.0, 0, 0.1 }, { 0.8f, 0.8f }, { 0.8f, 0.2f, 0.3f, 1.0f });
	Hazel::Renderer2D::DrawQuad({ 0.0, -0.0 },    { 1.5f, 1.75f }, m_CheckerboardTexture);
	
	Hazel::Renderer2D::EndScene();

	/*
	std::dynamic_pointer_cast<Hazel::OpenGLShader>(m_FlatColorShader)->Bind();
	std::dynamic_pointer_cast<Hazel::OpenGLShader>(m_FlatColorShader)->UploadUniformFloat4("u_Color", m_SquareColor);

	Hazel::Renderer::Submit(m_FlatColorShader, m_SquareVA, glm::mat4(1.0));
	*/
}

void Sandbox2D::OnEvent(Hazel::Event& event) {
	m_CameraController.OnEvent(event);
}

void Sandbox2D::OnImGuiRender() {
	ImGui::Begin("Settings");
	ImGui::ColorEdit4("Square Color", glm::value_ptr(m_SquareColor));
	ImGui::End();
}