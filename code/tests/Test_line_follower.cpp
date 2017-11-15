#include <iostream>
#include <stopwatch.h>
#include <vector>
#include <robot_instr.h>
#include <robot_link.h>
using namespace std;
#define ROBOT_NUM 14
robot_link rlink;
#include "movement.h"
int val;


int main(){
int V5;
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
    
watch.start();
    
  while (watch.read() < 5000){
	rlink.command(WRITE_PORT_5,255);
	V5 = rlink.request(READ_PORT_5);
	int sensors = 255-V5;
	line_following(sensors);
    cout << sensors  << endl;
    int TIME = watch.read();
    while (watch.read()-TIME < 250){}
  }

  cout << watch.read() << endl;
 return 0;
}
