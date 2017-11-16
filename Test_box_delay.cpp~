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
	int i;
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
    
    while (watch.read() < 2000){
    }
	watch.start();
	for(i=0;i<10000;i++) {
      cout << i << endl;
   }
	int v = rlink.request(READ_PORT_1);
	
    cout << "The value requested from the sensors is " << v << endl;
    cout << "The time taken to read the sensor 10000 times is " << watch.read() << "ms"<< endl;
}
