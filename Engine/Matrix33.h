#pragma once
#include "Vector2.h"
#include <cmath>

namespace zbe {
	namespace math {
		struct  Matrix33
		{
			Matrix33() {  };			
			
			void Scale(float s) {
				m[0][0] = s; m[1][0] = 0; m[2][0] = 0;
				m[0][1] = 0; m[1][1] = s; m[2][1] = 0;
				m[0][2] = 0; m[1][2] = 0; m[2][2] = 1;
			}

			void Scale(float sX, float sY) {
				m[0][0] = sX; m[1][0] = 0; m[2][0] = 0;
				m[0][1] = 0; m[1][1] = sY; m[2][1] = 0;
				m[0][2] = 0; m[1][2] = 0; m[2][2] = 1;
			}

			void Scale(const zbe::math::Vector2& v) {
				m[0][0] = v.x;  m[1][0] =   0;  m[2][0] = 0;
				m[0][1] =   0;  m[1][1] = v.y;  m[2][1] = 0;
				m[0][2] =   0;  m[1][2] =   0;  m[2][2] = 1;
			}

			void Rotate(float rotation) {
				m[0][0] =  std::cos(rotation); m[1][0] = std::sin(rotation); m[2][0] = 0;
				m[0][1] = -std::sin(rotation); m[1][1] = std::cos(rotation); m[2][1] = 0;
				m[0][2] = 0;                   m[1][2] = 0;                  m[2][2] = 1;
			}

			void SetIdentity() {
				m[0][0] = 1;  m[1][0] = 0;  m[2][0] = 0;
				m[0][1] = 0;  m[1][1] = 1;  m[2][1] = 0;
				m[0][2] = 0;  m[1][2] = 0;  m[2][2] = 1;
			}

			Matrix33 operator*(const Matrix33& o) {
				Matrix33 result;

				result.m[0][0] = m[0][0] * o.m[0][0] + m[1][0] * o.m[0][1] + m[2][0] * o.m[0][2];
				result.m[0][1] = m[0][1] * o.m[0][0] + m[1][1] * o.m[0][1] + m[2][1] * o.m[0][2];
				result.m[0][2] = m[0][2] * o.m[0][0] + m[1][2] * o.m[0][1] + m[2][2] * o.m[0][2];
				
				result.m[1][0] = m[0][0] * o.m[1][0] + m[1][0] * o.m[1][1] + m[2][0] * o.m[1][2];
				result.m[1][1] = m[0][1] * o.m[1][0] + m[1][1] * o.m[1][1] + m[2][1] * o.m[1][2];
				result.m[1][2] = m[0][2] * o.m[1][0] + m[1][2] * o.m[1][1] + m[2][2] * o.m[1][2];
				
				result.m[2][0] = m[0][0] * o.m[2][0] + m[1][0] * o.m[2][1] + m[2][0] * o.m[2][2];
				result.m[2][1] = m[0][1] * o.m[2][0] + m[1][1] * o.m[2][1] + m[2][1] * o.m[2][2];
				result.m[2][2] = m[0][2] * o.m[2][0] + m[1][2] * o.m[2][1] + m[2][2] * o.m[2][2];


				return result;
			}

			zbe::math::Vector2 operator*(const zbe::math::Vector2& v) {
				return zbe::math::Vector2{
					v.x * m[0][0] + v.y * m[0][1] + m[0][2],
					v.x * m[1][0] + v.y * m[1][1] + m[1][2]
				};
			}

			friend zbe::math::Vector2 operator*(const zbe::math::Vector2& v, const Matrix33& _m) {
				return zbe::math::Vector2{
					v.x * _m.m[0][0] + v.y * _m.m[0][1] + _m.m[0][2],
					v.x * _m.m[1][0] + v.y * _m.m[1][1] + _m.m[1][2]
				};
			}

			float m[3][3];
		};
	}
}