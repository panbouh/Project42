#include "git/get_next_line.h"

#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

void	useless_func(char *buff)
{
	if (buff)
    	printf("Some shit append here\n");
}

int     main(int ac, char **av)
{
	char	buff = (char *)malloc(sizeof(char) * BUFF_SIZE + 1);
	int   fd;

  if (ac != 2)
  {
  	printf("Missing File\n");
  	return (FAIL);
  }
  if ((fd = open(av[1], O_RDONLY)) == -1)
    {
      printf("File not found\n");
      return (-1);
    }

    int rd;
    rd = read(fd, buff, BUFF_SIZE);
    printf("rd = %i\n", rd);
    printf("buff = %s\n\n", buff);
    ft_strclr(buff);
    rd = read(fd, buff, BUFF_SIZE);
    printf("rd = %i\n", rd);
    printf("buff = %s\n", buff);
    useless_func(buff);
    return (0);
}