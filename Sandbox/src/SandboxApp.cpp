#include <hzpch.h>
#include <Hazel.h>

class ExampleLayer : public Hazel::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}

	void OnUpdate() override
	{
		HZ_INFO("ExampleLayer::Update");
		if (Hazel::Input::isKeyPressed(HZ_KEY_TAB))
			HZ_TRACE("TAB IS PRESSED");
	}

	void OnEvent(Hazel::Event& event) override
	{
		
	}

};

class Sanbox : public Hazel::Application {
public:
	Sanbox() {
		PushLayer(new ExampleLayer());
		PushOverlay(new Hazel::ImGuiLayer());
	}

	~Sanbox() {

	}
};

Hazel::Application* Hazel::CreateApplication() {
	return new Sanbox();
}