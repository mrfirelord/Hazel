#pragma once

#include <string>
#include <unordered_map>
#include <glm/glm.hpp>

namespace Hazel {
	class Shader {
	public:
		virtual ~Shader() = default;

		virtual void Bind() const {};
		virtual void Unbind() const {};

		virtual void SetInt(const std::string& name, int value) = 0;
		virtual void SetIntArray(const std::string& name, int* values, uint32_t count) = 0;

		virtual void SetFloat(const std::string& name, float value) = 0;
		virtual void SetFloat2(const std::string& name, const glm::vec2& vec) = 0;
		virtual void SetFloat3(const std::string& name, const glm::vec3& vec) = 0;
		virtual void SetFloat4(const std::string& name, const glm::vec4& vec) = 0;

		virtual void SetMat3(const std::string& name, const glm::mat3& matrix) = 0;
		virtual void SetMat4(const std::string& name, const glm::mat4& matrix) = 0;

		virtual const std::string GetName() const = 0;

		static Ref<Shader> Create(const std::string& filepath);
		static Ref<Shader> Create(const std::string& name, const std::string& vectorSource, const std::string& fragmentSource);
	};

	class ShaderLibrary {
	public:
		void Add(const Ref<Shader>& shader);
		void Add(const std::string& name, const Ref<Shader>& shader);
		Ref<Shader> Load(const std::string& filePath);
		Ref<Shader> Load(const std::string& name, const std::string& filePath);
		Ref<Shader> Get(const std::string& name);

		bool Exists(const std::string& name) const;
	private:
		// Shader refs by a file name where shader is located. filename doesn't contain path and extension
		std::unordered_map<std::string, Ref<Shader>> m_Shaders;
	};
}