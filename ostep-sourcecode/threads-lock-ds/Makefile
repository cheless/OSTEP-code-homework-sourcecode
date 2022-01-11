FLAGS = -Wall -pthread
INCLUDES = ../include

all: counter run

counter: counter.c
	gcc counter.c -I $(INCLUDES) -o b_counter $(FLAGS)
	./b_counter

counter-with-lock: counter-with-lock.c
	gcc counter-with-lock.c -I $(INCLUDES) -o b_counter-with-lock $(FLAGS)
	./b_counter-with-lock
