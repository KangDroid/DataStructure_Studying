CC=g++
CFLAGS=-Wall -O3 -std=c++2a
TARGET=app.out
OBJS= main.o
	
%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

all: $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

clean:
	rm -rf ./*.out ./*.o