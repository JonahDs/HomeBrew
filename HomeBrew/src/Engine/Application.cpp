#include "pch.h"
#include "Application.h"

namespace HomeBrew {

	Application::Application(): object_manager() {

	}

	Application::~Application() {
	}



	void Application::Run() {
		while (b_running) {
			/*for (auto p_object : object_manager.GetInstance()->GetObjects()) {
				std::cout << "got 1 light named: " << p_object->GetName();
			}*/
		}
	}

}

