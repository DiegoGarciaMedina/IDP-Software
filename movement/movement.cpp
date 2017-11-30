#include <iostream>
#include <stopwatch.h>
#include <vector>
#include <robot_instr.h>
#include <robot_link.h>
using namespace std;
#define ROBOT_NUM 14
extern robot_link rlink;

stopwatch watch;

//index of variables
//sensors:decimal number corresponding to the binary number made by sesnsors being set or off
//ms_r:motor speed right
//ms_l:motor speed left
//speed: value that will be decided experimentally
//distance: boolean value set to true if close to the wall
//left:left turn detected (integer increases by 1 every time that the line following detects a left left)
//right: right turn detected(integer increases by 1 every time that the line following detects a right left)

int line_following(int sensors) {
    int ms_r, ms_l,speed; //outputs

    //cout << sensors << endl;

    watch.start();
    speed =100;
    switch(sensors){
		case 0:
		ms_r = (speed)/3 +127;
		ms_l = ms_r-127;
		break;
		case 6:
		ms_r = speed;
		ms_l = ms_r + 127;
		break;
		case 15:
		ms_r = 0;
		ms_l = 0;
		break;
		case 1:
		ms_l = speed +127;
		ms_r = (ms_l-127)/4;
		break;
		case 2:
		ms_l = speed +127;
		ms_r = (ms_l-127)/2;
		break;
		case 3:
		ms_l = speed +127;
		ms_r = 0; // (ms_l)/2 if we want the right wheel to reverse
		break;
		case 7:
		ms_l = speed +127;
		ms_r = 0; // (ms_l)/2 if we want the right wheel to reverse
		break;
		case 4:
		ms_r = speed;
		ms_l = ms_r/2 + 127;
		break;
		case 8:
		ms_r = speed;
		ms_l = ms_r/4 + 127;
		break;
		case 12:
		ms_r = speed;
		ms_l = 0;
		break;
		case 14:
		ms_r = speed;
		ms_l = 0;
		break;
		case 5:
		cout << "something is seriously wrong" << endl;
		break;
		case 9:
		cout << "something is seriously wrong" << endl;
		break;
		case 10:
		cout << "something is seriously wrong" << endl;
		break;
		case 11:
		cout << "something is seriously wrong" << endl;
		break;
		case 13:
		cout << "something is seriously wrong" << endl;
		break;
		default : cout << "just stop trying" << endl;
		break;
	}

rlink.command(MOTOR_3_GO,ms_r); //update the right motor speed
rlink.command(MOTOR_1_GO,ms_l); //update the left motor speed

 while (watch.read() < 100){}
 return(sensors);
  }

void turn_left(void) {
	
stopwatch watch_tl;
watch_tl.start();
while(watch_tl.read()<200){}
int speed, ms_l, ms_r;
speed = 127;
ms_r = speed;
ms_l = speed; //sets the motor speeds

rlink.command(MOTOR_1_GO,ms_r); //update the right motor speed
rlink.command(MOTOR_3_GO,ms_l); //update the left motor speed

stopwatch watch_turn;
watch_turn.start();
while (watch_turn.read()<1100){
}
}

void turn_right(void) {

stopwatch watch_tr;
watch_tr.start();
while(watch_tr.read()<200){}

int ms_l, ms_r,speed;
speed = 255;
ms_l = speed;
ms_r = speed; //sets the motor speeds

rlink.command(MOTOR_1_GO,ms_r); //update the right motor speed
rlink.command(MOTOR_3_GO,ms_l); //update the left motor speed

stopwatch watch;
watch.start();
while (watch.read()<900){ //1200
}
}

void turn_around(void){
int ms_l, ms_r,speed;
speed = 100;
ms_l = 127 +speed;
ms_r = ms_l; //sets the motor speeds

rlink.command(MOTOR_1_GO,ms_r); //update the right motor speed
rlink.command(MOTOR_3_GO,ms_l); //update the left motor speed

stopwatch watch;
watch.start();
while (watch.read()<3000){ //1200
}
}

void reverse_robot(int time_reverse){
int ms_l, ms_r;

ms_r = 100;
ms_l = 227;

rlink.command(MOTOR_1_GO,ms_r); //update the right motor speed
rlink.command(MOTOR_3_GO,ms_l); //update the left motor speed
watch.start();
while (watch.read()<time_reverse){
}

}

void straight_junction(void){
	line_following(6);
	watch.start();
	while (watch.read()<150){}
	cout <<"Junction has been detected and gone straight though"<<endl;
}

void stop(void){
	rlink.command(MOTOR_3_GO,0); 
    rlink.command(MOTOR_1_GO,0);	
}

int box_id(void){
  stopwatch watch;
  stopwatch watch2;
  rlink.command(WRITE_PORT_2,255); //turning all LEDs off

  int v;
  int box_type;

  rlink.command(WRITE_PORT_5,64);
  watch.start();
  while (watch.read() < 2000){
	rlink.command(WRITE_PORT_5,64);
	v = rlink.request(READ_PORT_5) & 64;
  }
  watch.start();
  while (watch.read() < 2000){
	rlink.command(WRITE_PORT_5,128+64);
	v = rlink.request(READ_PORT_5) & 64;
  }

  rlink.command(WRITE_PORT_5,64);
  v = rlink.request(READ_PORT_5) & 64;

  watch2.start();
  v=64;
  while (v == 64 && watch2.read() < 5000){
	  while(watch2.read() % 10 != 0){}
	  v = rlink.request(READ_PORT_5) & 64;
	  }
  int time_taken = watch2.read();

  if (time_taken > 1500){
	  box_type = 0 ;
	  rlink.command(WRITE_PORT_2,251); //short circuit
  }
  else if (time_taken > 800){
	  box_type = 1;
	  rlink.command(WRITE_PORT_2,191);//type 1
  }
  else if (time_taken > 70){
	  box_type = 2;
	  rlink.command(WRITE_PORT_2,223);// type 2
  }
  else if (time_taken > 20){
	  box_type = 3;
	  rlink.command(WRITE_PORT_2,239);//type 3
  }
  else {
	  box_type = 4;
	  rlink.command(WRITE_PORT_2,247); //open circuit
  }
return (box_type);
}

void pick_up(int height){
	int timeUP, timeDOWN,speedUP,speedDOWN;
	stopwatch watch_pickup;
	if (height == 0){timeUP= 5500;timeDOWN = 4500; speedDOWN=255;speedUP=127;}
	//else {time = 2500;speedUP=127;speedDOWN=speedUP+127;}
	watch_pickup.start();
	rlink.command(WRITE_PORT_2,2); // OPENS
	while (watch_pickup.read()<timeDOWN){
		rlink.command(MOTOR_4_GO,speedDOWN);//downwards
	}
	rlink.command(MOTOR_4_GO,0); //stop motor
	rlink.command(WRITE_PORT_2,253); // CLOSES
	watch_pickup.start();
	while(watch_pickup.read()<1000){}
	watch_pickup.start();
	while (watch_pickup.read()<timeUP){
		rlink.command(MOTOR_4_GO,speedUP);//upwards
	}
	rlink.command(MOTOR_4_GO,0); //stop motor
}

void drop_box(int height){
	int time,speedUP,speedDOWN;
	if (height == 0){time = 1500;speedDOWN=255;speedUP=speedDOWN-127;}
	else {time = 2500;speedUP=127;speedDOWN=speedUP+127;}
	watch.start();
	while (watch.read()<time){
		rlink.command(MOTOR_4_GO,speedDOWN);//downwards
	}
	rlink.command(MOTOR_4_GO,0); //stop motor
	rlink.command(WRITE_PORT_2,2); // OPENS
	watch.start();
	while (watch.read()<1000){
		// wait for bax to fall
	}
	rlink.command(WRITE_PORT_2,253); // CLOSES
	watch.start();
	while (watch.read()<1200){
		rlink.command(MOTOR_4_GO,speedUP);//upwards
	}
	rlink.command(MOTOR_4_GO,0); //stop motor
}

int sensors_read(void){
    rlink.command(WRITE_PORT_5,255);
 int sensors = rlink.request(READ_PORT_5) &15;
 if (sensors < 0){
    sensors = 6;
 }
 else if (sensors > 15){
    sensors = 6;
 }
 return (sensors);
}

int turn_detection(int sensors,int turn){

switch (sensors){
case 1:
case 2:
case 3:
case 7:
    turn +=1; //right
    break;
case 4:
case 8:
case 12:
case 14:
    turn -=1; //left
    break;
default:
    break;
}
return(turn);
}

bool object_ahead(void){
    int distance;
    bool close_object = false;
    distance = 0;
    distance =  rlink.request (ADC0);
    cout << distance << endl;
    if (distance > 115){
        close_object = true;
        cout<< "ive seen the wall"<< endl;}
    return (close_object);
}

void alignment_drop(void){

stopwatch watch_drop;
int sensors = sensors_read();
  while (sensors != 15)
  {line_following(sensors);
	sensors = sensors_read();}
	
reverse_robot(800);

  stop();
  
}
void alignment_pickup(void){

reverse_robot(700);

stopwatch watch_alignment_pickup;
watch_alignment_pickup.start();
int sensors = sensors_read();
  while (watch_alignment_pickup.read() < 2000
  ){
	sensors = sensors_read();
	line_following(sensors);
  }
  reverse_robot(150);
  
  stop();
}


void blind_turn(int turn){ //this will be a positive if it has turned right at the turntable, and negative if it has turned left
//if it has turned left, it needs to blind turn right and vice versa
//go straight
int speed = 100;
stopwatch watch;
watch.start();
while (watch.read()<2000)
{
    rlink.command(MOTOR_3_GO,speed); //update the right motor speed
    rlink.command(MOTOR_1_GO,speed+127);
}
if (turn<0)
{
    turn_right();
    rlink.command(MOTOR_3_GO,speed); //update the right motor speed
    rlink.command(MOTOR_1_GO,speed+127);
}
else if (turn>0)
{
    turn_left();
    rlink.command(MOTOR_3_GO,speed); //update the right motor speed
    rlink.command(MOTOR_1_GO,speed+127);
}
}



