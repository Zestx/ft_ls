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
# include <pwd.h>
# include <grp.h>

//prototypes
void	putstr(char *str);

char	*subdir_path(char *current_path, char *subdir);
int	list(char *dirpath, int indent);
char	*parse_args(int argc, char **argv);

int	display_stats(char *filename);
char	*get_mode(mode_t file_mode);
char    *get_usrname(uid_t user_id);
char	*get_grpname(gid_t groupd_id);
void	get_type(char *buffer, mode_t file_mode);
void	get_perm(char *buffer, mode_t file_mode);

#endif
