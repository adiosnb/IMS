#include "line.h"
#include "constants.h"
#include "screws.h"
#include "counters.h"
#include "debug.h"
#include "stats.h"
#include "params.h"

long long staged_cars = 0;
long long proccessed_cars = 0;
long long created_cars = 0;

int post1_mux = 3;
int post2_mux = 2;
int post3_mux = 1;
int post4_mux = 0;

#define WAIT_CAR 30

void Car::Behavior() {

	created_cars++;

	echo("Entering post1");
	while(!post1_mux) Wait(WAIT_CAR);
	post1_mux--;
	staged_cars++;
	queue_of_cars(staged_cars - proccessed_cars);
	echo("Leaving post1");
	while(!post2_mux) Wait(WAIT_CAR);
	post2_mux--;
	echo("Leaving post2");
	while (!post3_mux) Wait(WAIT_CAR);
	post3_mux--;
	echo("Leaving post3");
	while (!post4_mux) Wait(WAIT_CAR);
	post4_mux--;
	echo("Leaving post4");

	if (screw_errors.Capacity()){
		Wait(MONITOR_CHECKING_SCREW_ERROR);
	}
	else {
		Wait(MONITOR_CHECKING_NO_ERROR);
	}
	echo("Car Proccesed");
	echo(Time);

	proccessed_cars++;
}

void CarGenerator::Behavior() {
	(new Car)->Activate();
	echo("New car created");
	echo(Time);
	Activate(Time + Uniform(CAR_GEN_LOW, CAR_GEN_HIGH));
}

void MainLineProc::Behavior() {
	while (true) {
		if (!weekend.Busy() and screw_errors.Capacity() and !no_errors) {
			screw_errors.SetCapacity(0);
		} else {
			Seize(working_week);

			if (!summer.Busy()) {
				Seize(summer);

				if (Random() <= SCREW_IS_OVERHEATED) {
					screw_errors.SetCapacity(screw_errors.Capacity() + 1);
					(new OverheatedScrew)->Activate();
					Release(summer);
				} else {
					Release(summer);
				}

			}

			// If screw brake is appended into store
			if (Random() <= SCREW_IS_BROOKEN and !backup_screw) {
				screw_errors.SetCapacity(screw_errors.Capacity() + 1);
			}

			if (Random() <= PART_IS_MISSING and !store_prediction) {
				if (Random() <= PART_IS_NOT_IN_STORE) {
					Wait(Uniform(WAIT_NOT_IN_STORE_LOW, WAIT_NOT_IN_STORE_HIGH));
				} else {
					Wait(Exponential(WAIT_IN_STORE));
				}
			}

			if (!screw_errors.Empty()) {
				Wait(Uniform(WAIT_BROOKEN_SCREW_LOW, WAIT_BROOKEN_SCREW_HIGH));
			} else {
				// TODO : shorter period for car processing
				Wait(Uniform(WAIT_STD_LOW, WAIT_STD_HIGH));
			}

			echo("Line is moving ");
			echo(Time);

			post1_mux += 1;
			post2_mux += 1;
			post3_mux += 1;
			post4_mux += 1;

			Release(working_week);
		}
	}
}
