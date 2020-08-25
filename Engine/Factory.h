#pragma once
#include <functional>
#include <map>


namespace zbe {
	template<typename TBase, typename TKey>
	class Factory {
	public:
		using function_t = std::function<TBase* ()>;
		template<typename T = TBase>
		T* Create(TKey key);
		void Register(TKey key, function_t function);


	protected:
		std::map<TKey, function_t> registry;
	};


	template<typename TBase, typename TKey>
	template<typename T>
	inline T* Factory<TBase, TKey>::Create(TKey key) {
		T* object{ nullptr };

		auto iter = registry.find(key);

		if (iter != registry.end())
			object = dynamic_cast<T*>(iter->second());


		return object;
	}
	template<typename TBase, typename TKey>
	inline void Factory<TBase, TKey>::Register(TKey key, function_t function) {
		registry[key] = function;
	}
}