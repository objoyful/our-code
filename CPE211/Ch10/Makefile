#!/bin/sh 
# CCPATH is defined in .bashrc
CCPATH=/usr/bin/g++ -std=c++11 -Wall

PROGRAMS=Structures_01 Structures_02 Structures_03 Structures_04 Structures_05

program: ${PROGRAMS}

Structures_01 : Structures_01.cpp
	${CCPATH} -lm -o Structures_01 Structures_01.cpp
Structures_02 : Structures_02.cpp
	${CCPATH} -lm -o Structures_02 Structures_02.cpp
Structures_03 : Structures_03.cpp
	${CCPATH} -lm -o Structures_03 Structures_03.cpp
Structures_04 : Structures_04.cpp
	${CCPATH} -lm -o Structures_04 Structures_04.cpp
Structures_05 : Structures_05.cpp
	${CCPATH} -lm -o Structures_05 Structures_05.cpp
clean:
	rm ${PROGRAMS}
