#include "Objects.h"

namespace Photon {
	HitInfo Sphere::hit(const Ray& ray, float ray_t_min, float ray_t_max) const {
		// a, b, c are the terms of the quadratic equation of t that for some t return 0 if the ray intersects the sphere at least once
		// h is b/(-2)
		float a = glm::dot(ray.direction(), ray.direction());

		glm::vec3 origin_to_center = m_position - ray.origin();

		float h = glm::dot(ray.direction(), origin_to_center);
		float c = glm::dot(origin_to_center, origin_to_center) - m_radius * m_radius;

		float discriminant = h * h - a * c;
		if (discriminant < 0) return { false };
		
		float discriminant_sqrt = sqrtf(discriminant);
		float root = (h - discriminant_sqrt) / a;
		if (root <= ray_t_min || root >= ray_t_max) {
			root = (h + discriminant) / a;
			if (root <= ray_t_min || root >= ray_t_max) return { false };
		}

		glm::vec3 point_hit = ray.get_point_at(root);

		return {
			true,
			point_hit,
			(point_hit - m_position) / m_radius,
			root
		};
	}
}