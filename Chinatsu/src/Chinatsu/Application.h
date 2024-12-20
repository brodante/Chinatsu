#pragma once

#include "Core.h"
#include "Events/Event.h"
#include "Chinatsu/Window.h"

namespace Chinatsu {
	class CHINATSU_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);
	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	};
	// To be defined in CLIENT
	Application* CreateApplication();
}