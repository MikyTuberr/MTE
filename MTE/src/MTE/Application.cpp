#include "Application.h"

#include "MTE/Events/ApplicationEvent.h"
#include "MTE/Log.h"

namespace MTE 
{
	Application::Application() 
	{

	}

	Application::~Application() 
	{

	}

	void Application::Run() 
	{
		WindowResizeEvent e(1200, 720);
		if (e.IsInCategory(EventCategoryApplication)) 
		{
			MTE_INFO(e);
		}
		if (e.IsInCategory(EventCategoryInput))
		{
			MTE_INFO(e);
		}

		MTE_TRACE("cos");
		
		while (true);
	}
}