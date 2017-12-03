#include "counters.h"
#include "constants.h"
#include "debug.h"

Facility summer("Summer");

Facility weekend("Weekend");

Facility start_break("Start break");

Facility end_break("End break");

void YearCounter::Behavior() {
	Priority = DEFAULT_COUNTER_PRIORITY;
	echo("Staring season counter");
	while (true){
		// starting in another other season than summer
		Seize(summer);
		Wait(OTHER_SEASONS_TIME);

		echo("It summer");
		Release(summer);
		Wait(SUMMER_TIME);
		echo("It's winter");
		echo(Time);
	}
}

void WeekCounter::Behavior() {
	Priority = DEFAULT_COUNTER_PRIORITY;
	echo("Starting weekend counter");

	while (true){
		Seize(weekend);
		echo("It's a week");
		Wait(WEEK_DAYS);

		echo("Weekend starting, party up!!!")
		Release(weekend);
		Wait(WEEKEND_DAYS);
	}
}

void BreakCounter::Behavior() {
	Priority = DEFAULT_COUNTER_PRIORITY;
	echo("Starting shift counter");

	Seize(start_break);
	Seize(end_break);

	while (true) {
		echo("Starting new shift");
		// At this point we have both breaks
		Wait(WORKING_TIME);

		// First short break is comming
		Release(start_break);
		echo("Starting short break");
		Wait(SHORT_BREAK);
		Seize(start_break);

		// end of first break
		Release(end_break);
		Priority = 0;
		Seize(end_break);

		Wait(WORKING_TIME);

		// First short break is comming
		Release(start_break);
		echo("Starting long break");
		Wait(LONG_BREAK);
		Seize(start_break);

		// end of first break
		Release(end_break);
		Priority = 0;
		Seize(end_break);

		Wait(WORKING_TIME);
	}

}

