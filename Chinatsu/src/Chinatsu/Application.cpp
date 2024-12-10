#include "Application.h"

#include "Chinatsu/Events/ApplicationEvent.h"
#include "Chinatsu/Log.h"

namespace Chinatsu {
	Application::Application()
	{
	}
	Application::~Application()
	{
	}
	void Application::Run()
	{	
		WindowResizeEvent e(1280, 720);
		if (e.IsInCategory(EventCategoryApplication))
		{
			CN_TRACE(e);
		}
		if (e.IsInCategory(EventCategoryInput))
		{
			CN_TRACE(e);
		}
		while (true);
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
