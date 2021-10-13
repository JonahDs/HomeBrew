#pragma once
#include <vector>
#include <map>

#include "Engine/Singleton.h"
#include "Engine/Objects/Component.h"
#include "Engine/Objects/Sensor.h"

namespace HomeBrew {
	class ObjectManager : public Singleton<ObjectManager> {
	public:
		void AddObject(Sensor*, Component*);

		void AddObject(Sensor*, std::vector<Component*> &);

		template<class T>
		std::vector<T>* GetT(Sensor*);
	private:
		std::map<Sensor*, std::vector<Component*>> mpp_objects;
	};

	template<class T>
	inline std::vector<T>* ObjectManager::GetT(Sensor* p_sensor) {
		auto it = mpp_objects.find(p_sensor);
		if (it != mpp_objects.end() && (typeid(T) == typeid(*mpp_objects[p_sensor][0]))) {
			return reinterpret_cast<std::vector<T>*>(&mpp_objects[p_sensor]);
		}
		
	}

}