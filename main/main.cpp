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
  //pick up
  //id
  //path_choice(BoxType, starting point)
  /*
	watch2.start();
	while (watch2.read() < 2000){
		rlink.command(MOTOR_4_GO,255);
	}
	watch2.start();
	while (watch2.read() < 2000){
		rlink.command(WRITE_PORT_2,2); // 0=close
	}
	watch2.start();
	while (watch2.read() < 2000){
		rlink.command(WRITE_PORT_2,0); // 0=close
	}
	watch2.start();
	while (watch2.read() < 800){
		rlink.command(MOTOR_4_GO,127);
	}
	
	watch2.start();
	while (watch2.read() < 800){
		rlink.command(MOTOR_4_GO,0);
	}*/
	
		
  //val = box_id();
  
  //cout << val << endl;
  
  return 0;
}

