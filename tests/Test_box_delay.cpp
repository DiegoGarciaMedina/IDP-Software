#include <iostream>
#include <stopwatch.h>
#include <vector>
#include <robot_instr.h>
#include <robot_link.h>
using namespace std;
#define ROBOT_NUM 14
//#include "line_following.h" not needed for this test
int val;

robot_link rlink;

void BoxType(int time_taken){
	
	cout << "The time detected was " << time_taken << endl;
  
  if (time_taken > 1500){
	  cout << "This is a short circuit" << endl;
  }
  else if (time_taken > 800){
	  cout << "This is box type 1" << endl;
  }
  else if (time_taken > 70){
	  cout << "This is box type 2" << endl;
  }
  else if (time_taken > 20){
	  cout << "This is box type 3" << endl;
  }
  else {
	  cout << "This is an open circuit" << endl;
  }


}

int main(){
  //int B6;
  stopwatch watch;
  stopwatch watch2;
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

  int v;
  int DELAY;
  /*
  rlink.command(WRITE_PORT_5,64);
  v = rlink.request(READ_PORT_5) & 64;
  while (watch.read() < 600000){
	  v = rlink.request(READ_PORT_5) & 64;
	  cout << v << endl;
	  if (v == 64){
		  //watch2.start();
		  //while (watch.read()<1000){rlink.command(WRITE_PORT_5,128+64);}
		  watch2.start();
		  v=64;
		  while (v == 64){
			  //rlink.command(WRITE_PORT_5,128+64);
			  while(watch2.read() % 10 != 0){}
			  v = rlink.request(READ_PORT_5) & 64;
			  }
		  DELAY = watch2.read();
		  BoxType(DELAY);
		  break;
		  }
    }
    */
  rlink.command(WRITE_PORT_5,64);
  watch.start();
  while (watch.read() < 2000){
	rlink.command(WRITE_PORT_5,64);
	v = rlink.request(READ_PORT_5) & 64;
	cout << v << "   Testing on" << endl;
  }
  watch.start();
  while (watch.read() < 2000){
	rlink.command(WRITE_PORT_5,128+64);
	v = rlink.request(READ_PORT_5) & 64;
	cout << v << "   Testing off" << endl;
  }
  
  rlink.command(WRITE_PORT_5,64);
  v = rlink.request(READ_PORT_5) & 64;
  cout << v << endl;
  //watch2.start();
  //while (watch.read()<1000){rlink.command(WRITE_PORT_5,128+64);}
  watch2.start();
  v=64;
  while (v == 64 && watch2.read() < 5000){
	  //rlink.command(WRITE_PORT_5,128+64);
	  while(watch2.read() % 10 != 0){}
	  v = rlink.request(READ_PORT_5) & 64;
	  }
  DELAY = watch2.read();
  BoxType(DELAY);
	  
	  
  
  /*
  watch.start();
  
  while (watch.read() < 5*60000){
	
	if (watch.read() % 10 == 0){
		v = rlink.request(READ_PORT_5) & 64;
		cout << watch.read() << " " << v << endl; // print the time every second
    }
  }
	*/
	/*
	int i;
	for (i=0;i<8000;i++){
		watch.start();
		while (watch.read() < 3000){
			rlink.command(WRITE_PORT_5,64);
			v = rlink.request(READ_PORT_5) & 64;
			cout << v << "   Testing on" << endl;
		}
		watch.start();
		while (watch.read() < 3000){
			rlink.command(WRITE_PORT_5,128+64);
			v = rlink.request(READ_PORT_5) & 64;
			cout << v << "   Testing off" << endl;
		}
		}
	*/
return 0;
}

