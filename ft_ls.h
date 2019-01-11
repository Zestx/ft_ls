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
# include <sys/types.h>

//prototypes
char	*subdir_path(char *current_path, char *subdir);
int		list(char *dirpath, int indent);
char	*parse_args(int argc, char **argv);

char	*get_stat(mode_t file_mode);
void	get_type(char *buffer, mode_t file_mode);
void	get_perm(char *buffer, mode_t file_mode);

#endif
