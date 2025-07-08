#!/bin/bash 
# CCPATH is defined in .bashrc

CCPATH=g++ -std=c++11 -Wall


PROGRAMS=Functions1_01 Functions1_02 Functions1_03 Functions1_03b Functions1_04 Functions1_05 Functions1_06 Functions1_06b Functions1_07 Functions1_08 Functions1_08b Functions1_09 Functions1_09b Functions1_10

program: ${PROGRAMS}

#program: Functions1_01 Functions1_02 Functions1_03 Functions1_04 Functions1_05 Functions1_06 Functions1_07 Functions1_08 Functions1_09 Functions1_09b Functions1_06b


Functions1_01 : Functions1_01.cpp
	${CCPATH}  -o Functions1_01 Functions1_01.cpp

Functions1_02 : Functions1_02.cpp
	${CCPATH}  -o Functions1_02 Functions1_02.cpp

Functions1_03 : Functions1_03.cpp
	${CCPATH}  -o Functions1_03 Functions1_03.cpp

Functions1_03b : Functions1_03b.cpp
	${CCPATH}  -o Functions1_03b Functions1_03b.cpp

Functions1_04 : Functions1_04.cpp
	${CCPATH}  -o Functions1_04 Functions1_04.cpp

Functions1_05 : Functions1_05.cpp
	${CCPATH}  -o Functions1_05 Functions1_05.cpp

Functions1_06 : Functions1_06.cpp
	${CCPATH}  -o Functions1_06 Functions1_06.cpp

Functions1_06b : Functions1_06b.cpp
	${CCPATH}  -o Functions1_06b Functions1_06b.cpp

Functions1_07 : Functions1_07.cpp
	${CCPATH}  -o Functions1_07 Functions1_07.cpp

Functions1_08 : Functions1_08.cpp
	${CCPATH}  -o Functions1_08 Functions1_08.cpp

Functions1_08b : Functions1_08b.cpp
	${CCPATH}  -o Functions1_08b Functions1_08b.cpp

Functions1_09 : Functions1_09.cpp
	${CCPATH}  -o Functions1_09 Functions1_09.cpp

Functions1_09b : Functions1_09b.cpp
	${CCPATH}  -o Functions1_09b Functions1_09b.cpp

Functions1_10 : Functions1_10.cpp
	${CCPATH}  -o Functions1_10 Functions1_10.cpp

clean:
	rm ${PROGRAMS}
