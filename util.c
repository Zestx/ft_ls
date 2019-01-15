/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbackaer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 19:45:31 by qbackaer          #+#    #+#             */
/*   Updated: 2019/01/15 03:38:01 by qbackaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*This file contains utilitary functions for ft_ls.*/

#include "ft_ls.h"

//This function is simply put strcat and strdub combined. It creates a subdirectory path.
char	*subdir_path(char *current_path, char *subdir)
{
	char	*full_path;
	int		i;
	int		j;

	if (!(full_path = malloc(strlen(current_path) + strlen(subdir) + 2)))
		return (NULL);
	i = 0;
	while (current_path[i] != '\0')
	{
		full_path[i] = current_path[i];
		i++;
	}
	full_path[i] = '/';
	i++;
	j = 0;
	while (subdir[j] != '\0')
	{
		full_path[i + j] = subdir[j];
		j++;
	}
	full_path[i + j] = '\0';
	return (full_path);
}

char	**add_entry(char **old_table, char *new_entry, int size)
{
	char **new_table;
	int i;

	if (!(new_table = malloc(sizeof(new_table) * size + 2)))
		return (NULL);
	i = 0;
	while (i < size)
	{
		new_table[i] = strdup(old_table[i]);
		free(old_table[i]);
		i++;
	}
	new_table[i] = strdup(new_entry);
	free(old_table[i]);
	free(old_table);
	new_table[i + 1] = "\0";

	return (new_table);
}
