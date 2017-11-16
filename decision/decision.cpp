#include <iostream>
#include <stopwatch.h>
#include <robot_instr.h>
#include <robot_link.h>
using namespace std;
#define ROBOT_NUM 14
int val, stat;

robot_link rlink;
stopwatch watch;

void path_choice(string BoxType, string InitialPoint){
  switch (BoxType){
  case "O/C": D1(InitialPoint);
    cout << "O/C detected, heading to D1." << endl;
  case "Short": D1(InitialPoint);
    cout << "Short circuit detected, heading to D1." << endl;
  case "1": D2(InitialPoint);
    cout << "Box type 1 detected, heading to D2." << endl;
  case "2": D4(InitialPoint);
    cout << "Box type 2 detected, heading to D4." << endl;
  case "3": D3(InitialPoint);
    cout << "Box type 3 detected, heading to D3." << endl;
  default : cout << "The box has not been properly classified!" << endl;
  }
}

void D1_path(string InitialPoint){
  int i;

  if (InitialPoint == "P1"){
	  /*THIS IS THE DELIVERY PART*/
	  reverse(1100); // 1.1 seconds
	  turn_right();
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
	  delivery_mechanism(); // **YET TO BE DONE** Specify height!!!

	  /*RETURN HOME*/
	  reverse(1100); // 1.1 seconds
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
	  stop();
  }
  else {
	  /*THIS IS THE DELIVERY PART*/
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
	  turn_right();
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

	  /*RETURN HOME*/
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
}

void D4_path(string InitialPoint){
	if (InitialPoint == "P2"){
	  /*THIS IS THE DELIVERY PART*/
	  reverse(1100);
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

	  /*RETURN HOME*/
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
	  /*THIS IS THE DELIVERY PART*/
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

	  /*RETURN HOME*/
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

}

void D2orD5_path(string InitialPoint){
	int speed_motor1, speed_motor2;
	bool turned_left = false, turned_right = false;
	if (InitialPoint == "P1"){ //choose detination depending on orientation of turn table
	  /*THIS IS THE DELIVERY PART*/
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

	  /*RETURN HOME*/
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
	else{
	  /*THIS IS THE DELIVERY PART*/
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
	  straight_junction();
	  bool block = distance_sensor();
	  while (block != true){
		  sensor_value = line_following();
		  block = distance_sensor();
	  }
	  stop;
	  delivery_mechanism(); // **YET TO BE DONE**

	  /*RETURN HOME*/
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

void D3orD6_path(string InitialPoint){
	int speed_motor1, speed_motor2;
	bool turned_left = false, turned_right = false;
	if (InitialPoint == "P1"){ //choose detination depending on orientation of turn table
	  /*THIS IS THE DELIVERY PART*/
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

	  /*RETURN HOME*/
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
	  /*THIS IS THE DELIVERY PART*/
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

	  /*RETURN HOME*/
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
}
