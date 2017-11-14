;; This buffer is for notes you don't want to save, and for Lisp evaluation.
;; If you want to create a file, visit that file with C-x C-f,
;; then enter the text in that file's own buffer.

#include <iostream>
#include <stopwatch.h>
#include <vector>
#include <robot_instr.h>
#include <robot_link.h>
using namespace std;
#define ROBOT_NUM 14
#include "movement.h"
robot_link rlink;

int main()
{
  stopwatch watch;
  int a=0,i,val,distance;

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

  //from starting point facing P2

  watch.start()
  turn_left();
  read_sensors_line_following();
  while (sensors != 7 && sensors =! 15){
    line_following(read_sensors_line_following());
  }
  straight_junction();
  while (sensors != 7 && sensors =! 15){
    line_following(read_sensors_line_following());
  }

  // in this part we should insert a test about the robot realising which way we have gone through the truntable

  reverse_robot(2000);
  turn_around(); 
  while (sensors != 7 && sensors =! 15){
    line_following(read_sensors_line_following());
  }
  straight_junction();
  while (sensors != 7 && sensors =! 15){
    line_following(read_sensors_line_following());
  }
  turn_right()
  while (sensors != 7 && sensors =! 15){
    line_following(read_sensors_line_following());
  }
  straight_junction();
  while (sensors != 7 && sensors =! 15){
    line_following(read_sensors_line_following());
  }
  turn_right();
  while (sensors != 7 && sensors =! 15){
    line_following(read_sensors_line_following());
  }
  straight_junction();
  distance = distance_sensor()
  while (distance_sensor =! 1){
    line_following(read_sensors_line_following());
    distance = distance_sensor()
  }
  stop();
  

  return (watch.read());
}
