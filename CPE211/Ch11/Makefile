#!/bin/bash 

#CCPATH is set to the following path names in the .bashrc file
CCPATH=/usr/bin/g++ -std=c++11 -Wall
#CCPATH=/opt/SUNWspro/bin/CC

PROGRAMS=Arrays_01 Arrays_02 Arrays_02b Arrays_03 Arrays_04 Arrays_05 Arrays_06 Arrays_07 Arrays_08 Arrays_09

program: ${PROGRAMS}


Arrays_01 : Arrays_01.cpp
	$(CCPATH)  -o Arrays_01 Arrays_01.cpp
Arrays_02 : Arrays_02.cpp
	$(CCPATH)  -o Arrays_02 Arrays_02.cpp
Arrays_02b : Arrays_02b.cpp
	$(CCPATH)  -o Arrays_02b Arrays_02b.cpp
Arrays_03 : Arrays_03.cpp
	$(CCPATH)  -o Arrays_03 Arrays_03.cpp
Arrays_04 : Arrays_04.cpp
	$(CCPATH)  -o Arrays_04 Arrays_04.cpp
Arrays_05 : Arrays_05.cpp
	$(CCPATH)  -o Arrays_05 Arrays_05.cpp
Arrays_06 : Arrays_06.cpp
	$(CCPATH)  -o Arrays_06 Arrays_06.cpp
Arrays_07 : Arrays_07.cpp
	$(CCPATH)  -o Arrays_07 Arrays_07.cpp
Arrays_08 : Arrays_08.cpp
	$(CCPATH)  -o Arrays_08 Arrays_08.cpp
Arrays_09 : Arrays_09.cpp
	$(CCPATH)  -o Arrays_09 Arrays_09.cpp
# MessyArray : MessyArray.cpp
# 	$(CCPATH)  -o MessyArray MessyArray.cpp


clean:
	rm ${PROGRAMS}

