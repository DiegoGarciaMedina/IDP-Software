#include <iostream>
#include <stopwatch.h>
#include <vector>
#include <robot_instr.h>
#include <robot_link.h>
using namespace std;
#define ROBOT_NUM 14


robot_link rlink;

//index of variables
//sensors:decimal number corresponding to the binary number made by sesnsors being set or off
//ms_r:motor speed right
//ms_l:motor speed left
//speed: value that will be decided experimentally

int read_sensors_line_following(void){
  int sensors;
  sensors = rlink.request(READ_PORT_1);
  return (sensors)


int line_following(int sensors) {
    int ms_r, ms_l, speed ,sensors ; //outputs
    stopwatch watch;
    watch.start();
    speed =127;

    if (sensors == 2|| sensors == 5|| sensors == 10 || sensors == 13)  //keep going straight
  {
     ms_r = speed;
     ms_l = ms_r + 127;
  }
  else if (sensors == 4||sensors == 6|| sensors == 12|| sensors == 14) // turn left
  {
     ms_r = speed;
     ms_l = ms_r/2 + 127;
  }

  else if (sensors == 1||sensors == 3|| sensors == 9|| sensors == 11)// turn right
  {
     ms_l = speed +127;
     ms_r = (ms_l-127)/2;
  }
  
  else if (sensors == 7|| sensors == 15){
    return (sensors)}

  else // reverse
  {
     ms_r = (speed)/3 +127;
     ms_l = ms_r-127;
  }

rlink.command(MOTOR_1_GO,ms_r); //update the right motor speed
rlink.command(MOTOR_3_GO,ms_l); //update the left motor speed

while (watch.read() < 500)  {
 }

 return(sensors)
  }

void turn_left(speed) {


}

void turn_right(void) {
}

void turn_around(void){

}

void reverse_robot(void){
}

void straight_junction(void){ 
  float ms_r,ms_l
  ms_r=rlink.request(MOTOR_1);
  ms_l=rlink.request(MOTOR_3);
  rlink.command(MOTOR_1_GO,ms_r);
  rlink.command(MOTOR_3_GO,ms_l);
}

void stop(void){
  float ms_r,ms_l
  ms_r=0;
  ms_l=0;
  rlink.command(MOTOR_1_GO,ms_r);
  rlink.command(MOTOR_3_GO,ms_l);
}

void pick_up(void){
}

void drop_box(void){
}


