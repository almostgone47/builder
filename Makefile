CC = g++
CPPFLAGS = -std=c++17 -Wall -g

builders: builders.o builder.o linkedlist.o request.o stack.o structuretype.o

builders.o: builders.cpp

builder.o: builder.cpp builder.h

linkedlist.o: linkedlist.cpp linkedlist.h

request.o: request.cpp request.h

stack.o: stack.cpp stack.h

structuretype.o: structuretype.cpp structuretype.h

clean:
	rm *.o builders