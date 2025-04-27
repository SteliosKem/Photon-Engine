#pragma once
#include "glm/glm.hpp"
#include "Ray.h"

namespace Photon {
	struct HitInfo {
		bool hit;
		glm::vec3 point;
		glm::vec3 normal;
		double t;
	};

	class Object {
	public:
		virtual ~Object() = default;

		virtual HitInfo hit(const Ray& ray, float ray_t_min, float ray_t_max) const = 0;
	};

	class Sphere : public Object {
	public:
		Sphere() {}
		~Sphere() {}

		Sphere(const glm::vec3& position, float radius) : m_position{ position }, m_radius{ radius } {}

		const glm::vec3& position() const { return m_position; }
		float radius() const { return m_radius; }

		glm::vec3& position() { return m_position; }
		float& radius() { return m_radius; }

		HitInfo hit(const Ray& ray, float ray_t_min, float ray_t_max) const override;
	private:
		glm::vec3 m_position{ 0.0f };
		float m_radius{ 1.0f };
	};
}