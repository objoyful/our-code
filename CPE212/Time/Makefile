timedriver: timedriver.o time.o
	g++ -g time.o timedriver.o -o timedriver

time.o: time.h time.cpp
	g++ -g -c time.cpp

timedriver.o: time.h timedriver.cpp
	g++ -g -c timedriver.cpp

clean:
	rm *.o