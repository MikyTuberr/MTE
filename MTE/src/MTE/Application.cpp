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
		AppTickEvent a;
		if (e.IsInCategory(EventCategoryApplication)) 
		{
			MTE_INFO(e);
			MTE_WARN(a);
		}
		if (e.IsInCategory(EventCategoryInput))
		{
			MTE_INFO(e);
			MTE_WARN(a);
		}
		
		while (true);
	}
}