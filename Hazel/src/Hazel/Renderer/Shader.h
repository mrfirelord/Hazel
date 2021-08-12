#pragma once

#include <string>

namespace Hazel {
	class Shader {
	public:
		virtual ~Shader() = default;

		virtual void Bind() const {};
		virtual void Unbind() const {};

		static Shader* Create(const std::string& vectorSource, const std::string& fragmentSource);
	};
}