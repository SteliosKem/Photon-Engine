#pragma once
#include "glm/glm.hpp"

namespace Photon {
	using Color = glm::vec3;

	inline uint8_t write_color_value(float value) {
		return value * 255.999;
	}
}