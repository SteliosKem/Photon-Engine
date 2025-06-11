#pragma once
#include "glm/glm.hpp"
#include "Ray.h"
#include "Interval.h"

namespace Photon {
	struct HitInfo {
		bool hit;
		glm::vec3 point;
		glm::vec3 normal;
		double t;
		bool front_face;

		HitInfo(bool hit, const glm::vec3& point = {}, const glm::vec3& normal = {}, double t = 0)
			: hit{ hit }, point{ point }, normal{ normal }, t{ t } {}

		HitInfo(const Ray& ray, bool hit, const glm::vec3& point, const glm::vec3& normal, double t) 
			: hit{ hit }, point{ point }, normal{ normal }, t{ t } {
			set_face_normal(ray, normal);
		}

		void set_face_normal(const Ray& ray, const glm::vec3& outward_normal /* of unit length */) {
			front_face = glm::dot(ray.direction(), outward_normal) < 0;
			normal = front_face ? outward_normal : -outward_normal;
		}
	};

	class Object {
	public:
		virtual ~Object() = default;

		virtual HitInfo hit(const Ray& ray, const Interval& interval) const = 0;
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

		HitInfo hit(const Ray& ray, const Interval& interval) const override;
	private:
		glm::vec3 m_position{ 0.0f };
		float m_radius{ 1.0f };
	};
}