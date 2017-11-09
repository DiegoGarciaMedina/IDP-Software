#include <iostream>
#include <stopwatch.h>
#include <vector>
#include <robot_instr.h>
#include <robot_link.h>
using namespace std;
#define ROBOT_NUM 14


robot_link rlink;



void line_following(void) {
    int ms_r, ms_l, speed ,sensors ; //outputs
    stopwatch watch;
    watch.start();
    speed =127;

	sensors = rlink.request(READ_PORT_1);
	cout << sensors << endl;

  if (sensors == 2|| sensors == 5||sensors ==7)   //keep going straight
  {
     ms_r = speed;
     ms_l = ms_r + 127;
  }
  else if (sensors == 4||sensors == 6) // turn left
  {
     ms_r = speed;
     ms_l = ms_r/2 + 127;
  }

  else if (sensors == 1||sensors == 3)// turn right
  {
     ms_l = speed +127;
     ms_r = (ms_l-127)/2;
  }

  else // reverse
  {
     ms_r = (speed)/3 +127;
     ms_l = ms_r-127;
  }

rlink.command(MOTOR_1_GO,ms_r); //update the right motor speed
rlink.command(MOTOR_3_GO,ms_l); //update the left motor speed

while (watch.read() < 500)  {
 }
  }
