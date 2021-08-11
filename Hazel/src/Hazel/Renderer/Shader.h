#pragma once

#include <string>

#include <glm/glm.hpp>

namespace Hazel {
	class Shader {
	public:
		Shader(const std::string& vectorSource, const std::string& fragmentSource);
		~Shader();

		void Bind() const;
		void Unbind() const;

		void UploadUniformMat4(const std::string& name, const glm::mat4& matrix);
		void UploadUniformFloat4(const std::string& name, const glm::vec4& vec);
	private:
		uint32_t m_RendererID;
	};
}