//Basic demonstrability tests
#include <iostream>
#include <stopwatch.h>
#include <vector>
#include <robot_instr.h>
#include <robot_link.h>
using namespace std;
#define ROBOT_NUM 14
robot_link rlink;
#include "movement.h"
int val,speed;

int main(){
int V5,sensors,TIME;
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

speed = 100 // setting the speed of the AGV

//test 1 Start robot pointing towards the ramp, turn left, at junction turn right, keep straight over other junction and stop when it detects a wall

int test_1()
{   speed = 100;
    rlink.command(MOTOR_3_GO,speed); //update the right motor speed
    rlink.command(MOTOR_1_GO,speed);

    turn_left(speed); //90 degrees stationary left turn
    rlink.command(WRITE_PORT_5,255);
    while (watch.read()<50000)
    {
    sensors = 15 -(255-rlink.request(READ_PORT_5));
    line_following(sensors);
    if sensors == 15;
        break;
    }
    turn_right(speed); // 90 degrees stationary right turn

    while (watch.read()<1000000)
    {
    sensors = 15 -(255-rlink.request(READ_PORT_5));
    if sensors == 15
    {sensors = 6;}
    line_following();
    if (wall == true)
    {
        break;
    }
    }
        }


}
//test 2 Starting from 20cm away from the ramp (pointing towards it), move up the ramp and keep straight over junction and stop at delivery point

//test 3 Start 20 cm from collection point and go towards it and get aligned for pick-up. Show that robot knows that it has arrived at collection point.

 return 0;
