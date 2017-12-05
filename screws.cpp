#include "screws.h"
#include "constants.h"

Store screw_errors;

void OverheatedScrew::Behavior() {
	Wait(Exponential(WAIT_OVERHEATED_SCREW));
	Enter(screw_errors);
}
