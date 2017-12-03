#include <iostream>
#include <simlib.h>

#include "counters.h"
#include "constants.h"

int main() {


	Init(0, MAX_RUN_TIME);

	(new YearCounter)->Activate();

	Run();




	return 0;
}