/**********************************************/
/* A SIMPLE IMPLEMENTATION OF THE ls COMMAND. */
/* Made by:	Q. Backaert                       */
/* 		q.bckrt@gmail.com                     */
/**********************************************/
 
#include "ft_ls.h"


t_entry		*newnode(char *filename, char *options)
{
	t_entry	*new_node;

	new_node = (t_entry*)malloc(sizeof(t_entry));
	if (!new_node)
		return (NULL);
	stat(filename, &(new_node->filestat));
	new_node->filename = filename;
	new_node->next = NULL;

	return (new_node);
}

//Core function, display recursively the entries of a directory.
int		list(char *dirpath, char *options)
{
	struct dirent	*entry;
	DIR				*dir;
	t_list			*entries_list;
	t_list			*entry_ptr;
	int				entry_count;
	int i;

	entries_list = ft_lstnew(NULL, 0);
	if ((dir = opendir(dirpath)) == NULL)
		return (-1);
	entry_count = 0;
	while ((entry = readdir(dir)) != NULL)
	{
		if (entry->d_name[0] != '.' || (options && ft_strchr(options, 'a')))
		{
			ft_lstadd(&entries_list, 
					ft_lstnew(newnode(entry->d_name, options), sizeof(t_entry)));
			entry_count++;
		}
	}
	entry_ptr = entries_list;
	i = 0;
	while(entry_ptr->content != NULL)
	{
		display_wpr(entry_ptr->content, options);
		entry_ptr = entry_ptr->next;
		i++;
	}
	//free the list here.. (ft_lstdel + del function/pointer)
	closedir(dir);
	return (0);
}

void	display_wpr(t_entry *entry, char *options)
{
	if (options && ft_strchr(options, 'l'))
		display_stats(entry->filename, &(entry->filestat), 1);
	else
		display_stats(entry->filename, &(entry->filestat), 0);
}

//This function get all the options in a table.
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

//This function checks if the options are valid.
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

//Main.
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
