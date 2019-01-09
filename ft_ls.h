/**********************************************/
/* A SIMPLE IMPLEMENTATION OF THE ls COMMAND. */
/* Made by:	Q. Backaert		      */
/* 		q.bckrt@gmail.com	      */
/**********************************************/

#ifndef FT_LS_H
# define FT_LS_H

//colors
# define CMAG "\x1B[35m"
# define RESET "\x1B[0m"

//libraries
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <dirent.h>
# include <sys/stat.h>

//prototypes
int	fname(char *dir);

#endif
