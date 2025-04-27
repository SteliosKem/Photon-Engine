#include "Ray.h"

namespace Photon {
	bool Ray::hit(const Sphere& sphere) const {
		// a, b, c are the terms of the quadratic equation of t that for some t return 0 if the ray intersects the sphere at least once
		float a = glm::dot(m_direction, m_direction);

		glm::vec3 origin_to_center = sphere.position() - m_origin;

		float b = -2.0f * glm::dot(m_direction, origin_to_center);
		float c = glm::dot(origin_to_center, origin_to_center) - sphere.radius() * sphere.radius();

		float discriminant = b * b - 4 * a * c;
		return discriminant >= 0;
	}
}