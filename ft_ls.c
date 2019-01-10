/**********************************************/
/* A SIMPLE IMPLEMENTATION OF THE ls COMMAND. */
/* Made by:	Q. Backaert		      */
/* 		q.bckrt@gmail.com	      */
/**********************************************/

#include "ft_ls.h"

//This function is basically strcat and strdup combined. it's used to send the nez path to list() if called recursively.
char	*subdir_path(char *current_path, char *subdir)
{
	char	*full_path;
	int		curr_len;
	int		sub_len;
	int		i;
	int		j;

	curr_len = strlen(current_path);
	sub_len = strlen(subdir);
	if ((full_path = malloc(curr_len + sub_len + 2)) == NULL)
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

//Core function, display recursively the entries of a directory.
int		list(char *dirpath, int indent)
{
	struct dirent	*entry;
	DIR		*dir;
	int		i;
	char	etype;

	dir = opendir(dirpath);
	if (dir == NULL)
	{
		printf("error: can't open directory.\n");
		return (-1);
	}
	while ((entry = readdir(dir)) != NULL)
	{
		//prevent displaying hidden files.
		if (entry->d_name[0] != '.')
		{
			//figure out the file type. Need to be done with stat though.
			if (entry->d_type == 4)
				etype = 'd';
			else 
				etype = '-';
			i = 0;
			printf("%c. ", etype);
			//indent the output in regard of our level in the arborescence from the given root directory (dirpath).
			while (i < indent)
			{
				printf("---");
				i++;
			}
			//if one of the entry is another directory, put it in color and display it's content recursively.
			if (entry->d_type == 4)
			{
				printf(CMAG "%s\n" RESET, entry->d_name);
				list(subdir_path(dirpath, entry->d_name), indent + 1);
			}
			//else just print the file name.
			else
				printf("%s\n", entry->d_name);	
		}
	}
	return (0);
}

//This function get all the options in a table.
char	*parse_args(int argc, char **argv)
{
	int		i;
	int		j;
	int		opt_count; //will contain all options set by the user.
	char	*opt_table; //will contain the number of options set by the user.

	//opt_table will contain all the options set by the user. I allocate 41 bytes, enough for all possible ls options.
	if ((opt_table = malloc(41)) == NULL)
	{
		printf("allocation error.\n");
		return (NULL);
	}
	i = 1;
	opt_count = 0;
	while (i < argc && argv[i][0] == '-') //this loop will read through all the arguments as long as they're options ('-x')
	{
		j = 1;
		while (argv[i][j] != '\0') //stocking all the options on this argument into opt_table and updating opt_count.
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
	printf("%s\n", opt_table);
	return (opt_table);
}

int		main(int argc, char **argv)
{
	char *options;

	//if no arguments, list current working directory (cwd) content.
	if (argc == 1)
	{
		if (list(".", 0))
			return (-1);
	}
	//else list all directories specified in arguments.
	else
	{
		options = parse_args(argc, argv);
		//	while (--argc)
		//		if (list(*++argv, 0))
		//			return (-1);
	}
	return (0);
}
