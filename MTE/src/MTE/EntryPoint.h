#pragma once

#ifdef MTE_PLATFORM_WINDOWS

extern MTE::Application* MTE::CreateApplication();

int main(int argc, char** argv) 
{
	MTE::Log::Init();
	MTE_CORE_WARN("Siema!");
	MTE_INFO("cos!");

	auto app = MTE::CreateApplication();
	app->Run();
	delete app;
}

#endif