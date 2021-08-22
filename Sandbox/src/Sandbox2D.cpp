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
	HZ_PROFILE_FUNCTION();
	{
		HZ_PROFILE_SCOPE("CameraController.OnUpdate");
		// Update
		m_CameraController.OnUpdate(ts);
	}

	{
		HZ_PROFILE_SCOPE("Renderer preparation");
		// Render
		Hazel::RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1 });
		Hazel::RenderCommand::Clear();
	}

	{
		HZ_PROFILE_SCOPE("Rendering scene");
		Hazel::Renderer2D::BeginScene(m_CameraController.GetCamera());

		Hazel::Renderer2D::DrawQuad({ -1.0, 0, 0.1 }, { 0.8f, 0.8f }, { 0.8f, 0.2f, 0.3f, 1.0f });
		Hazel::Renderer2D::DrawQuad({ 0.0, -0.0 }, { 1.5f, 1.75f }, m_CheckerboardTexture);

		Hazel::Renderer2D::EndScene();
	}
}

void Sandbox2D::OnEvent(Hazel::Event& event) {
	m_CameraController.OnEvent(event);
}

void Sandbox2D::OnImGuiRender() {
	HZ_PROFILE_FUNCTION();

	ImGui::Begin("Settings");
	ImGui::ColorEdit4("Square Color", glm::value_ptr(m_SquareColor));
	ImGui::End();
}