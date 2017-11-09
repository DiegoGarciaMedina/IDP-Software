#include <iostream>
#include <stopwatch.h>
#include <vector>
#include <robot_instr.h>
#include <robot_link.h>
using namespace std;
#define ROBOT_NUM 14


robot_link rlink;

void line_following() {

    vector<double> sensors ; //inputs
    int ms_r, ms_l, speed; //outputs


    sensors [0] = rlink.request (READ_PORT_1); //sensor left
    sensors [1] = rlink.request (READ_PORT_2); // sensor middle
    sensors [2] = rlink.request (READ_PORT_3); //sensor right

  if ((sensors[0] = 0 && sensors[1] = 1 && sensors [2] = 0)||(sensors[0] = 1 && sensors [2] = 1))   //keep going straight
  {
     ms_r = speed;
     ms_l = ms_r + 127;
  }
  else if (sensors[0] = 1 && sensors [2] = 0) // turn left
  {
     ms_r = speed;
     ms_l = (ms_r)/2 + 127;
  }

  else if (sensors[0] = 0 && sensors [2] = 1) // turn left
  {
     ms_l = speed +127;
     ms_r = (ms_l-127)/2;
  }

  else // reverse
  {
     ms_r = speed +127;
     ms_l = ms_r-127;
  }

rlink.command(MOTOR_1_GO,ms_r); //update the right motor speed
rlink.command(MOTOR_2_GO,ms_l); //update the left motor speed

while (watch.read() < 500)  {
 }
  }
