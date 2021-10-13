// HomeBrewBootloader.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <HomeBrew.h>

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <chrono>
#include <thread>


class BootLoader : public HomeBrew::Application {
public:
	BootLoader() {
		EngineSeeder();
		//SensorData();
	}
	~BootLoader() {}

	void SensorData() {
		//Simulate real life sensors that can trigger at any point in time
		std::srand(std::time(NULL));
		int trigger = std::rand() % 100 + 1;
		int sensor_trigger;
		while (b_running) {
			sensor_trigger = std::rand() % 100 + 1;
			if (sensor_trigger == trigger) {
				//HomeBrew::ObjectManager::GetInstance()->GetObjects().at(0)->Run();
			}
			//check every 5ms
			std::this_thread::sleep_for(std::chrono::milliseconds(5));
		}
	}

	void EngineSeeder() {

		HomeBrew::Light* light1 = new HomeBrew::Light("light1");
		HomeBrew::Light* light2 = new HomeBrew::Light("light2");
		HomeBrew::Light* light3 = new HomeBrew::Light("light3");

		HomeBrew::Heater* heater = new HomeBrew::Heater();
		HomeBrew::Sensor* sensor = new HomeBrew::Sensor("sensor light 1-3");
		HomeBrew::Sensor* sensor_heater = new HomeBrew::Sensor("sensor heater");


		std::vector<HomeBrew::Component*> lights{
			light1, light2, light3
		};
		HomeBrew::ObjectManager::GetInstance()->AddObject(sensor, lights);
		HomeBrew::ObjectManager::GetInstance()->AddObject(sensor_heater, heater);

		GetAllLights(sensor);

	}

	void GetAllLights(HomeBrew::Sensor* p_sensor) {
		for (auto l : *HomeBrew::ObjectManager::GetInstance()->GetT<HomeBrew::Light*>(p_sensor)) {
			std::cout << (*l).GetName();
		}
	}

private:
	bool b_running = true;
};

HomeBrew::Application* HomeBrew::CreateApplication() {
	return new BootLoader();
}
