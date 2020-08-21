#pragma once
namespace zbe {
	class System {
	public:
		virtual bool Init() = 0;
		virtual void Close() = 0;
		virtual void Update() = 0;
	};
}