#include "counters.h"
#include "constants.h"

void YearCounter::Behavior() {
	summer.SetName("Summer");
	Seize(summer);
	Priority = 1;
	while (true){
		// starting in another other season than summer
		Wait(OTHER_SEASONS_TIME);

		Release(summer);

		Wait(SUMMER_TIME);

		Seize(summer);

	}
}



/*
 * Facilities init
 */
