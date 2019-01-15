/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbackaer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 19:45:31 by qbackaer          #+#    #+#             */
/*   Updated: 2019/01/15 07:02:18 by qbackaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

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

t_entry	*newnode(char *filename)
{
	t_entry *new_node;

	new_node = (t_entry*)malloc(sizeof(t_entry));
	if (!new_node)
		return (NULL);
	stat(filename, &(new_node->filestat));
	new_node->filename = filename;
	new_node->next = NULL;
	return (new_node);
}
