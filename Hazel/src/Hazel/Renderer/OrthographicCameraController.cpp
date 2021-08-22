#include "hzpch.h"
#include "OrthographicCameraController.h"
#include "Hazel/Core/Input.h"
#include "Hazel/Core/KeyCodes.h"
#include "Hazel/Core/Core.h"

namespace Hazel {
	OrthographicCameraController::OrthographicCameraController(float aspectRatio, bool rotation) :
		m_Rotation(rotation),
		m_AspectRatio(aspectRatio),
		m_Camera(-aspectRatio * m_ZoomLevel, aspectRatio* m_ZoomLevel, -m_ZoomLevel, m_ZoomLevel) {
	}

	void OrthographicCameraController::OnUpdate(Timestep ts) {
		HZ_PROFILE_FUNCTION();

		if (Input::isKeyPressed(HZ_KEY_RIGHT))
			m_CameraPosition.x += m_CameraTranslationSpeed * ts;
		else if (Input::isKeyPressed(HZ_KEY_LEFT))
			m_CameraPosition.x -= m_CameraTranslationSpeed * ts;

		if (Input::isKeyPressed(HZ_KEY_UP))
			m_CameraPosition.y += m_CameraTranslationSpeed * ts;
		else if (Input::isKeyPressed(HZ_KEY_DOWN))
			m_CameraPosition.y -= m_CameraTranslationSpeed * ts;

		if (m_Rotation) {
			if (Input::isKeyPressed(HZ_KEY_Q))
				m_CameraRotation -= m_CameraRotationSpeed * ts;
			else if (Input::isKeyPressed(HZ_KEY_E))
				m_CameraRotation += m_CameraRotationSpeed * ts;

			m_Camera.SetRotation(m_CameraRotation);
		}

		m_Camera.SetPosition(m_CameraPosition);
		m_CameraTranslationSpeed = m_ZoomLevel;
	}

	void OrthographicCameraController::OnEvent(Event& e) {
		HZ_PROFILE_FUNCTION();

		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<MouseScrolledEvent>(HZ_BIND_EVENT_FN(OrthographicCameraController::OnMouseScrolled));
		dispatcher.Dispatch<WindowResizeEvent>(HZ_BIND_EVENT_FN(OrthographicCameraController::OnWindowResized));
	}

	bool OrthographicCameraController::OnMouseScrolled(MouseScrolledEvent& e) {
		HZ_PROFILE_FUNCTION();

		m_ZoomLevel -= e.GetYOffset() * 0.25f;
		m_ZoomLevel = std::max(m_ZoomLevel, 0.25f);
		HZ_CORE_INFO("ZoomLevel: {0}", m_ZoomLevel);

		m_Camera.SetProjection(-m_AspectRatio * m_ZoomLevel, m_AspectRatio * m_ZoomLevel, -m_ZoomLevel, m_ZoomLevel);
		return false;
	}

	bool OrthographicCameraController::OnWindowResized(WindowResizeEvent& e) {
		HZ_PROFILE_FUNCTION();

		m_AspectRatio = (float) e.GetWidth() / (float) e.GetHeight();
		m_Camera.SetProjection(-m_AspectRatio * m_ZoomLevel, m_AspectRatio * m_ZoomLevel, -m_ZoomLevel, m_ZoomLevel);
		return false;
	}
}