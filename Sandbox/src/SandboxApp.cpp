#include <Chinatsu.h>


class ExampleLayer : public Chinatsu::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}

	void OnUpdate() override
	{
		CN_INFO("ExampleLayer::Update");
	}

	void OnEvent(Chinatsu::Event& event) override
	{
		CN_TRACE("{0}", event);
	}
};

class Sandbox : public Chinatsu::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
	}
	~Sandbox()
	{
	}
};

Chinatsu::Application* Chinatsu::CreateApplication()
{
	return new Sandbox();
}