#include <iostream>
#include <stopwatch.h>
#include <vector>
#include <robot_instr.h>
#include <robot_link.h>
using namespace std;
#define ROBOT_NUM 14
extern robot_link rlink;

//index of variables
//sensors:decimal number corresponding to the binary number made by sesnsors being set or off
//ms_r:motor speed right
//ms_l:motor speed left
//speed: value that will be decided experimentally
//distance: boolean value set to true if close to the wall


/*int read_sensors_line_following(void){
  double sensors_init;
  int sensors;
  sensors_init = rlink.request(READ_PORT_1);
  sensors_init += 0.5
  int sensors = (int)sensors_init
  return (sensors)
    }*/

/*int distance_sensor(int sensors){
  int distance;
  if(sensors<8){
    distance = 0;
}
  else{
    distance = 1;
}
}*/

int line_following(int sensors) {
    int ms_r, ms_l, speed; //outputs
    stopwatch watch;
    watch.start();
    speed =100;

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

  else if (sensors == 0|| sensors == 15){
	  
	ms_l = 0;
    ms_r = 0;
    }

  else // reverse
  {
     //ms_r = (speed)/3 +127;
     //ms_l = ms_r-127;
  }

rlink.command(MOTOR_3_GO,ms_r); //update the right motor speed
rlink.command(MOTOR_1_GO,ms_l); //update the left motor speed

 while (watch.read() < 100){}
 return(sensors);
  }

/*void turn_left(speed) {

int speed, ms_l, ms_r;

speed = rlink.request(MOTOR_1); //reads the current motor speed

ms_r = speed;
ms_l = 0; //sets the motor speeds

rlink.command(MOTOR_1_GO,ms_r); //update the right motor speed
rlink.command(MOTOR_3_GO,ms_l); //update the left motor speed

stopwatch watch;
watch.start();
while (watch.read()<1100){
}
}

void turn_right(void) {

int speed, ms_l, ms_r, time_reverse;

speed = rlink.request(MOTOR_1); //reads the current motor speed

ms_l = speed;
ms_r = 0; //sets the motor speeds

rlink.command(MOTOR_1_GO,ms_r); //update the right motor speed
rlink.command(MOTOR_3_GO,ms_l); //update the left motor speed

stopwatch watch;
watch.start();
while (watch.read()<1100){
}
}

void turn_around(void){
int speed, ms_l, ms_r;

speed = rlink.request(MOTOR_1); //reads the current motor speed

ms_l = speed;
ms_r = 0; //sets the motor speeds

rlink.command(MOTOR_1_GO,ms_r); //update the right motor speed
rlink.command(MOTOR_3_GO,ms_l); //update the left motor speed

stopwatch watch;
watch.start();
while (watch.read()<2200){
}
}

void reverse_robot(time_reverse){
int speed, ms_l, ms_r;

speed = rlink.request(MOTOR_1);
ms_r = (speed)/3 +127;
ms_l = ms_r-127;

rlink.command(MOTOR_1_GO,ms_r); //update the right motor speed
rlink.command(MOTOR_3_GO,ms_l); //update the left motor speed
watch.start()
while (watch.read()<time_reverse){
}

}

void straight_junction(void){
double ms_r,ms_l;
  ms_r=rlink.request(MOTOR_1);
  ms_l=rlink.request(MOTOR_3);
  rlink.command(MOTOR_1_GO,ms_r);
  rlink.command(MOTOR_3_GO,ms_l);
  watch.start();
  while (watch.read() < 500)  {
 }
}

void stop(void){
double ms_r,ms_l;
  ms_r=0;
  ms_l=0;
  rlink.command(MOTOR_1_GO,ms_r);
  rlink.command(MOTOR_3_GO,ms_l);
}

void pick_up(void){
}

void drop_box(void){
}
*/

