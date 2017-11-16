# Automatically generated Makefile
Test_line_follower :  Test_line_follower.o movement.o
	 g++ -L/export/teach/1BRobot -o Test_line_follower  Test_line_follower.o  movement.o  -lrobot

Test_line_follower.o: Test_line_follower.cpp movement.h
	 g++ -ansi -Wall -g -I/export/teach/1BRobot -c Test_line_follower.cpp
movement.o: movement.cpp
	 g++ -ansi -Wall -g -I/export/teach/1BRobot -c movement.cpp
