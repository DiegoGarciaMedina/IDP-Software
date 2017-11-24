//Basic demonstrability tests
#include <iostream>
#include <stopwatch.h>
#include <vector>
#include <robot_instr.h>
#include <robot_link.h>
using namespace std;
#define ROBOT_NUM 14
robot_link rlink;
int val,sensors, TIME;
stopwatch watch;

//test 1 Start robot pointing towards the ramp, turn left, at junction turn right, keep straight over other junction and stop when it detects a wall

void test(void)
	{
	int i;
	
	for (i=0;i<10;i++){
		watch.start();
		while (watch.read() < 2000){
			rlink.command(WRITE_PORT_2,255);
		}
		watch.start();
		while (watch.read() < 2000){
			rlink.command(WRITE_PORT_2,0);
		}
	}
 }

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
  test();
	
  return 0;
}
