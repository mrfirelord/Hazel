/*
#include <hzpch.h>

#include "Sandbox2D.h"

#include "imgui/imgui.h"
#include <glm/gtc/type_ptr.hpp>

void Sandbox2D::OnAttach() {
    m_VertexArray = Hazel::VertexArray::Create();

    float vertices[3 * 7] = {
        -0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 1.0f, 1.0f,
        0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f,
        0.0f,  0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f,
    };

    Hazel::Ref<Hazel::VertexBuffer> vertexBuffer;
    vertexBuffer = Hazel::VertexBuffer::Create(vertices, sizeof(vertices));
    Hazel::BufferLayout layout = {
        { Hazel::ShaderDataType::Float3, "a_Position" },
        { Hazel::ShaderDataType::Float4, "a_Color" }
    };
    vertexBuffer->SetLayout(layout);
    m_VertexArray->AddVertexBuffer(vertexBuffer);

    uint32_t indices[3] = { 0, 1, 2 };
    Hazel::Ref<Hazel::IndexBuffer> indexBuffer;
    indexBuffer = Hazel::IndexBuffer::Create(indices, sizeof(indices) / sizeof(uint32_t));
    m_VertexArray->SetIndexBuffer(indexBuffer);

    m_SquareVA = Hazel::VertexArray::Create();

    float squareVertices[5 * 4] = {
        -0.5f, -0.5f, 0.0f, 0.0,  0.0,
        0.5f, -0.5f, 0.0f, 1.0f, 0.0,
        0.5f,  0.5f, 0.0f, 1.0f, 1.0f,
        -0.5f,  0.5f, 0.0f, 0.0,  1.0f
    };

    Hazel::Ref<Hazel::VertexBuffer> squareVB;
    squareVB.reset(Hazel::VertexBuffer::Create(squareVertices, sizeof(squareVertices)));
    squareVB->SetLayout({
        { Hazel::ShaderDataType::Float3, "a_Position" },
        { Hazel::ShaderDataType::Float2, "a_TexCoord" },
        });
    m_SquareVA->AddVertexBuffer(squareVB);

    uint32_t squareIndices[6] = { 0, 1, 2, 2, 3, 0 };
    Hazel::Ref<Hazel::IndexBuffer> squareIB;
    squareIB.reset(Hazel::IndexBuffer::Create(squareIndices, sizeof(squareIndices) / sizeof(uint32_t)));
    m_SquareVA->SetIndexBuffer(squareIB);

    std::string vertexSrc = R"(
                #version 330 core

                layout(location=0) in vec3 a_Position;
                layout(location=1) in vec4 a_Color;

                uniform mat4 u_ViewProjection;
                uniform mat4 u_Transform;

                out vec3 v_Position;
                out vec4 v_Color;

                void main() {
                    v_Position = a_Position;
                    v_Color = a_Color;
                    gl_Position = u_ViewProjection * u_Transform * vec4(a_Position, 1.0);
                }
            )";

    std::string fragmentSrc = R"(
                #version 330 core

                layout(location=0) out vec4 color;

                in vec3 v_Position;
                in vec4 v_Color;

                void main() {
                    color = vec4(v_Position, 1.0);
                    color = v_Color;
                }
            )";

    m_Shader = Hazel::Shader::Create("VertexPosColor", vertexSrc, fragmentSrc);

    std::string flatColorShaderVertexSrc = R"(
                #version 330 core
                
                layout(location = 0) in vec3 a_Position;

                uniform mat4 u_ViewProjection;
                uniform mat4 u_Transform;

                out vec3 v_Position;

                void main()
                {
                    v_Position = a_Position;
                    gl_Position = u_ViewProjection * u_Transform * vec4(a_Position, 1.0);	
                }
            )";

    std::string flatColorShaderFragmentSrc = R"(
                #version 330 core
                
                layout(location = 0) out vec4 color;
                in vec3 v_Position;

                uniform vec3 u_Color;

                void main()
                {
                    color = vec4(u_Color, 1.0);
                }
            )";

    m_FlatColor = Hazel::Shader::Create("FlatColor", flatColorShaderVertexSrc, flatColorShaderFragmentSrc);

    auto textureShader = m_ShaderLibrary.Load("assets/shaders/Texture.glsl");

    m_Texture = Hazel::Texture2D::Create("assets/textures/Checkerboard.png");
    m_ChernoLogoTexture = Hazel::Texture2D::Create("assets/textures/ChernoLogo.png");

    std::dynamic_pointer_cast<Hazel::OpenGLShader>(textureShader)->Bind();
    std::dynamic_pointer_cast<Hazel::OpenGLShader>(textureShader)->UploadUniformInt("u_Texture", 0);
}

void Sandbox2D::OnDetach() {
}

void Sandbox2D::OnUpdate(Hazel::Timestep timestep) {
	m_CameraController.OnUpdate(timestep);
}

void Sandbox2D::OnEvent(Hazel::Event& event) {
	m_CameraController.OnEvent(event);
}

void Sandbox2D::OnImGuiRender() {
	ImGui::Begin("Settings");
	ImGui::ColorEdit3("Square Color", glm::value_ptr(m_SquareColor));
	ImGui::End();
}
*/