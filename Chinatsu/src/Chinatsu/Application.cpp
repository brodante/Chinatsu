#include "cnpch.h"
#include "Application.h"

#include "Chinatsu/Events/ApplicationEvent.h"

#include <GLFW/glfw3.h>

namespace Chinatsu {
	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{	
		while (m_Running)
		{
			glClearColor(1, 0, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			m_Window->OnUpdate();
		}
	}
}
// Specialize fmt::formatter for WindowResizeEvent outside the Chinatsu namespace
template <>
struct fmt::formatter<Chinatsu::WindowResizeEvent> : fmt::formatter<std::string>
{
	// This function tells fmt how to format the custom WindowResizeEvent
	template <typename FormatContext>
	auto format(const Chinatsu::WindowResizeEvent& event, FormatContext& ctx) const
	{
		return fmt::format_to(ctx.out(), "{} x {}", event.GetWidth(), event.GetHeight());
	}
};
