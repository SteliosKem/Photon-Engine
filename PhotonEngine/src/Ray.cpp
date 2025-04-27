#include "Ray.h"

namespace Photon {
	float Ray::hit(const Sphere& sphere) const {
		// a, b, c are the terms of the quadratic equation of t that for some t return 0 if the ray intersects the sphere at least once
		float a = glm::dot(m_direction, m_direction);

		glm::vec3 origin_to_center = sphere.position() - m_origin;

		float b = -2.0f * glm::dot(m_direction, origin_to_center);
		float c = glm::dot(origin_to_center, origin_to_center) - sphere.radius() * sphere.radius();

		float discriminant = b * b - 4 * a * c;
		if (discriminant < 0) return -1;
		return -b - sqrtf(discriminant) / 2.0f * a;
	}
}