#pragma once
#include <math.h>
#include "Vector2.h"
namespace zbe {
	const double PI = 3.14159265359;
	const double TWO_PI = 6.28318530718;
	const double HALF_PI = 1.57079632679;

	template<typename T>
	inline T Clamp(T v, T _min, T _max) {
		return fmax(fmin(T, _max), _min);
	}

	template<typename T>
	inline T Lerp(T a, T b, float t) {
		t = Clamp(t, 0, 1);
		return (a + ((b - a) * t));
	}

}