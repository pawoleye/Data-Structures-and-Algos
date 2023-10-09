#;-*-Makefile-*-
LAB=lab5
COURSE=ele428
ARCHIVE=*.c *.h Makefile README *.sh
ARCHFILE=${LAB}.archive
CC = gcc
CFLAGS = -g -Wall

all: validateXML  heap

validateXML: part1Main.o stringStack.o
	gcc $(CFLAGS) -o  validateXML part1Main.o stringStack.o

heap: part2Main.o intHeap.o intStack.o
	gcc $(CFLAGS) -o heap part2Main.o intHeap.o intStack.o

include /home/courses/ele428/bin/Makefile.sub

clean:
	rm -f *~ core a.out *.o validateXML heap *.exe
