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
stopwatch watch;

int main(){


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
  
  //go get the box
  //pick up
  //id
  //path_choice(BoxType, starting point)
	
  return 0;
}

