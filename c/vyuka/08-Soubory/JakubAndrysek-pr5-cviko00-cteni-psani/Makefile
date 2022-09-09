
NAME=pr5-cviko00-cteni-psani

DEBUGER=kdbg
CC=gcc
CFLAGS=-std=c99 -Wall -pedantic -Wextra -g

$(NAME): $(NAME).c
	$(CC) $(CFLAGS) $(NAME).c -lm -o $(NAME)

run:
	./$(NAME)

debug: $(NAME)
	$(DEBUGER) $(NAME)

clean:
	rm -f *~ $(NAME) *.bak *.o

edit:
	kate $(NAME).c

