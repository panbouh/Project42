#include "libft.h"
#include "ft_wuni.h"

const t_mask_uni	g_masktab_put[] = 
{
	{"0xxxxxxx\0", 7},
	{"110xxxxx10xxxxxx\0", 11},
	{"1110xxxx10xxxxxx10xxxxxx\0", 16},
	{"11110xxx10xxxxxx10xxxxxx10xxxxxx\0", 21},
	{NULL, 0},
};

static	char *add_mask(char *bin, size_t size)
{
	char	*new;
	size_t	y;
	size_t	x;

	y = 0;
	x = 0;
	new = ft_strdup(g_masktab_put[size].mask);
	new = ft_strrev(new);
	bin = ft_strrev(bin);
	while (new[x])
	{
		if (new[x] == 'x' && bin[y])
			new[x] = bin[y++];
		else if (new[x] == 'x' && !bin[y])
			new[x] = '0';
		x++;
	}
	ft_strdel(&bin);
	return (ft_strrev(new));
}

static unsigned int	get_byte(char *bin, size_t i)
{
	char		byte[424242];
	unsigned int	n;
	int				count;
	size_t			y;

	y = 0;
	count = 0;
	ft_bzero(byte, 424242);
	while (count < 8)
	{
		byte[y++] = bin[i++];
		count++;
	}
	n = ft_conv_fbase(byte, 2);
	return (n);
}

int	ft_putwchar(const wchar_t c)
{
	char			*conv;
	size_t			i;
	size_t			size;
	int				ret;
	unsigned int	byte;

	conv = ft_conv_nbase(c, 2);
	if ((size = ft_wcharlen(c)) == 1)
		{
			ft_putchar(c);
			ft_strdel(&conv);
			return (size);
		}
	conv = add_mask(conv, size - 1);
	i = 0;
	ret = size;
	while (size != 0)
	{
		byte = get_byte(conv, i);
		write(1, &byte, 1);
		i += 8;
		size--;
	}
	ft_strdel(&conv);
	return (ret);
}


