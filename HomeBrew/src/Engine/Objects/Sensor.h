#pragma once
#include <string>
namespace HomeBrew {
	class Sensor {
	public:
		Sensor() = delete;
		Sensor(std::string p_name) : name(p_name) {};
	private:
		std::string name;
	};
}