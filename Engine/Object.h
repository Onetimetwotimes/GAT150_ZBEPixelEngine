#pragma once
#include "json.h"

namespace zbe {
	class Object {
	public:
		virtual void Create(void* data) = 0;
		virtual void Destroy() = 0;

		virtual void Read(const rapidjson::Value& value) = 0;
	};
}