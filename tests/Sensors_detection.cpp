#include <iostream>
#include <stopwatch.h>
#include <robot_instr.h>
#include <robot_link.h>
using namespace std;
#define ROBOT_NUM 14
int val, stat;

robot_link rlink;

stopwatch watch;

int main(){

#ifdef __arm__
   if (!rlink.initialise ("127.0.0.1")) {          // setup for local hardware
#else
}
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
  }
  else {
    cout << "Test failed (bad value returned)" << endl;
  }

	rlink.command(WRITE_PORT_3, 64+16+4+1);
	//rlink.command (WRITE_PORT_1, 0);
	//rlink.command (WRITE_PORT_2, 0);
	rlink.command (WRITE_PORT_3, 64);
	int v=rlink.request (READ_PORT_3);
	cout << "Value 1 ="  << v << endl;

	watch.start();
	while (watch.read()<3000){
		}
	rlink.command (WRITE_PORT_3, 1);
	v = rlink.request (READ_PORT_3);

    cout << "Value 2 ="  <<v << endl;
    //stat = rlink.request (STATUS);
    cout << stat << endl;
	return 0;
	}
