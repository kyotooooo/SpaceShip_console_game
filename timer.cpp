#include "timer.h"
#include <chrono>
#include <iostream>

Timer::Timer() : elapsedTime(clock_t::now()) {}


int Timer::elapsed() {
	return std::chrono::duration_cast<second_t>(clock_t::now() - elapsedTime).count();
}

