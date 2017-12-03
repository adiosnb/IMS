#include "line.h"
#include "constants.h"
#include "screws.h"

Facility post1_mux("Post 1");
Facility post2_mux("Post 2");
Facility post3_mux("Post 3");
Facility post4_mux("Post 4");


void Car::Behavior() {

	Seize(post1_mux);
	Seize(post2_mux);
	Seize(post3_mux);
	Seize(post4_mux);

	if (screw_errors.Capacity()){
		Wait(MONITOR_CHECKING_SCREW_ERROR);
	}
	else {
		Wait(MONITOR_CHECKING_NO_ERROR);
	}
}

void CarGenerator::Behavior() {
	(new Car)->Activate();
	Activate(Time + 50 + Random()*10);
}
