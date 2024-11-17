#pragma once

#include "Core.h"

namespace Chinatsu {
	class CHINATSU_API Application
	{
	public:
		Application();
		virtual ~Application();
		void Run();
	};
	// To be defined in CLIENT
	Application* CreateApplication();
}