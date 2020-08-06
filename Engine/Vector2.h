#pragma once
#include <cmath>

namespace zbe {
	namespace math {

		struct Vector2 {
			Vector2() {
				x = 0;
				y = 0;
			}
			Vector2(int x, int y) {
				this->x = (float)x;
				this->y = (float)y;
			}
			Vector2(int p) {
				this->x = (float)p;
				this->y = (float)p;
			}
			Vector2(float x, float y) {
				this->x = x;
				this->y = y;
			}
			Vector2(float p) {
				this->x = p;
				this->y = p;
			}


#pragma region Arithmetic

			Vector2 operator+(const Vector2 v) const {
				return Vector2(v.x + x,
					          v.y + y);
			}
			Vector2 operator-(const Vector2 v) const {
				return Vector2(v.x - x,
					          v.y - y);
			}
			Vector2 operator*(const Vector2 v) const {
				return Vector2(v.x * x,
					          v.y * y);
			}
			Vector2 operator/(const Vector2 v) const {
				return Vector2(v.x / x,
					          v.y / y);
			}
			Vector2 operator+(const float p) const {
				return Vector2(p + x,
					          p + y);
			}
			Vector2 operator-(const float p) const {
				return Vector2(p - x,
					          p - y);
			}
			Vector2 operator*(const float p) const {
				return Vector2(p * x,
					          p * y);
			}
			Vector2 operator/(const float p) const {
				return Vector2(x / p,
					          y / p);
			}

			Vector2 operator+=(const Vector2& v) {
				x += v.x;
				y += v.y;
				return *this;
			}
			Vector2 operator-=(const Vector2& v) {
				x -= v.x;
				y -= v.y;
				return *this;
			}
			Vector2 operator*=(const Vector2& v) {
				x *= v.x;
				y *= v.y;
				return *this;
			}
			Vector2 operator/=(const Vector2& v) {
				x /= v.x;
				y /= v.y;
				return *this;
			}
			Vector2 operator+=(const float p) {
				x += p;
				y += p;
				return *this;
			}
			Vector2 operator-=(const float p) {
				x -= p;
				y -= p;
				return *this;
			}
			Vector2 operator*=(const float p) {
				x *= p;
				y *= p;
				return *this;
			}
			Vector2 operator/=(const float p) {
				x /= p;
				y /= p;
				return *this;
			}

#pragma endregion

#pragma region Comparison
			bool operator<(Vector2 o) {
				return Length() < o.Length();
			}
			bool operator>(Vector2 o) {
				return Length() > o.Length();
			}
			bool operator==(Vector2 o) {
				return Length() == o.Length();
			}
#pragma endregion

			float Length() const {
				return hypot(x, y);
			}

			static float Distance(const Vector2 a, const Vector2 b) {
				return (a - b).Length();

			}

			static Vector2 Normalise(const Vector2& v) {
				return Vector2(v / v.Length());
			}
				 
			static Vector2 Rotate(const Vector2& v, float rad) {
				return Vector2(
					v.x * std::cosf(rad) - v.y * sinf(rad),
					v.x * sinf(rad) + v.y * cosf(rad)
				);
			}

			float rotation() {
				Vector2 normal = Vector2::Normalise(*this);
				return std::atan2(normal.y, normal.x);
			}

			static Vector2 Min(const Vector2& a, const Vector2& b) {
				return Vector2(a.Length() < b.Length() ? a : b);
			}
			static Vector2 Max(const Vector2& a, const Vector2& b) {
				return Vector2(a.Length() > b.Length() ? a : b);
			}


			float x, y;
		};
	}
}