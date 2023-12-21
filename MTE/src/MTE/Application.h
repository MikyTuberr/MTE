#pragma once

#include "hzpch.h"
#include "Core.h"

#include "Window.h"
#include "MTE/Events/Event.h"
#include "MTE/LayerStack.h"
#include "MTE/Events/ApplicationEvent.h"

namespace MTE 
{
	class MTE_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);
	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;
	};

	// To be defined in CLIENT
	Application* CreateApplication();
}

