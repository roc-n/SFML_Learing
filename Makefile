SRCS = Game.cpp main.cpp
TARG = main
CC= g++
OPTS = -Wall -O2
LIBS = -lsfml-graphics-d-2 -lsfml-system-d-2 -lsfml-window-d-2

OBJS = $(SRCS:.cpp=.o)
all: $(TARG)
$(TARG):  $(OBJS)
	$(CC) -o  $(TARG) $(OBJS) $(OPTS) $(LIBS)

clean:
	rm -f $(OBJS) $(TARG)