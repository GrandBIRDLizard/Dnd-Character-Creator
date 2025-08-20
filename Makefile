CC     = gcc
CFLAGS = -Wall -Wextra -std=c99 -Iinclude -g
LDFLAGS = -lraylib -lm -ldl -lpthread -lGL

SRC  = $(wildcard src/*.c)
OBJ  = $(SRC:.c=.o)

TARGET = DnDGUI

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET) $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)

.PHONY: all clean


