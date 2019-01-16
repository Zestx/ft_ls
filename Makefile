CC=gcc
CFLAGS= -Wall -Wextra -Werror --pedantic -g -O0

all: ft_ls clean

ft_ls: ft_ls.o getstat.o display.o util.o
	$(CC) $(CFLAGS) $^ -I. libft.a -o ft_ls

%.o: %.c
	$(CC) $(CFLAGS) -I. -c $^

clean:
	rm -rf *.o

fclean: clean
	rm -rf ft_ls

re: fclean all
