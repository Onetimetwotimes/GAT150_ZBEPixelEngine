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
		T* Get(const std::string name);
		template<typename T>
		bool Add(const std::string name, std::string filename, void* data = nullptr);

	protected:
		std::map<std::string, Resource*> resources;

		struct resource_not_found : public std::exception {
			resource_not_found(std::string w) {
				this->w = w.c_str();
			}
			const char* what() {
				return w;
			}
		private:
			const char* w;
		};
	};

	template<typename T>
	inline T* ResourceManager::Get(const std::string name) {
		T* source = dynamic_cast<T*>(resources[name]);

		if (source == nullptr)
			throw resource_not_found("No resource with name: " + name);

		return source;
	}
	template<typename T>
	inline bool ResourceManager::Add(const std::string name, const std::string filename, void* data) {
		if (resources[name] == nullptr) {
			T* resource = new T;
			if (!resource->Create(filename, data))
				return false;
			resources[name] = resource;
			return true;
		}
		else
			return false;
	}
}
