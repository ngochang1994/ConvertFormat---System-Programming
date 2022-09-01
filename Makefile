# Thi Tran
# RedID: 825223653
# CS 530 - Systems Programming, Spring 2022
# Prof: G. Leonard
# Project #1


# The compiler: gcc for C program, g++ for C++ program
CC = gcc

#compiler flags:
# -g	adds debugging information to the executable file
#  -Wall turns on compiler warnings
CFLAGS = -g -Wall

# build target executable
TARGET = xed

# Specify how to compile the target
all: $(TARGET)
$(TARGET): $(TARGET).c
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).c

# To start over, type 'make clean'
# This removes the executable file and .o object file
clean :
	rm count *.o


