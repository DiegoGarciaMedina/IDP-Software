#include <iostream>
#include <stopwatch.h>
#include <vector>
#include <robot_instr.h>
#include <robot_link.h>
#include "decision.h"
#include "movement.h"
using namespace std;
#define ROBOT_NUM 14
robot_link rlink;
stopwatch watch2;

int main(){


#ifdef __arm__
   if (!rlink.initialise ("127.0.0.1")) {       // setup for local hardware
#else
   if (!rlink.initialise (ROBOT_NUM)) {
	   // setup the link
#endif
}

  int val = rlink.request (TEST_INSTRUCTION); // send test instruction
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
  
  //go get the box
  int sensor_value = sensors_read();
	  while (sensor_value != 15){
		sensor_value = line_following(sensor_value);
		sensor_value = sensors_read();
	  }
	straight_junction();
	
	sensor_value = sensors_read();
	  while (sensor_value != 15){
		sensor_value = line_following(sensor_value);
		sensor_value = sensors_read();
	  }
	straight_junction();
	

stopwatch watch_main;
watch_main.start();

while (watch_main.read() < 30000000)
{bool block = object_ahead();
	  while (block != true){
		  sensor_value = line_following(sensor_value);
		  block = object_ahead();
		  sensor_value = sensors_read();
	  }
	alignment_pickup();
	pick_up();
	int val = box_id();
	path_choice(val, "P2");}

  
  return 0;
}

