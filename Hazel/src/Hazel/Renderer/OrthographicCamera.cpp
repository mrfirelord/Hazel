#include "hzpch.h"
#include "OrthographicCamera.h"

#include <glm/gtc/matrix_transform.hpp>

namespace Hazel {
	OrthographicCamera::OrthographicCamera(float left, float right, float bottom, float top)
		: m_ProjectionMatrix(glm::ortho(left, right, bottom, top)), m_ViewMatrix(1.0) {
		HZ_PROFILE_FUNCTION();

		m_ViewProjectionMatrix = m_ProjectionMatrix * m_ViewMatrix;
	}

	void OrthographicCamera::SetProjection(float left, float right, float bottom, float top) {
		HZ_PROFILE_FUNCTION();

		m_ProjectionMatrix = glm::ortho(left, right, bottom, top);
		m_ViewProjectionMatrix = m_ProjectionMatrix * m_ViewMatrix;
	}

	void OrthographicCamera::RecalculateViewMatrix() {
		HZ_PROFILE_FUNCTION();

		glm::mat4 transform =
			glm::translate(glm::mat4(1.0), m_Position) *
			glm::rotate(glm::mat4(1.0), glm::radians(m_Rotation), glm::vec3(0, 0, 1.0));

		m_ViewMatrix = glm::inverse(transform);
		m_ViewProjectionMatrix = m_ProjectionMatrix * m_ViewMatrix;
	}
}


