# #!/bin/bash
# make file for class Time
#program: timedriver time.o timedriver.o
# create a macro for compiling
CC=g++ -std=c++11 -Wall
timedriver:  timedriver.o  time_sec.o
	$(CC) time_sec.o  timedriver.o   -o timedriver

time.o:  time_sec.h  time_sec.cpp
	$(CC) -c  time_sec.cpp

timedriver.o:  time_sec.h  timedriver.cpp
	$(CC) -c  timedriver.cpp
clean:
	rm *.o

cleanAll:
	rm *.o timedriver

