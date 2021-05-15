#include "Oberon.h"

class Sandbox : public Oberon::Application
{
public:
	Sandbox() 
	{

	}

	~Sandbox()
	{

	}
};

Oberon::Application* Oberon::CreateApplication()
{
	return new Sandbox();
}