/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbackaer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 06:36:57 by qbackaer          #+#    #+#             */
/*   Updated: 2019/01/15 07:00:08 by qbackaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		list(char *dirpath, char *options)
{
	struct dirent	*entry;
	DIR				*dir;
	t_list			*entries_list;
	t_list			*entry_ptr;

	entries_list = ft_lstnew(NULL, 0);
	if ((dir = opendir(dirpath)) == NULL)
		return (-1);
	while ((entry = readdir(dir)) != NULL)
	{
		if (entry->d_name[0] != '.' || (options && ft_strchr(options, 'a')))
			ft_lstadd(&entries_list,
					ft_lstnew(newnode(entry->d_name), sizeof(t_entry)));
	}
	entry_ptr = entries_list;
	while (entry_ptr->content != NULL)
	{
		display_wpr(entry_ptr->content, options);
		entry_ptr = entry_ptr->next;
	}
	closedir(dir);
	return (0);
}

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

int		main(int argc, char **argv)
{
	char	*options;

	options = NULL;
	if (argc > 1)
	{
		if (!(options = parse_args(argc, argv)))
			return (-1);
		if (check_opts("Ralst", options))
			return (-1);
	}
	if (list(".", options))
		return (-1);
	return (0);
}
