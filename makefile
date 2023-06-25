SHELL 	= /bin/bash

CFLAG	= -Wall -Wextra #-Werror
CC 	= g++

all:
	${CC} ${CFLAG} main.cpp -o scraper.o
	${CC} ${CFLAG} data_processor/main.cpp -o processor.o
	${CC} ${CFLAG} data_processor/filter/filter.cpp -o filter.o

clean:
	rm -f *.o
