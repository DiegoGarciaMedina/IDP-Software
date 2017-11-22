
#include <iostream>
#include <stopwatch.h>
#include <vector>
#include <robot_instr.h>
#include <robot_link.h>
using namespace std;
#define ROBOT_NUM 14
robot_link rlink;
#include "movement.h"
int val,sensors, TIME;
bool distance_sensor;

void test_turn_detection() {
stopwatch watch;
watch.start();

  while (watch.read() < 100000){
	rlink.command(WRITE_PORT_5,255);
	sensors = 15 -(255-rlink.request(READ_PORT_5));
	line_following(sensors);
	straight_junction(sensors);}

watch.start();

turn = 0
  while (watch.read() < 100000){
	rlink.command(WRITE_PORT_5,255);
	sensors = 15 -(255-rlink.request(READ_PORT_5));
	line_following(sensors);
	turn  = turn_detection(sensors,turn);
	if (sensors == 15)
		{break;}
    cout << sensors  << endl;
    TIME = watch.read();
    while (watch.read()-TIME < 250){}
  }

if (turn < 0){
    turn_left();}
else if (turn>0){
    turn_right();}
else
    {turn_right();}
}

int main(){
stopwatch watch;

#ifdef __arm__
   if (!rlink.initialise ("127.0.0.1")) {       // setup for local hardware
#else
   if (!rlink.initialise (ROBOT_NUM)) {
	   // setup the link
#endif
}

  val = rlink.request (TEST_INSTRUCTION); // send test instruction
  if (val == TEST_INSTRUCTION_RESULT) {   // check result
    cout << "Test passed" << endl;
  }
  else if (val == REQUEST_ERROR) {
    cout << "Fatal errors on link:" << endl;
    rlink.print_errs();
    rlink.reinitialise(); // flush the link
  }
  else {
    cout << "Test failed (bad value returned)" << endl;

}
test();
return 0;
}
