FLAGS = -Wall -pthread
INCLUDES = ../include
FILE01 = example

all: file01

file01: $(FILE01).c
	gcc $(FILE01).c -I $(INCLUDES) -o b_$(FILE01) $(FLAGS)
	./b_$(FILE01)
