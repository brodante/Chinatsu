#include "cnpch.h"
#include "Application.h"

#include "Chinatsu/Events/ApplicationEvent.h"

#include <GLFW/glfw3.h>

namespace Chinatsu {

#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)

	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(BIND_EVENT_FN(OnEvent)); // Bind the OnEvent function to the Application class
	}

	Application::~Application()
	{
	}

	void Application::PushLayer(Layer* layer)
	{
		m_LayerStack.PushLayer(layer);
	}

	void Application::PushOverlay(Layer* layer)
	{
		m_LayerStack.PushOverlay(layer);
	}

	void Application::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));

		//CN_CORE_TRACE("{0}", e);

		for (auto it = m_LayerStack.end(); it != m_LayerStack.begin();)
		{
			(*--it)->OnEvent(e);
			if (e.Handled)
				break;
		}
	}

	void Application::Run()
	{	
		while (m_Running)
		{
			glClearColor(0.5f, 0.0f, 0.5f, 1.0f); // Dark purple
			glClear(GL_COLOR_BUFFER_BIT);

			for (Layer* layer : m_LayerStack)
				layer->OnUpdate();

			m_Window->OnUpdate();
		}
	}

	bool Application::OnWindowClose(WindowCloseEvent& e)
	{
		m_Running = false;
		return true;
	}

}


// Specialize fmt::formatter for WindowResizeEvent outside the Chinatsu namespace
//template <>
//struct fmt::formatter<Chinatsu::WindowResizeEvent> : fmt::formatter<std::string>
//{
//	// This function tells fmt how to format the custom WindowResizeEvent
//	template <typename FormatContext>
//	auto format(const Chinatsu::WindowResizeEvent& event, FormatContext& ctx) const
//	{
//		return fmt::format_to(ctx.out(), "{} x {}", event.GetWidth(), event.GetHeight());
//	}
//};


// Base Event class
//class Event {
//public:
//	virtual std::string ToString() const = 0;
//};
//
//// Example of a derived event class
//class WindowResizeEvent : public Event {
//public:
//	WindowResizeEvent(int width, int height)
//		: m_Width(width), m_Height(height) {
//	}
//
//	int GetWidth() const { return m_Width; }
//	int GetHeight() const { return m_Height; }
//
//	std::string ToString() const override {
//		return fmt::format("{} x {}", m_Width, m_Height);
//	}
//
//private:
//	int m_Width, m_Height;
//};
//
//// Specialize fmt::formatter for the base Event class
//template <>
//struct fmt::formatter<Event> : fmt::formatter<std::string>
//{
//	// This function tells fmt how to format the custom Event
//	template <typename FormatContext>
//	auto format(const Event& event, FormatContext& ctx) const
//	{
//		return fmt::format_to(ctx.out(), "{}", event.ToString());
//	}
//};