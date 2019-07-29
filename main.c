#include "main.h"

int 	tetr_read(int fd)
{
	char	str[21];
	int		was_read;

	if ((was_read = read(fd, str, 30)) != 21)
		return (-1); //not valid file
	printf("was_read = %d", was_read);
	return (0);
}

int		main(int argv, char **argc)
{
	int		fd;
	int 	i;

	i = 0;
	printf("argv = %d\nargc[0] = %s\nargc[1] = %s\n", argv, argc[i], argc[i + 1]);
	if (argv == 1)
		return (-1); //EXIT
	while (argv > 1)
	{
		argc++;
		if ((fd = open(*argc, O_RDONLY)) < 3 || tetr_read(fd) == -1)
			return (-1); //EXIT
		argv--;
	}
	return (0);
}