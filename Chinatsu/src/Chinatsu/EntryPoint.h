#pragma once

#ifdef CH_PLATFORM_WINDOWS

extern Chinatsu::Application* Chinatsu::CreateApplication();

int main(int argc, char** argv)
{
	auto app = Chinatsu::CreateApplication();
	app->Run();
	delete app;
}

#endif // CH_PLATFORM_WINDOWS