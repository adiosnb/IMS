#include <iostream>
#include <simlib.h>

#include "counters.h"
#include "constants.h"

int main() {


	Init(0, TEST_ONE_DAY);

	(new YearCounter)->Activate();
	(new WeekCounter)->Activate();
	(new BreakCounter)->Activate();

	Run();




	return 0;
}