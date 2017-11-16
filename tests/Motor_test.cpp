#include <iostream>
#include <stopwatch.h>
#include <vector>
#include <robot_instr.h>
#include <robot_link.h>
using namespace std;
#define ROBOT_NUM 14
#include "line_following.h"
int val;


int main(){

stopwatch watch;
#ifdef __arm__
   if (!rlink.initialise ("127.0.0.1")) {          // setup for local hardware
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
    watch.start();

	int t_ramp = 255; // no apparent difference changing the ramp from 0 to 255 
	
	rlink.command (RAMP_TIME, t_ramp);

    int speed = 127; // 30 just let's the robot make it up the ramp
    
    rlink.command(MOTOR_1_GO, speed);
    rlink.command(MOTOR_3_GO, speed + 127);
    
    while (watch.read() < 5000){
    }
    rlink.command (RAMP_TIME, t_ramp);
}
