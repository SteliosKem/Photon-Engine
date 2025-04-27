#pragma once
#include "Objects.h"
#include "glm/glm.hpp"

namespace Photon {
	class Ray {
	public:
		Ray() {}
		~Ray() {}

		Ray(const glm::vec3& origin, const glm::vec3& direction) : m_origin{ origin }, m_direction{ direction } { m_direction = glm::normalize(m_direction); }

		const glm::vec3& origin() const { return m_origin; }
		const glm::vec3& direction() const { return m_direction; }

		glm::vec3 get_point_at(float x) const {
			return m_origin + (x * m_direction);
		}

		float hit(const Sphere& sphere) const;
	private:
		glm::vec3 m_origin{ 0.0f, 0.0f, 0.0f };
		glm::vec3 m_direction{ 1.0f, 1.0f, 1.0f };
	};
}