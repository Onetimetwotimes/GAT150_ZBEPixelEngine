#pragma once
#include "Vector2.h"
#include <cmath>

namespace zbe {
	struct Matrix22 {
		Matrix22() {  };
		Matrix22(const zbe::math::Vector2& column1, const zbe::math::Vector2& column2) {
			m[0][0] = column1.x; m[1][0] = column2.x;
			m[0][1] = column1.y; m[1][1] = column2.y;
		}
		void Scale(float s) {
			m[0][0] = s; m[1][0] = 0;
			m[0][1] = 0; m[1][1] = s;
		}

		void Scale(float sX, float sY) {
			m[0][0] = sX; m[1][0] = 0;
			m[0][1] = 0; m[1][1] = sY;
		}

		void Scale(const zbe::math::Vector2& v) {
			m[0][0] = v.x; m[1][0] = 0;
			m[0][1] = 0; m[1][1] = v.y;
		}

		void Rotate(float rotation) {
			m[0][0] =  std::cos(rotation); m[1][0] = std::sin(rotation);
			m[0][1] = -std::sin(rotation); m[1][1] = std::cos(rotation);
		}

		void SetIdentity() {
			m[0][0] = 1; m[1][0] = 0;
			m[0][1] = 0; m[1][1] = 1;
		}

		Matrix22 operator*(const Matrix22& o) {
			Matrix22 result;

			result.m[0][0] = m[0][0] * o.m[0][0] + m[1][0] * o.m[0][1];
			result.m[1][0] = m[0][0] * o.m[1][0] + m[1][0] * o.m[1][1];
			result.m[0][1] = m[0][1] * o.m[0][0] + m[1][1] * o.m[0][1];
			result.m[1][1] = m[0][1] * o.m[1][0] + m[1][1] * o.m[1][1];

			return result;
		}

		zbe::math::Vector2 operator*(const zbe::math::Vector2& v) {
			return zbe::math::Vector2{
				v.x * m[0][0] + v.y * m[0][1],
				v.x * m[1][0] + v.y * m[1][1]
			};
		}

		friend zbe::math::Vector2 operator*(const zbe::math::Vector2& v, const Matrix22& _m) {
			return zbe::math::Vector2{
				v.x * _m.m[0][0] + v.y * _m.m[0][1],
				v.x * _m.m[1][0] + v.y * _m.m[1][1]
			};
		}

		float m[2][2];
	};
}