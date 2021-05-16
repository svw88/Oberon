#include <Oberon.h>
#include <Oberon/Core/EntryPoint.h>

#include "Sandbox2D.h"
#include "ExampleLayer.h"

class Sandbox : public Oberon::Application
{
public:
	Sandbox()
	{
		// PushLayer(new ExampleLayer());
		PushLayer(new Sandbox2D());
	}

	~Sandbox()
	{
	}
};

Oberon::Application* Oberon::CreateApplication()
{
	return new Sandbox();
}