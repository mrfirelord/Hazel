#pragma once

namespace Hazel {
	class Timestep {
	public:
		Timestep(float time = 0.0) : m_Time(time) {}

		float GetSeconds() { return m_Time; }
		float GetMilliseconds() { return m_Time * 1000; }

		operator float() const { return m_Time; }
	private:
		float m_Time;
	};
}