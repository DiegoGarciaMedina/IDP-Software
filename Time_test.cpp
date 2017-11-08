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
  
		
  cout << "The time elapsed is " << watch.read() << endl;


  rlink.command(MOTOR_3_GO,254);
  //rlink.command(MOTOR_2_GO,100);
  rlink.command(MOTOR_1_GO,127);
  //rlink.command(MOTOR_4_GO,100);
  
  while (watch.read() < 10000)  {
  }
  
  watch.start();
  rlink.command(MOTOR_3_GO,127); //anticlowise 90
  //rlink.command(MOTOR_2_GO,100);
  rlink.command(MOTOR_1_GO,127);
  //rlink.command(MOTOR_4_GO,100);
  
  
  while (watch.read()< 1100)  {
  }
   watch.start();
  rlink.command(MOTOR_3_GO,254); 
  //rlink.command(MOTOR_2_GO,100);
  rlink.command(MOTOR_1_GO,127);
  //rlink.command(MOTOR_4_GO,100);
  
  
  while (watch.read() < 5000)  {
 }
    
  return 0;
}
