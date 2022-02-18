DVDArrayPDriver:  DVDArrayP.o DVDArrayPDriver.o DVD0.o
	g++ -g -Wall -o DVDArrayPDriver DVDArrayP.o DVDArrayPDriver.o DVD0.o

DVD0.o: DVD0.h DVD0.cpp
	g++ -g -Wall -c DVD0.cpp

DVDArrayP.o:  DVDArrayP.cpp DVDArrayP.h DVD0.h
	g++ -g -Wall -c DVDArrayP.cpp
	
DVDArrayPDriver.o:  DVDArrayPDriver.cpp DVDArrayP.h DVD0.h
	g++ -g -Wall -c DVDArrayPDriver.cpp