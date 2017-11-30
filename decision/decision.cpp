#include <iostream>
#include <stopwatch.h>
#include <robot_instr.h>
#include <robot_link.h>
using namespace std;
#define ROBOT_NUM 14
#include "movement.h"
stopwatch watch_turn;

extern robot_link rlink;


void D1_path(string);
void D4_path(string);
//void D2orD5_path(string);
/*void D3orD6_path(string);

void path_choice(int BoxType, string InitialPoint){
  switch (BoxType){
  case 0:
    cout << "O/C detected, heading to D1." << endl;
    D1_path(InitialPoint);
  case 1: 
    cout << "Short circuit detected, heading to D1." << endl;
    D1_path(InitialPoint);
  case 2:
    cout << "Box type 1 detected, heading to D2." << endl;
    D2orD5_path(InitialPoint);
  case 3: 
    cout << "Box type 2 detected, heading to D4." << endl;
    D4_path(InitialPoint);
  case 4: 
    cout << "Box type 3 detected, heading to D3." << endl;
    D3orD6_path(InitialPoint);
  default : cout << "The box has not been properly classified!" << endl;
  }
}*/

void D1_path(string InitialPoint){
  int i;

  if (InitialPoint == "P1"){
	  //THIS IS THE DELIVERY PART
	  turn_right();
	  int sensor_value = sensors_read();
	  while (sensor_value!= 15){
		  sensor_value = line_following(sensor_value);
		  sensor_value = sensors_read();
	  }
	  straight_junction();
	  sensor_value = sensors_read();
	  bool wall = object_ahead();
	  while (wall != true){
		  sensor_value = line_following(sensor_value);
		  sensor_value = sensors_read();
		  wall = object_ahead();
		  cout<< wall << endl;
	  }
	  stop();
	  //alignment_drop();
	  //drop_box(1);

	  //RETURN HOME
	  reverse_robot(1100); 
	  turn_around();
	  sensor_value = sensors_read();
	  while (sensor_value != 15){
		  sensor_value = line_following(sensor_value);
		  sensor_value = sensors_read();
	  }
	  straight_junction();
	  sensor_value = sensors_read();	  
	  while (sensor_value != 15){
		  sensor_value = line_following(sensor_value);
		  sensor_value = sensors_read();
	  }
	  turn_right();
	  stop();
	  alignment_pickup();
  }
  else {
	  //THIS IS THE DELIVERY PART
	  reverse_robot(1100);
	  turn_around();
	  for (i=0;i<4;i++){ // repeat 3 times due to 3 intersections
		  int sensor_value = sensors_read();
		  while (sensor_value != 15){
			  sensor_value = line_following(sensor_value);
			  sensor_value = sensors_read();
		  }
		  straight_junction();
	  }
	  int sensor_value = sensors_read();
	  while (sensor_value != 15){
		  sensor_value = line_following(sensor_value);
		  sensor_value = sensors_read(); 
	  turn_right();
	  sensor_value = sensors_read();
	  sensor_value = line_following(sensor_value);
	  while (sensor_value != 15){
		  sensor_value = line_following(sensor_value);
		  sensor_value = sensors_read();
	  }
	  straight_junction();
	  bool wall = object_ahead();
	  sensor_value = sensors_read();
	  while (wall != true){
		  cout<< wall << endl;
		  sensor_value = line_following(sensor_value);
		  wall = object_ahead();
		  sensor_value = sensors_read();
	  }
	  stop();
	  //alignment_drop();
	  //drop_box(1); // **YET TO BE DONE**

	  //RETURN HOME
	  reverse_robot(1100);
	  turn_around();
	  reverse_robot(1000);
	  sensor_value = sensors_read();
	  sensor_value = line_following(sensor_value);
	  while (sensor_value != 15){
		  sensor_value = line_following(sensor_value);
		  sensor_value = sensors_read();
	  }
	  straight_junction();
	  sensor_value = sensors_read();
	  while (sensor_value != 15){
		  sensor_value = line_following(sensor_value);
		  sensor_value = sensors_read();
	  }
	  watch_turn.start();
	  while (watch_turn.read()<1000){}
	  reverse_robot(500);
	  turn_left();
	  for (i=0;i<4;i++){ // repeat 3 times due to 3 intersections
		  sensor_value = sensors_read();
		  while (sensor_value != 15){
			  sensor_value = line_following(sensor_value);
			  sensor_value = sensors_read();
		  }
		  straight_junction();
	  }
	  sensor_value = sensors_read();
	  while (sensor_value != 15){
		  sensor_value = line_following(sensor_value);
		  sensor_value = sensors_read();
	  }
	  stop();
	  alignment_pickup();
  }
}}

void D4_path(string InitialPoint){
 if (InitialPoint == "P2"){
      //THIS IS THE DELIVERY PART
      reverse_robot(500);
      turn_left();
      int sensor_value = sensors_read();
      while (sensor_value != 15){
          line_following(sensor_value);
          sensor_value = sensors_read();
      }
      straight_junction();
      bool wall = object_ahead();
      while (wall != true){
          line_following(sensor_value);
          sensor_value = sensors_read();
          wall = object_ahead();
          cout<< wall << endl;
      }
      stop();
      //high_dropbox(); // **YET TO BE DONE**

      //RETURN HOME
      reverse_robot(1100);
      turn_around();
      sensor_value = sensors_read();
      cout << sensor_value << endl;
      while (sensor_value != 15){
		  line_following(sensor_value);
          sensor_value = line_following(sensor_value);
      }
      straight_junction();
      sensor_value = sensors_read();
      while (sensor_value != 15){
          sensor_value = line_following(sensor_value);
      }
      turn_left();
      reverse_robot(1000);
      bool block = object_ahead();
      while (block != true){
          sensor_value = line_following(sensor_value);
          block = object_ahead();
      alignment_pickup();
      }
      stop();
      
  }
 }

/*void D4_path(string InitialPoint){
	if (InitialPoint == "P2"){
	  //THIS IS THE DELIVERY PART
	  reverse_robot(1100);
	  turn_left();
	  sensor_value = sensors_read();
	  while (sensor_value != 15){
		  sensor_value = line_following(sensors_read);
		  sensor_value = sensors_read();
	  }
	  straight_junction();
	  bool wall = distance_sensor();
	  while (wall != true){
		  sensor_value = line_following();
		  wall = distance_sensor();
	  }
	  stop();
	  delivery_mechanism(); // **YET TO BE DONE**

	  //RETURN HOME
	  reverse(1100);
	  turn_around();
	  sensor_value = line_following();
	  while (sensor_value != 7 && sensor_value != 15){
		  sensor_value = line_following();
	  }
	  straight_junction();
	  sensor_value = line_following();
	  while (sensor_value != 7 && sensor_value != 15){
		  sensor_value = line_following();
	  }
	  turn_left();
	  bool block = distance_sensor();
	  while (block != true){
		  sensor_value = line_following();
		  block = distance_sensor();
	  }
	  stop();
  }

  else {
	  //THIS IS THE DELIVERY PART
	  reverse(1100);
	  turn_around();
	  for (i=0;i<3;i++){ // repeat 3 times due to 3 intersections
		  sensor_value = line_following();
		  while (sensor_value != 7 && sensor_value != 15){
			  sensor_value = line_following();
		  }
		  straight_junction();
	  }
	  sensor_value = line_following();
	  while (sensor_value != 7 && sensor_value != 15){
		  sensor_value = line_following();
	  }
	  turn_left();
	  sensor_value = line_following();
	  while (sensor_value != 7 && sensor_value != 15){
		  sensor_value = line_following();
	  }
	  straight_junction();
	  bool wall = distance_sensor();
	  while (wall != true){
		  sensor_value = line_following();
		  wall = distance_sensor();
	  }
	  stop();
	  delivery_mechanism(); // **YET TO BE DONE**

	  //RETURN HOME
	  reverse(1100);
	  turn_around();
	  sensor_value = line_following();
	  while (sensor_value != 7 && sensor_value != 15){
		  sensor_value = line_following();
	  }
	  straight_junction();
	  sensor_value = line_following();
	  while (sensor_value != 7 && sensor_value != 15){
		  sensor_value = line_following();
	  }
	  turn_right();
	  for (i=0;i<4;i++){ // repeat 3 times due to 3 intersections
		  sensor_value = line_following();
		  while (sensor_value != 7 && sensor_value != 15){
			  sensor_value = line_following();
		  }
		  straight_junction();
	  }
	  bool block = distance_sensor();
	  while (block != true){
		  sensor_value = line_following();
		  block = distance_sensor();
	  }
	  stop();
  }

}*/

void D2orD5_path(string InitialPoint){
	//int speed_motor1, speed_motor2;
	bool turned_left = false, turned_right = false;
	/*if (InitialPoint == "P1"){ //choose detination depending on orientation of turn table
	  //THIS IS THE DELIVERY PART
	  reverse(1100);
	  turn_around();
	  sensor_value = line_following();
	  while (sensor_value != 7 && sensor_value != 15){
		  sensor_value = line_following();
	  }
	  straight_junction();
	  sensor_value = line_following();
	  while (sensor_value != 7 && sensor_value != 15){
		  sensor_value = line_following();
	  }
	  turn_left();
	  sensor_value = line_following();
	  while (sensor_value != 7 && sensor_value != 15){
		  sensor_value = line_following();
		  // Read motors to check wether it turned right or left on the turntable
		  speed_motor1 = rlink.request(MOTOR_1); // Assumining motor 1 is on the left
		  speed_motor2 = rlink.request(MOTOR_2) - 127; // This one is on the right
		  if (speed_motor1 - speed_motor2 > 10 && turned_right == false
			  && turned_left == false){ // ***VALUE TO BE CALIBRATED***
			   turned_right = true;
			   turned_left = false;
		   }
		   else{
			   turned_left = true;
			   turned_right = false;
		   }
	  }
	  straight_junction();
	  bool block = distance_sensor();
	  while (block != true){
		  sensor_value = line_following();
		  block = distance_sensor();
	  }
	  stop();
	  delivery_mechanism(); // **YET TO BE DONE**

	  //RETURN HOME
	  reverse(1100);
	  turn_around();
	  sensor_value = line_following();
	  while ((sensor_value != 7 && sensor_value != 15)||
	         (sensor_value != 8 && sensor_value != 0)){
		  sensor_value = line_following();
	  }
	  if (sensor_value == 8 || sensor_value == 0){ // turn table is wrong way round
		  if (turned_right == true){
			  turn_left_large();
		  }
		  else{
			  turn_right_large();
		  }
		  sensor_value = line_following();
		  while (sensor_value != 7 && sensor_value != 15){
			sensor_value = line_following();
		  }
	  }
	  sensor_value = line_following();
	  while (sensor_value != 7 && sensor_value != 15){
		sensor_value = line_following();
	  }
	  straight_junction();
	  sensor_value = line_following();
	  while (sensor_value != 7 && sensor_value != 15){
		sensor_value = line_following();
	  }
	  turn_right();
	  sensor_value = line_following();
	  while (sensor_value != 7 && sensor_value != 15){
		sensor_value = line_following();
	  }
	  straight_junction();
	  sensor_value = line_following();
	  while (sensor_value != 7 && sensor_value != 15){
		sensor_value = line_following();
	  }
	  straight_junction();
	  block = distance_sensor();
	  while (block != true){
		  sensor_value = line_following();
		  block = distance_sensor();
	  }
	  stop();
	}
	else{*/
	  
	  int turn = 0;
	  stopwatch watch2;
	  //THIS IS THE DELIVERY PART
	  watch2.start();
	  while (watch2.read() < 2000){
		rlink.command(MOTOR_4_GO,127);
	  }
	  reverse_robot(1100);
	  turn_around();
	  int sensor_value = sensors_read();
	  while (sensor_value != 15){
		  sensor_value = line_following(sensor_value);
	  }
	  straight_junction();
	  sensor_value = sensors_read();
	  while (sensor_value != 15){
		  sensor_value = line_following(sensor_value);
	  }
	  turn_right();
	  sensor_value = sensors_read();
	  while (sensor_value != 15){
		  sensor_value = line_following(sensor_value);
		  turn = turn_detection(sensor_value,turn);
	  }
	  if (turn > 0){turned_right = true;}
	  else {turned_left = true;} 
	  straight_junction();
	  bool block = object_ahead();
	  sensor_value = sensors_read();
	  while (block != true){
		  sensor_value = line_following(sensor_value);
		  block = object_ahead();
	  }
	  stop();
	  //delivery_mechanism(); // **YET TO BE DONE**

	  //RETURN HOME
	  reverse_robot(1100);
	  turn_around();
	  sensor_value = sensors_read();
	  while ((sensor_value != 15)||(sensor_value != 0)){
		  sensor_value = line_following(sensor_value);
		  sensor_value = sensors_read();
	  }
	  stop();
	  if (sensor_value == 15){} // turn table is the correct way round
	  else if (sensor_value == 0){
		  blind_turn(turn);
		  sensor_value = sensors_read();
		  }
	  sensor_value = sensors_read();
	  while (sensor_value != 15){
		sensor_value = line_following(sensor_value);
		sensor_value = sensors_read();
	  }
	  straight_junction();
	  sensor_value = sensors_read();
	  while (sensor_value != 15){
		sensor_value = line_following(sensor_value);
		sensor_value = sensors_read();
	  }
	  turn_left();
	  sensor_value = sensors_read();
	  while (sensor_value != 15){
		sensor_value = line_following(sensor_value);
		sensor_value = sensors_read();
	  }
	  straight_junction();
	  sensor_value = sensors_read();
	  while (sensor_value != 15){
		sensor_value = line_following(sensor_value);
		sensor_value = sensors_read();
	  }
	  straight_junction();
	  block = object_ahead();
	  sensor_value = sensors_read();
	  while (block != true){
		  sensor_value = line_following(sensor_value);
		  block = object_ahead();
	  }
	  stop();
}
	
void D3orD6_path(string InitialPoint){

//THIS IS THE DELIVERY PART
      reverse_robot(1100);
      turn_around();
      int sensor_value = sensors_read();
      while (sensor_value != 15){
          line_following(sensor_value);
          sensor_value = sensors_read();
      }
      straight_junction();
      sensor_value = sensors_read();
      while (sensor_value != 15){
          line_following(sensor_value);
          sensor_value = sensors_read();
      }
      turn_right();
      sensor_value = sensors_read();
      int turn;
      turn=0;
      while (sensor_value != 15){
          line_following(sensor_value);
          sensor_value = sensors_read();
          turn = turn_detection(sensor_value,turn);}
      if (turn < 0){
        turn_left();}
      else{
        turn_right();}
      sensor_value = sensors_read();
      while (sensor_value != 15){
          line_following(sensor_value);
          sensor_value = sensors_read();
      }
      stop();
      //alignment_drop();
      // DROP BOX AT THAT POINT

//RETURN HOME
      reverse_robot(1100);
      if (turn > 0){
        turn_left();}
      else{
        turn_right();}
      sensor_value = sensors_read();
      while (sensor_value != 15 && sensor_value != 0){
        line_following(sensor_value);
        sensor_value = sensors_read();}
      if (sensor_value == 0){
        blind_turn(turn);
        sensor_value = sensors_read();
        while (sensor_value != 15){
          line_following(sensor_value);
          sensor_value = sensors_read();}
      straight_junction();
      int sensor_value = sensors_read();
      while (sensor_value != 15){
         line_following(sensor_value);
         sensor_value = sensors_read();}}
      turn_left();
      sensor_value = sensors_read();
      while (sensor_value != 15){
         line_following(sensor_value);
         sensor_value = sensors_read();}
      straight_junction();
      sensor_value = sensors_read();
      while (sensor_value != 15){
         line_following(sensor_value);
         sensor_value = sensors_read();}
      straight_junction();
}

	
/*
void D3orD6_path(string InitialPoint){
	int speed_motor1, speed_motor2;
	bool turned_left = false, turned_right = false;
	if (InitialPoint == "P1"){ //choose detination depending on orientation of turn table
	  //THIS IS THE DELIVERY PART
	  reverse(1100);
	  turn_around();
	  sensor_value = line_following();
	  while (sensor_value != 7 && sensor_value != 15){
		  sensor_value = line_following();
	  }
	  straight_junction();
	  sensor_value = line_following();
	  while (sensor_value != 7 && sensor_value != 15){
		  sensor_value = line_following();
	  }
	  turn_left();
	  sensor_value = line_following();
	  while (sensor_value != 7 && sensor_value != 15){
		  sensor_value = line_following();
		  // Read motors to check wether it turned right or left on the turntable
		  speed_motor1 = rlink.request(MOTOR_1); // Assumining motor 1 is on the left
		  speed_motor2 = rlink.request(MOTOR_2) - 127; // This one is on the right
		  if (speed_motor1 - speed_motor2 > 10 && turned_right == false
			  && turned_left == false){ // ***VALUE TO BE CALIBRATED***
			   turned_right = true;
			   turned_left = false;
		   }
		   else{
			   turned_left = true;
			   turned_right = false;
		   }
	  }
	  if (turned_right == true){
		  turn_left();
	  }
	  else{
		  turn_right();
	  }
	  sensor_value = line_following();
	  while (sensor_value != 7 && sensor_value != 15){
		  sensor_value = line_following();
	  }
	  straight_junction();
	  bool block = distance_sensor();
	  while (block != true){
		  sensor_value = line_following();
		  block = distance_sensor();
	  }
	  stop();
	  delivery_mechanism(); // **YET TO BE DONE**

	  //RETURN HOME
	  reverse(1100);
	  if (turned_right == true){
		  turn_left();
	  }
	  else{
		  turn_right();
	  }
	  sensor_value = line_following();
	  while ((sensor_value != 7 && sensor_value != 15)||
	         (sensor_value != 8 && sensor_value != 0)){
		  sensor_value = line_following();
	  }
	  if (sensor_value == 8 || sensor_value == 0){ // turn table is wrong way round
		  if (turned_right == true){
			  turn_left_large();
		  }
		  else{
			  turn_right_large();
		  }
		  sensor_value = line_following();
		  while (sensor_value != 7 && sensor_value != 15){
			sensor_value = line_following();
		  }
	  }
	  sensor_value = line_following();
	  while (sensor_value != 7 && sensor_value != 15){
		sensor_value = line_following();
	  }
	  straight_junction();
	  sensor_value = line_following();
	  while (sensor_value != 7 && sensor_value != 15){
		sensor_value = line_following();
	  }
	  turn_right();
	  sensor_value = line_following();
	  while (sensor_value != 7 && sensor_value != 15){
		sensor_value = line_following();
	  }
	  straight_junction();
	  sensor_value = line_following();
	  while (sensor_value != 7 && sensor_value != 15){
		sensor_value = line_following();
	  }
	  straight_junction();
	  block = distance_sensor();
	  while (block != true){
		  sensor_value = line_following();
		  block = distance_sensor();
	  }
	  stop();
	}
	else{
	  //THIS IS THE DELIVERY PART
	  reverse(1100);
	  turn_around();
	  sensor_value = line_following();
	  while (sensor_value != 7 && sensor_value != 15){
		  sensor_value = line_following();
	  }
	  straight_junction();
	  sensor_value = line_following();
	  while (sensor_value != 7 && sensor_value != 15){
		  sensor_value = line_following();
	  }
	  turn_right();
	  sensor_value = line_following();
	  while (sensor_value != 7 && sensor_value != 15){
		  sensor_value = line_following();
		  // Read motors to check wether it turned right or left on the turntable
		  speed_motor1 = rlink.request(MOTOR_1); // Assumining motor 1 is on the left
		  speed_motor2 = rlink.request(MOTOR_2) - 127; // This one is on the right
		  if (speed_motor1 - speed_motor2 > 10 && turned_right == false
			  && turned_left == false){ // ***VALUE TO BE CALIBRATED***
			   turned_right = true;
			   turned_left = false;
		   }
		   else{
			   turned_left = true;
			   turned_right = false;
		   }
	  }
	  if (turned_right == true){
		  turn_left();
	  }
	  else{
		  turn_right();
	  }
	  sensor_value = line_following();
	  while (sensor_value != 7 && sensor_value != 15){
		  sensor_value = line_following();
	  }
	  straight_junction();
	  bool block = distance_sensor();
	  while (block != true){
		  sensor_value = line_following();
		  block = distance_sensor();
	  }
	  stop();
	  delivery_mechanism(); // **YET TO BE DONE**

	  //RETURN HOME
	  reverse(1100);
	  if (turned_right == true){
		  turn_left();
	  }
	  else{
		  turn_right();
	  }
	  sensor_value = line_following();
	  while ((sensor_value != 7 && sensor_value != 15)||
	         (sensor_value != 8 && sensor_value != 0)){
		  sensor_value = line_following();
	  }
	  if (sensor_value == 8 || sensor_value == 0){ // turn table is wrong way round
		  if (turned_right == true){
			  turn_left_large();
		  }
		  else{
			  turn_right_large();
		  }
		  sensor_value = line_following();
		  while (sensor_value != 7 && sensor_value != 15){
			sensor_value = line_following();
		  }
	  }
	  sensor_value = line_following();
	  while (sensor_value != 7 && sensor_value != 15){
		sensor_value = line_following();
	  }
	  straight_junction();
	  sensor_value = line_following();
	  while (sensor_value != 7 && sensor_value != 15){
		sensor_value = line_following();
	  }
	  turn_left();
	  sensor_value = line_following();
	  while (sensor_value != 7 && sensor_value != 15){
		sensor_value = line_following();
	  }
	  straight_junction();
	  sensor_value = line_following();
	  while (sensor_value != 7 && sensor_value != 15){
		sensor_value = line_following();
	  }
	  straight_junction();
	  bool block = distance_sensor();
	  while (block != true){
		  sensor_value = line_following();
		  block = distance_sensor();
	  }
	  stop();
	}
}*/
