#include "get_next_line.h"
#include <fcntl.h>

int main(int ac, char **av)
{
  char **line = NULL;
  int fd;

  if (ac != 2)
    {ft_putstr_fd("Use : ./gnl [FILE]\n", 2); return (FAIL);}
  if ((fd = open(av[1], O_RDONLY)) == -1)
    {ft_putstr_fd("No file Found\n", 2); return (FAIL);}

  get_next_line(fd, line);

  //printf("line : %s\n", line);

  // ft_strdel(&line);
  return (0);
}
