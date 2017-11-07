#include <iostream>
#include <stopwatch.h>
#include <robot_instr.h>
#include <robot_link.h>
using namespace std;
#define ROBOT_NUM 14

robot_link rlink;

int main()
{
  stopwatch watch;
  int time_elapsed,time_elapsed2;
  int a=0,i,val;

  if (!rlink.initialise (ROBOT_NUM)) { // setup the link
  cout << "Cannot initialise link" << endl;
  rlink.print_errs("  ");
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

  watch.start();

  for (i=0;i<1000000;i++)
    {
      a=a+2*i;
    }
  
  time_elapsed = watch.read();
		
  cout << "The time elapsed is " << time_elapsed << endl;

  time_elapsed2 = watch.read();

  rlink.command(MOTOR_1_GO,100);
  //rlink.command(MOTOR_2_GO,100);
  //rlink.command(MOTOR_3_GO,100);
  //rlink.command(MOTOR_4_GO,100);
  
  while (time_elapsed2 < 10000)  {
    time_elapsed2 = watch.read();
  }

  return 0;
}