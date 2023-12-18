#pragma once

#include "hzpch.h"

#include "MTE/Core.h"
#include "MTE/Events/Event.h"

namespace MTE {

	struct WindowProps 
	{
		std::string Title;
		unsigned int Width, Height;

		WindowProps(const std::string& title = "MTE Engine",
			unsigned int width = 1280,
			unsigned height = 720)
			: Title(title), Width(width), Height(height) {}
	};

	// Interface representing a desktop system based Window
	class MTE_API Window
	{
	public:
		using EventCallbackFn = std::function<void(Event&)>;

		virtual ~Window() = default;

		virtual void OnUpdate() = 0;

		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;

		// Window attributes
		virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSync() const = 0;

		static Window* Create(const WindowProps& props = WindowProps());
	};
}