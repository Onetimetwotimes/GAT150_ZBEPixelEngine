#pragma once
#include "System.h"
#include <string>
#include "Resource.h"
#include <map>

namespace zbe {
	class ResourceManager : public System {
	public:
		virtual bool Init() override;
		virtual void Close() override;
		virtual void Update() override;

		
		template<typename T>
		T* Get(const std::string name, void* data);
	
	protected:
		std::map<std::string, zbe::Resource*> resources;
	};

	template<typename T>
	inline T* ResourceManager::Get(const std::string name, void* data) {
		T* source = dynamic_cast<T*>(resources[name]);

		if (source == nullptr) {
			source = new T;
			source->Create(name, data);
		}

		return source;
	}
}
