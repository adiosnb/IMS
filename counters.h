#ifndef COUNTERS
#define COUNTERS

#include <simlib.h>

class YearCounter : public Process {
	void Behavior();
};

class WeekCounter : public Process {
	void Behavior();
};

class BreakCounter : public Process {
	void Behavior();
};


/*
 * Counters will singal program using Facilities.
 */

Facility summer;

#endif //COUNTERS
