/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbackaer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 19:45:31 by qbackaer          #+#    #+#             */
/*   Updated: 2019/01/16 17:42:07 by qbackaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

//return a new path from a current path and a subdirectory:
//ex:
//subdir_path("./directory", "subdirectory");
//will return "./directory/subdirectory"
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

//creates and fill a new t_entry struct.
t_entry	*newnode(char *path, char *filename)
{
	t_entry *new_node;

	new_node = (t_entry*)malloc(sizeof(t_entry));
	if (!new_node)
		return (NULL);
	stat(path, &(new_node->filestat));
	new_node->filename = filename;
	return (new_node);
}

//free linked lists.
void	free_list(t_list *entries)
{
	t_list *n_node;

	if (!entries)
		return ;
	while (entries)
	{
		n_node = entries->next;
		free(entries->content);
		free(entries);
		entries = n_node;
	}
	entries = NULL;
}
