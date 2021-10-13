#include "pch.h"
#include "ObjectManager.h"

void HomeBrew::ObjectManager::AddObject(Sensor* p_sensor, Component* p_compoment) {
	try {
		auto it = mpp_objects.find(p_sensor);
		if (it != mpp_objects.end())
			mpp_objects[p_sensor].push_back(p_compoment);
		else
			mpp_objects.insert(std::pair<Sensor*, std::vector<Component*>>(p_sensor, { p_compoment }));
	}
	catch (const std::exception& ex) {
		std::cerr << "exception while adding object " << ex.what();
	}
}

void HomeBrew::ObjectManager::AddObject(Sensor* p_sensor, std::vector<Component*> &p_components) {
	try {
		auto it = mpp_objects.find(p_sensor);
		if (it != mpp_objects.end()) {
			mpp_objects[p_sensor].reserve(mpp_objects[p_sensor].size() + p_components.size());
			mpp_objects[p_sensor].insert(mpp_objects[p_sensor].end(), p_components.begin(), p_components.end());
		} 
		else
			mpp_objects.insert(std::pair<Sensor*, std::vector<Component*>>(p_sensor, p_components));
	}
	catch (const std::exception& ex) {
		std::cerr << "exception while adding object " << ex.what();
	}
}


