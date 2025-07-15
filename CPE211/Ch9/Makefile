#!/bin/sh 
# CCPATH is defined in .bashrc

CCPATH=/usr/bin/g++ -std=c++11 -Wall
#CCPATH=/opt/SUNWspro/bin/CC

PROGRAMS=Functions2_01 Functions2_02 Functions2_03 Functions2_04 Functions2_05 Functions2_06 Functions2_07 Functions2_08

#program: Functions2_01 Functions2_02 Functions2_03 Functions2_04 Functions2_05 Functions2_06 Functions2_07 

program: ${PROGRAMS}

Functions2_01 : Functions2_01.cpp
	${CCPATH} -lm -o Functions2_01 Functions2_01.cpp
Functions2_02 : Functions2_02.cpp
	${CCPATH} -lm -o Functions2_02 Functions2_02.cpp
Functions2_03 : Functions2_03.cpp
	${CCPATH} -lm -o Functions2_03 Functions2_03.cpp
Functions2_04 : Functions2_04.cpp
	${CCPATH} -lm -o Functions2_04 Functions2_04.cpp
Functions2_05 : Functions2_05.cpp
	${CCPATH} -lm -o Functions2_05 Functions2_05.cpp
Functions2_06 : Functions2_06.cpp
	${CCPATH} -lm -o Functions2_06 Functions2_06.cpp
Functions2_07 : Functions2_07.cpp
	${CCPATH} -lm -o Functions2_07 Functions2_07.cpp
Functions2_08 : Functions2_08.cpp
	${CCPATH} -lm -o Functions2_08 Functions2_08.cpp

clean:
	rm ${PROGRAMS}
