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

int	list_main(char *dirpath)
{
	struct dirent	*entry;
	struct stat		filestats;
	DIR				*dir;
	char		*mode;

	dir = opendir(dirpath);
	while (dir && (entry = readdir(dir)))
	{
		if (entry->d_name[0] != '.')
		{
			display_stats(entry->d_name);
			putchar('\n');
		}
	}
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc == 1)
		list_main(".");
	else
		list_main(argv[1]);
	return (0);
}
