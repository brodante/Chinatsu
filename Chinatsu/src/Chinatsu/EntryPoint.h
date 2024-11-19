#pragma once

#ifdef CN_PLATFORM_WINDOWS

extern Chinatsu::Application* Chinatsu::CreateApplication();

int main(int argc, char** argv)
{
	Chinatsu::Log::Init();
	CN_CORE_WARN("Initialized Log!");
	int x = 23;
	CN_INFO("Hello! Var={0}", x);

	auto app = Chinatsu::CreateApplication();
	app->Run();
	delete app;
}

#endif // CN_PLATFORM_WINDOWS