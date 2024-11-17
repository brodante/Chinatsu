#include <Chinatsu.h>


class Sandbox : public Chinatsu::Application
{
public:
	Sandbox()
	{
	}
	~Sandbox()
	{
	}
};

Chinatsu::Application* Chinatsu::CreateApplication()
{
	return new Sandbox();
}