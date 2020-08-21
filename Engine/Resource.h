#pragma once
#include <string>

namespace zbe {
	class Resource {
	public:
		virtual bool Create(const std::string filename, void* data = nullptr) = 0;
		virtual void Destroy() = 0;


	};
}