/**********************************************/
/* A SIMPLE IMPLEMENTATION OF THE ls COMMAND. */
/* Made by:	Q. Backaert		      */
/* 		q.bckrt@gmail.com	      */
/**********************************************/

#include "dirent.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define CMAG "\x1B[35m"
#define RESET "\x1B[0m"

//this function is basically strcat and strdup combined. it's used to send the nez path to list() if called recursively.
//(not necessary??)
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


//core function, display recursively the entries of a directory.
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

int		main(int argc, char **argv)
{
	//if no arguments, list current working directory (cwd) content.
	if (argc == 1)
	{
		if (list(".", 0))
			return (-1);
	}
	//else list all directories specified in arguments.
	else 
	{
		while (--argc)
			if (list(*++argv, 0))
				return (-1);
	}
	return (0);
}
