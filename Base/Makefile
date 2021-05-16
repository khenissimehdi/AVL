CC=gcc
CFLAGS=-Wall -ansi
LDFLAGS=-lm
DEPS=visualtree.h tree.h avl.h
OBJ=visualtree.o tree.o avl.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

tp09: tp09.o $(OBJ)
	gcc -o $@ $^ $(LDFLAGS)

.PHONY: clean
clean:
	rm -f $(OBJ) tp09 tp09.o current-tree.dot current-tree.pdf