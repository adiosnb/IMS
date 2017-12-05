#include <iostream>
#include <simlib.h>

#include "counters.h"
#include "constants.h"
#include "line.h"

int main() {


	Init(0, 300);

	(new YearCounter)->Activate();
	(new WeekCounter)->Activate();
	(new BreakCounter)->Activate();

	(new CarGenerator)->Activate();

	(new MainLineProc)->Activate();

	Run();




	return 0;
}