#include "counters.h"
#include "constants.h"
#include "debug.h"

Facility summer("Summer");

void YearCounter::Behavior() {
	Seize(summer);
	Priority = 1;
	echo("Staring season counter");
	while (true){
		// starting in another other season than summer
		Wait(OTHER_SEASONS_TIME);
		echo("It summer");
		Release(summer);

		Wait(SUMMER_TIME);

		Seize(summer);
		echo("It's winter");
		echo(Time);
	}
}

