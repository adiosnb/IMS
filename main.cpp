#include <iostream>
#include <simlib.h>

#include "counters.h"
#include "constants.h"
#include "line.h"
#include "stats.h"

int main() {


	Init(0, 60*60*24*3);

	(new YearCounter)->Activate();
	(new WeekCounter)->Activate();
	(new BreakCounter)->Activate();

	(new CarGenerator)->Activate();

	(new MainLineProc)->Activate();

	Run();


	throughput_8_hours.Output();
	throughput_24_hours.Output();
	throughput_while_error.Output();
	queue_of_cars.Output();

	return 0;
}