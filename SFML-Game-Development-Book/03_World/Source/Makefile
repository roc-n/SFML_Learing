CC = gcc
CPP = g++
RM = rm -rf

DBG_ENABLE = 1

SRC_PATH := ./Source

TARGET := main.exe

OBJS_DIR := Objs

SRCS := $(wildcard $(SRC_PATH)/*cpp)

SRCS_NO_DIR := $(notdir $(wildcard $(SRC_PATH)/*cpp))

OBJS := $(SRCS_NO_DIR:%.cpp=$(OBJS_DIR)/%.o)


LIBS := .

INCLUDE_PATH := ./Include

# LIBRARY_PATH := D:/Env/SFML/SFML-2.5.1/bin

ifeq (1,${DBG_ENABLE})
CFLAGS += -D_DEBUG -O0 -g -DDEBUG=1
endif

CFLGS += $(foreach dir,(INCLUDE_PATH), -I(dir))
# LIBRARY_PATH += $(foreach lib,(LIBRARY_PATH),-L(lib))
# LDFLAGS += $(foreach lib,(LIBS),-l(lib))

all:	build

build: $(OBJS)
	$(CPP) $(CFLAGS) -o $(TARGET) $(OBJS) -lsfml-graphics-d-2 -lsfml-system-d-2 -lsfml-window-d-2

$(OBJS): %.o : %.cpp
	$(CPP) -c -o $@ $(CFLAGS) $<
	
clean:
	$(RM) $(OBJS) $(TARGET)