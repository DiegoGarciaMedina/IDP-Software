#include <iostream>
#include <stopwatch.h>
#include <vector>
#include <robot_instr.h>
#include <robot_link.h>
using namespace std;
#define ROBOT_NUM 14
robot_link rlink;
#include "movement.h"
#include "decision.h"
int val; 

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
//turn_left();
D4_path("P2");
/*int sensors = sensors_read();
bool box = object_ahead();
while (box != true)
{	line_following(sensors);
	sensors = sensors_read();
	box = object_ahead();
	}
alignment_pickup();
pick_up(0);
reverse_robot(2000);
turn_around();*/
/*
watch.start();
while (watch.read() <5000){rlink.command(MOTOR_4_GO,127);} // goes up 5500
watch.start();
while (watch.read() <4500){rlink.command(MOTOR_4_GO,255);} //goes down - 3700*/
return 0;}


