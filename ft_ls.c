/**********************************************/
/* A SIMPLE IMPLEMENTATION OF THE ls COMMAND. */
/* Made by:	Q. Backaert		      */
/* 		q.bckrt@gmail.com	      */
/**********************************************/

#include "dirent.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int	putstr(char *str)
{
	if (!str)
		return (-1);
	while (*str)
		putchar(*str++);
	return (0);
}

int	ls(char *dirpath)
{
	struct dirent	*d;
	DIR		*dir;

	dir = opendir(dirpath);
	if (!dir)
	{
		putstr("error: can't open directory.\n");
		return (-1);
	}
	while ((d = readdir(dir))) {
		if (d->d_name[0] != '.') {
			putstr(d->d_name);
			putstr("  ");
		}
	}
	putchar('\n');
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc == 1)
		if (ls("."))
			return (-1);
	else
		while (--argc)
			if (ls(*++argv))
				return (-1);
	return (0);
}
