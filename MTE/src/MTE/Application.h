#pragma once

#include "hzpch.h"

#include "Core.h"
#include "Events/Event.h"

namespace MTE 
{
	class MTE_API Application
	{
	public:
		Application();

		virtual ~Application();

		void Run();
	};

	// To be defined in CLIENT
	Application* CreateApplication();
}

