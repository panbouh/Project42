#ifndef FT_WUNI_H
# define FT_WUNI_H

# include <wchar.h>
# include <stdlib.h>

# define	MASK_1	"0xxxxxxx"
# define	MASK_2	"110xxxxx10xxxxxx"
# define	MASK_3	"1110xxxx10xxxxxx10xxxxxx"
# define	MASK_4	"11110xxx10xxxxxx10xxxxxx10xxxxxx"

# define	SIZE_M1	7
# define	SIZE_M2	11
# define	SIZE_M3	16
# define	SIZE_M4	21

typedef struct	s_mask_uni
{
	char	*mask;
	size_t	size;
}				t_mask_uni;

/*
**	Print
*/
void				ft_putwstr(const wchar_t *wstr);
void				ft_putnofwstr(const wchar_t *wstr, size_t n);
int					ft_putnbyte(const wchar_t *wstr, size_t n);
int					ft_putwchar(const wchar_t c);

/*
**	Alloc
*/
wchar_t				*ft_wstrdup(const wchar_t *wstr);
int					ft_wstrdel(wchar_t	**wstr);

/*
**	Math
*/
size_t				ft_wstrlen(const wchar_t *wstr);
size_t				ft_wcharlen(const wchar_t c);

/*
** const t_mask_uni	tab[] = 
** {
** 	{"0xxxxxxx\0", 7},
** 	{"110xxxxx10xxxxxx\0", 11},
** 	{"1110xxxx10xxxxxx10xxxxxx\0", 16},
** 	{"11110xxx10xxxxxx10xxxxxx10xxxxxx\0", 21},
** 	{NULL, 0},
** };
*/

#endif