#pragma once
#include <iostream>
#include <string>

#include "Component.h"

namespace HomeBrew {
	class Light : public Component {
	public:
		Light() {};
		Light(std::string p_lightname) {
			light_name = p_lightname;
		}

		void Toggle() {
			state = !state;
			std::cout << "light is turned on/off";
		}

		std::string GetName() const { return light_name; }
	private:
		std::string light_name;
		bool state;
	};

}
