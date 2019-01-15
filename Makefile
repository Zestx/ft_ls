CC=gcc
CFLAGS= -Wall -Wextra -Werror --pedantic

all: ft_ls clean

ft_ls: ft_ls.o l_display.o util.o
	$(CC) $(CFLAGS) $^ -I. libft.a -o ft_ls

%.o: %.c
	$(CC) $(CFLAGS) -I. -c $^

clean:
	rm -rf *.o

fclean: clean
	rm -rf ft_ls

re: fclean ft_ls
