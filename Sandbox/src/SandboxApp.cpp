#include <MTE.h>

class ExampleLayer : public MTE::Layer
{
public:
	ExampleLayer() : Layer("Example") {}

	void OnUpdate() override
	{
		MTE_INFO("ExampleLayer::Update");
	}

	void OnEvent(MTE::Event& event) override
	{
		MTE_TRACE("{0}", event);
	}
};

class Sandbox : public MTE::Application 
{
public:
	Sandbox() 
	{
		PushLayer(new ExampleLayer());
	}

	~Sandbox() 
	{

	}
};

MTE::Application* MTE::CreateApplication()
{
	return new Sandbox();
}