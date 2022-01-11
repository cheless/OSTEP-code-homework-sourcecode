FLAGS 		= -Wall -pthread
INCLUDES 	= ../include
FNAME 	= thread_create_with_return_args

all: t0

t0: $(FNAME).c
	gcc -I $(INCLUDES) -o b_$(FNAME) $(FNAME).c $(FLAGS)

clean:
	rm b_*
