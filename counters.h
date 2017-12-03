#ifndef COUNTERS
#define COUNTERS

#include <simlib.h>

class YearCounter : public Process {
public:
	void Behavior() override;
};

class WeekCounter : public Process {
public:
	void Behavior() override;
};

class BreakCounter : public Process {
public:
	void Behavior() override;
};


/*
 * Counters will singal program using Facilities.
 */

extern Facility summer;

#endif //COUNTERS
