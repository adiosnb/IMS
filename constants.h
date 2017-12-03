#ifndef CONSTANTS
#define CONSTANTS

#define DEFAULT_COUNTER_PRIORITY	2

#define MAX_RUN_TIME		999999999

#define OTHER_SEASONS_TIME	23328000 	// 9*30*24*60*60
#define SUMMER_TIME 		8208000		// (365 - 9*30)*24*60*60

#define WEEK_DAYS			432000		// 5*24*60*60
#define WEEKEND_DAYS		172800		// 2*24*60*60

#define WORKING_TIME		9000		// 2.5*60*60
#define SHORT_BREAK			600			// 10*60
#define LONG_BREAK			1200		// 20*60



/*
 * Monitor checking times
 */
#define MONITOR_CHECKING_NO_ERROR		15
#define MONITOR_CHECKING_SCREW_ERROR	60

/*
 * TEST TIME
 */
#define TEST_ONE_DAY 		86400

#endif //CONSTANTS
