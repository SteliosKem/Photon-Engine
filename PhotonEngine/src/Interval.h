#pragma once
#include <limits>

namespace Photon {
	const inline double inf = std::numeric_limits<double>::infinity();

	class Interval {
	public:
		Interval() : min{ +inf }, max{ -inf } {}
		Interval(double min, double max) : min{ min }, max{ max } {}

		double size() const { return max - min; }
		bool contains(double x) const { return x <= max && x >= min; }
		bool surrounds(double x) const { return x < max && x > min; }

		static const Interval empty;
		static const Interval universe;
	public:
		double min;
		double max;
	};

	inline const Interval Interval::empty = Interval();
	inline const Interval Interval::universe = Interval(-inf, +inf);
}