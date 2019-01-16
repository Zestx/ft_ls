/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbackaer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 21:36:16 by qbackaer          #+#    #+#             */
/*   Updated: 2019/01/16 17:03:51 by qbackaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# define CMAG "\x1B[35m"
# define RESET "\x1B[0m"

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <dirent.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <pwd.h>
# include <grp.h>
# include "./libft/libft.h"

typedef struct	s_entry
{
	char			*filename;
	struct stat		filestat;
}				t_entry;

int				list(char *dirpath, char *options);
void			read_create_list(t_list **entry_list, DIR *dir, char *path, char *options);
char			*parse_args(int argc, char **argv);
int				display_entry(char *fname, struct stat *fstat, int l_nmode);
char			*get_mode(mode_t file_mode);
char			*get_usrname(uid_t user_id);
char			*get_grpname(gid_t groupd_id);
void			get_type(char *buffer, mode_t file_mode);
void			get_perm(char *buffer, mode_t file_mode);
void			display_wpr(t_entry *entry, char *options);
t_entry			*newnode(char *path, char *filename);
char			*subdir_path(char *current_path, char *subdir);
void			free_list(t_list *entries);

#endif
