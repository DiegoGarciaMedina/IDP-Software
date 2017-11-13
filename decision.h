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

void D1_path(string InitialPoint){
  int i;

  if (InitialPoint == "P1"){
	  reverse(1100); // 1.1 seconds
	  turn_right();
	  sensor_value = line_following();
	  while (sensor_value != 7 && sensor_value != 15){
		  sensor_value = line_following();
	  }
	  straight_junction();
	  distance = distance_sensor();
	  while (distance != 1){
		  sensor_value = line_following();
	  }
	  delivery_mechanism(); // **YET TO BE DONE**
	  
  else {
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
	  distance = distance_sensor();
	  while (distance != 1){
		  sensor_value = line_following();
		  distance = distance_sensor();
	  }
	  delivery_mechanism(); // **YET TO BE DONE**
	  
  }
}

void D4_path(){
	int i;
	if (InitialPoint == "P2"){
	  reverse(1100);
	  turn_left();
	  sensor_value = line_following();
	  while (sensor_value != 7 && sensor_value != 15){
		  sensor_value = line_following();
	  }
	  straight_junction();
	  distance = distance_sensor();
	  while (distance != 1){
		  sensor_value = line_following();
	  }
	  delivery_mechanism(); // **YET TO BE DONE**
	  
  else {
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
	  turn_left();
	  sensor_value = line_following();
	  while (sensor_value != 7 && sensor_value != 15){
		  sensor_value = line_following();
	  }
	  straight_junction();
	  distance = distance_sensor();
	  while (distance != 1){
		  sensor_value = line_following();
		  distance = distance_sensor();
	  }
	  delivery_mechanism(); // **YET TO BE DONE**
  }
	
}

void D2orD5_path(){
	int i;
	if (InitialPoint == "P1"){ //choose detination depending on orientation of turn table
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
	  
	  delivery_mechanism(); // **YET TO BE DONE**
}
