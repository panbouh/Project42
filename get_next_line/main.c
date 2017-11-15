#include "git/get_next_line.h"

#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int get_next_line(int fd, char **line);

int     main(int ac, char **av)
{
  char *line = NULL;
  int   fd;

  if (ac != 2 || !(av[1]))
  {
    printf("Missing File\n");
    return (FAIL);
  }
  if ((fd = open(av[1], O_RDONLY)) == -1)
    {
      printf("File not found\n");
      return (-1);
    }
    int   ret = GO;
    while (ret != RD_END)
    {
    ret = get_next_line(fd, &line);
    ft_putendl(line);
    ft_strdel(&line);
    }
  close(fd);
  return (0);
}
