#pragma once
#include <stdexcept>
#include <SDL.h>

namespace zbe {
	namespace Graphics {
		struct Color {
			~Color() {

			}

			float r, g, b, a;

			Color() {
				r = 0;
				g = 0;
				b = 0;
				a = 1;
			}

			Color(float r, float g, float b, float a = 1) {
				this->r = r;
				this->g = g;
				this->b = b;
				this->a = a;
			}

			void SetRGBA(float r, float g, float b, float a = 1) {
				this->r = r;
				this->g = g;
				this->b = b;
				this->a = a;
			}

#pragma region Array Accessors

			float& operator[](size_t index) {
				switch (index) {
				case 0:
					return r;
				case 1:
					return g;
				case 2:
					return b;
				case 3:
					return a;
				default:
					throw std::out_of_range("Max index: 3");
				}
			}
			const float& operator[](size_t index) const {
				switch (index) {
				case 0:
					return r;
				case 1:
					return g;
				case 2:
					return b;
				case 3:
					return a;
				default:
					throw std::out_of_range("Max index: 3");
				}
			}
#pragma endregion

#pragma region Arithmetic
			Color operator+(const Color& c) const {
				return Color(
					r + c.r,
					g + c.g,
					b + c.b,
					a + c.a);
			}
			Color operator-(const Color& c) const {
				return Color(
					r - c.r,
					g - c.g,
					b - c.b,
					a - c.a);
			}
			Color operator*(const Color& c) const {
				return Color(
					r * c.r,
					g * c.g,
					b * c.b,
					a * c.a);
			}
			Color operator/(const Color& c) const {
				return Color(
					r / c.r,
					g / c.g,
					b / c.b,
					a / c.a);
			}
			Color operator+(const float s) const {
				return Color(
					r + s,
					g + s,
					b + s,
					a + s);
			}
			Color operator-(const float s) const {
				return Color(
					r - s,
					g - s,
					b - s,
					a - s);
			}
			Color operator*(const float s) const {
				return Color(
					r * s,
					g * s,
					b * s,
					a * s);
			}
			Color operator/(const float s) const {
				return Color(
					r / s,
					g / s,
					b / s,
					a / s);
			}

			Color operator+=(const Color c) {
				r += c.r;
				g += c.g;
				b += c.b;
				a += c.a;
				return *this;
			}
			Color operator-=(const Color c) {
				r -= c.r;
				g -= c.g;
				b -= c.b;
				a -= c.a;
				return *this;
			}
			Color operator*=(const Color c) {
				r *= c.r;
				g *= c.g;
				b *= c.b;
				a *= c.a;
				return *this;
			}
			Color operator/=(const Color c) {
				r /= c.r;
				g /= c.g;
				b /= c.b;
				a /= c.a;
				return *this;
			}

#pragma endregion

			operator SDL_Color() const {
				SDL_Color color;
				Uint8 r_ = (Uint8)floorf(r * 255.0f);
				Uint8 g_ = (Uint8)floorf(g * 255.0f);
				Uint8 b_ = (Uint8)floorf(b * 255.0f);
				Uint8 a_ = (Uint8)floorf(a * 255.0f);
				
				color = { r_, g_, b_, a_ };
				return color;
			}
		};
	}
}