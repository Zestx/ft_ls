/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbackaer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 06:36:57 by qbackaer          #+#    #+#             */
/*   Updated: 2019/01/16 18:23:23 by qbackaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

//this function reads a directory stream and creates a linked list containing all its entries,
//and their associated stats.
void	read_create_list(t_list **entry_list, DIR *dir, char *path, char *options)
{
	struct dirent 	*entry;
	char			*new_path;

	while ((entry = readdir(dir)) != NULL)
	{
		new_path = subdir_path(path, entry->d_name);
		if (entry->d_name[0] != '.' || (options && ft_strchr(options, 'a'))) 
			ft_lstadd(entry_list,
					ft_lstnew(newnode(new_path, entry->d_name), sizeof(t_entry)));
	}
}
//test if the "current" entry is a directory and if so, call list() (recursively).
void	recursive_wpr(t_entry *entry, char *path, char *options)
{
	char		*subpath;

	if (S_ISDIR(entry->filestat.st_mode))
	{
		ft_putchar('\n');
		subpath = subdir_path(path, entry->filename);
		list(subpath, options);
	}
}

//core function. open a directory, then use read_create_list() and display_wpr() to display it's content.
//if the -R option is set, list() will use recursive_wpr() to call itself recursively on the subdirectory.
int		list(char *dirpath, char *options)
{
	DIR				*dir;
	t_list			*entries_list;
	t_list			*entry_ptr;

	printf("%s :\n", dirpath);
	entries_list = NULL;
	if ((dir = opendir(dirpath)) == NULL)
		exit(EXIT_FAILURE);
	read_create_list(&entries_list, dir, dirpath, options);
	entry_ptr = entries_list;
	while (entry_ptr)
	{
		display_wpr(entry_ptr->content, options);
		if (options && strchr(options, 'R'))
			recursive_wpr(entry_ptr->content, dirpath, options);
		entry_ptr = entry_ptr->next;
	}
	printf("\n");
	free_list(entries_list);
	closedir(dir);
	return (0);
}

//get all the options.
char	*parse_args(int argc, char **argv)
{
	int		i;
	int		j;
	int		opt_count;
	char	*opt_table;

	if ((opt_table = malloc(41)) == NULL)
		return (NULL);
	i = 1;
	opt_count = 0;
	while (i < argc && argv[i][0] == '-' && strcmp(argv[i], "--"))
	{
		j = 1;
		while (argv[i][j] != '\0')
		{
			if (!strchr(opt_table, argv[i][j]))
			{
				opt_table[opt_count] = argv[i][j];
				opt_table[opt_count + 1] = '\0';
				opt_count++;
			}
			j++;
		}
		i++;
	}
	return (opt_table);
}

//check if the options sets are valid.
int		check_opts(char *valid_opt, char *opt_table)
{
	while (*opt_table != '\0')
	{
		if (!strchr(valid_opt, *opt_table))
		{
			printf("error: -%c is not a valid options.\n", *opt_table);
			return (-1);
		}
		opt_table++;
	}
	return (0);
}

//MAIN. The program only supports options as arguments yet, no directories.
int		main(int argc, char **argv)
{
	char	*options;

	options = NULL;
	if (argc > 1)
	{
		if (!(options = parse_args(argc, argv)))
			exit(EXIT_FAILURE);
		if (check_opts("Ralst", options))
			exit(EXIT_FAILURE);
	}
	if (list(".", options))
		exit(EXIT_FAILURE);
	return (0);
}
