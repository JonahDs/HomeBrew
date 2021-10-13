#pragma once
#include "Abstraction.h"
#include "Managers/ObjectManager.h"

namespace HomeBrew {
	class Application {
	public:
		Application();
		virtual ~Application();
		void Run();
	private:
		bool b_running = true;
		ObjectManager object_manager;
		static sPtr<Application> p_instance;
	};



	Application* CreateApplication();
}