#pragma once

#ifdef CH_PLATFORM_WINDOWS

extern Chinatsu::Application* Chinatsu::CreateApplication();

int main(int argc, char** argv)
{
	Chinatsu::Log::Init();
	CH_CORE_WARN("Initialized Log!");
	int x = 23;
	CH_INFO("Hello! Var={0}", x);

	auto app = Chinatsu::CreateApplication();
	app->Run();
	delete app;
}

#endif // CH_PLATFORM_WINDOWS