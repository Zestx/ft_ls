CC=gcc
CFLAGS= -Wall -Wextra -Werror --pedantic

all: ft_ls

ft_ls: ft_ls.o
	$(CC) $(CFLAGS) $^ -I. -o ft_ls

%.o: %.c
	$(CC) $(CFLAGS) -I. -c $^

clean:
	rm -rf *.o

fclean: clean
	rm -rf ft_ls
