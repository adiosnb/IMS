#ifndef LINE
#define LINE

#include <simlib.h>

extern Facility post1_mux;
extern Facility post2_mux;
extern Facility post3_mux;
extern Facility post4_mux;

class CarGenerator : public Event {
public:
	void Behavior();
};

class Car : public Process {
public:
	void Behavior();
};



#endif //LINE