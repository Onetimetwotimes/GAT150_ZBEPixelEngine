#pragma once
#include "Factory.h"
#include "Object.h"
#include "Singleton.h"

namespace zbe {
	class ObjectFactoryImp : public Factory<Object, std::string> {
	private:
	};
	class ObjectFactory : public Singleton<ObjectFactoryImp>{};
}