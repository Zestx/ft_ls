/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbackaer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 21:36:16 by qbackaer          #+#    #+#             */
/*   Updated: 2019/01/15 06:27:07 by qbackaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**********************************************/
/* A SIMPLE IMPLEMENTATION OF THE ls COMMAND. */
/* Made by:	Q. Backaert		      */
/* 		q.bckrt@gmail.com	      */
/**********************************************/

#ifndef FT_LS_H
# define FT_LS_H

//COLORS
# define CMAG "\x1B[35m"
# define RESET "\x1B[0m"

//LIBRARIES
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <dirent.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <pwd.h>
# include <grp.h>
# include "./libft/libft.h"

//STRUCTURES
typedef struct	s_entry
{
	char			*filename;
	struct stat		filestat;
	struct s_entry	*next;
}				t_entry;				

//PROTOTYPES
void	putstr(char *str);
char	*subdir_path(char *current_path, char *subdir);
int		list(char *dirpath, char *options);
char	*parse_args(int argc, char **argv);
int		display_stats(char *fname, struct stat *fstat, int l_nmode);
char	*get_mode(mode_t file_mode);
char    *get_usrname(uid_t user_id);
char	*get_grpname(gid_t groupd_id);
void	get_type(char *buffer, mode_t file_mode);
void	get_perm(char *buffer, mode_t file_mode);
void	display_wpr(t_entry *entry, char *options);
char	**add_entry(char **old_table,char *new_entry, int size);
t_entry	*newnode(char *filename, char *options);
#endif
