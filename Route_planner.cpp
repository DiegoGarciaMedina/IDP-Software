#include <iostream>
#include <stopwatch.h>
#include <robot_instr.h>
#include <robot_link.h>
using namespace std;
#define ROBOT_NUM 14
int val, stat;

robot_link rlink;
stopwatch watch;

#define time90turn 1100
#define time90turntable 1100
#define time180turn 2200
#define time_separation 500

int main(){

#ifdef __arm__
   if (!rlink.initialise ("127.0.0.1")) {         // setup for local hardware
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
  }
  else {
    cout << "Test failed (bad value returned)" << endl;
  }

}

void delivery(string BoxType, string InitialPoint){
  switch (BoxType){
  case "O/C": D1(InitialPoint);
    cout << "O/C detected, heading to D1."
  case "Short": D1(InitialPoint);
    cout << "Short circuit detected, heading to D1."
  case "1": D2(InitialPoint);
    cout << "Box type 1 detected, heading to D2."
  case "2": D4(InitialPoint);
    cout << "Box type 2 detected, heading to D4."
  case "3": D3(InitialPoint);
    cout << "Box type 3 detected, heading to D3."
  default : cout << "The box has not been properly classified!" << endl;
  }
}

void D1(string InitialPoint){

  bool misleading_turn_table = false;
  bool reached_delivery_point = false;

  watch.start();

  // separate from collection point
  rlink.command(MOTOR_3_GO,127);
  rlink.command(MOTOR_1_GO,127);
  while (watch.read() < time_separation){}

  // turn 180
  watch.start();
  rlink.command(MOTOR_3_GO,127);
  rlink.command(MOTOR_1_GO,127);
  while (watch.read() < time180turn){}

  // activate line following
  while ((misleading_turn_table == false) && (reached_delivery_point == false)){
    misleading_turn_table, reached_delivery_point = line_follower(InitialPoint,"D1","turn_table_left"); // **YET TO BE DONE**
    }

  // decide whether it has reached the turn table or the delivery point
  if (misleading_turn_table == true){
    // turn 90 anticlockwise
    watch.start();
    rlink.command(MOTOR_3_GO,127);
    rlink.command(MOTOR_1_GO,127);
    while (watch.read() < time90turntable){}

    // reactivate line following after the
    while (reached_delivery_point == false){
      misleading_turn_table, reached_delivery_point = line_follower("Lcross","D1","None");
    }
  }

  delivery_mechanism(); // **YET TO BE DONE**

  }
}
