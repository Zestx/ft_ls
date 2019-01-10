/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_test.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbackaer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 20:34:16 by qbackaer          #+#    #+#             */
/*   Updated: 2019/01/10 21:08:41 by qbackaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ls(char *dirpath)
{
	struct dirent	*entry;
	struct stat		filestats;
	DIR				*dir;

	dir = opendir(dirpath);
	while (dir && (entry = readdir(dir)))
	{
		stat(entry->d_name, &filestats);
		if (S_ISDIR(filestats.st_mode))
		{
			printf("d	");
		}
		else
		{
			printf("-	");
		}
		printf("%s\n", entry->d_name);
	}
	return (0);
}

int		main(int argc, char **argv)
{
	if (argc == 1)
		ls(".");
	else
		ls(argv[1]);
	return (0);
}
