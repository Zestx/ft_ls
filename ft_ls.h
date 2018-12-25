/**********************************************/
/* A SIMPLE IMPLEMENTATION OF THE ls COMMAND. */
/* Made by:	Q. Backaert		      */
/* 		q.bckrt@gmail.com	      */
/**********************************************/

#ifndef
# define FT_LS_H

# define NAME_MAXLEN 14

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <dirent.h>
# include <sys/stat.h>

int	fname(char *dir);

#endif
