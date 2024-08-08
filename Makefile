TARGET = dicionario
CC = gcc
CFLAGS = -Wall -g

$(TARGET): main.o tree.o
	$(CC) $(CFLAGS) -o $(TARGET) main.o tree.o

main.o: main.c tree.h
	$(CC) $(CFLAGS) -c main.c

tree.o: tree.c tree.h
	$(CC) $(CFLAGS) -c tree.c

clean:
	rm -f $(TARGET) *.o
