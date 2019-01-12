/* This file contain the functions used for long display (-l option) */

#include "ft_ls.h"

void	putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		putchar(str[i]);
		i++;
	}	
}

int	display_stats(char *filename)
{
	struct stat	filestats;

	stat(filename, &filestats);
	putstr(get_mode(filestats.st_mode));
	putstr(" ");
	printf("%d", filestats.st_nlink); //use ft_putnbr;
	putstr(" ");
	putstr(get_usrname(filestats.st_uid));
	putstr(" ");
	putstr(get_grpname(filestats.st_gid));
	putstr(" ");
	printf("%d ", filestats.st_size);
	putstr(filename);
	return (0);
}

char	*get_usrname(uid_t user_id)
{
	struct	passwd *usr_stats;

	usr_stats = getpwuid(user_id);
	return(usr_stats->pw_name);
}

char	*get_grpname(gid_t group_id)
{
	struct group *grp_stats;

	grp_stats = getgrgid(group_id);
	return (grp_stats->gr_name);
}

char	*get_mode(mode_t file_mode)
{
	int i;
	char *mode_str;

	mode_str = malloc(11);
	if (mode_str == NULL)
		return (NULL);
	i = 0;
	while (i < 10)
	{
		mode_str[i] = '-';
		i++;
	}
	mode_str[10] = '\0';
	get_type(mode_str, file_mode);
	get_perm(mode_str, file_mode);
	return (mode_str);
}

void	get_type(char *buffer, mode_t file_mode)
{
	if (S_ISDIR(file_mode))
		buffer[0] = 'd';
	if (S_ISCHR(file_mode))
		buffer[0] = 'c';
	if (S_ISBLK(file_mode))
		buffer[0] = 'b';
	if (S_ISREG(file_mode))
		buffer[0] = '-';
	if (S_ISFIFO(file_mode))
		buffer[0] = 'p';
	if (S_ISLNK(file_mode))
		buffer[0] = 'l';
	if (S_ISSOCK(file_mode))
		buffer[0] = 's';
}

void	get_perm(char *buffer, mode_t file_mode)
{
	if (file_mode & S_IRUSR)
		buffer[1] = 'r';
	if (file_mode & S_IWUSR)
		buffer[2] = 'w';
	if (file_mode & S_IXUSR)
		buffer[3] = 'x';
	if (file_mode & S_IRGRP)
		buffer[4] = 'r';
	if (file_mode & S_IWGRP)
		buffer[5] = 'w';
	if (file_mode & S_IXGRP)
		buffer[6] = 'x';
	if (file_mode & S_IROTH)
		buffer[7] = 'r';
	if (file_mode & S_IWOTH)
		buffer[8] = 'w';
	if (file_mode & S_IXOTH)
		buffer[9] = 'x';
}
