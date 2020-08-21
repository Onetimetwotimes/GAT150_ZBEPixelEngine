#pragma once
#include <chrono>

namespace zbe {
	class Timer {
	public:
		using time = std::chrono::high_resolution_clock;
		using deltaTime = std::chrono::duration<time::rep, std::nano>;

		Timer() : startT(time::now()) {};
		void Reset();

		time::rep ElapsedTicks();
		time::rep TicksPerSecond();

		double ElapsedSeconds();

	protected:
		time::time_point startT;
	};

	class FrameTime : public Timer{
	public:
		void Tick();
		float DeltaTime() { dT; }

	private:
		float dT{ 0 };
	};
}