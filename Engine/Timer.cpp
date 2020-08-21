#include "pch.h"
#include "Timer.h"

namespace zbe {
	void Timer::Reset() {
		startT = time::now();
	}

	Timer::time::rep zbe::Timer::ElapsedTicks() {
		return (time::now() - startT).count();
	}

	Timer::time::rep zbe::Timer::TicksPerSecond() {
		return deltaTime::period::den;
	}

	double Timer::ElapsedSeconds() {
		return ElapsedSeconds() / static_cast<double>(TicksPerSecond());
	}
	void FrameTime::Tick() {
		dT = ElapsedSeconds();
		Reset();
	}
}