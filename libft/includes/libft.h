/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccatoire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 14:29:42 by ccatoire          #+#    #+#             */
/*   Updated: 2017/05/16 14:29:47 by ccatoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

/*
** #############
** #  INCLUDE  #
** #############
*/

# include <stdlib.h>
// # include <string.h>
// # include <stdio.h>
// # include <ctype.h>
// # include <unistd.h>
// # include <fcntl.h>

/*
** ###########
** #  MACRO  #
** ###########
*/

# define BUFF_MAX	4242
# define FAIL		-1
# define OK			0
# define TILL		96
# define ALL		69
# define SKIP		9
# define STOP		1
# define GO			3
# define BOUH		ft_printf("bouh\n");

/*
** ###############
** #  STRUCTURE  #
** ###############
*/

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

/*
** ###############
** #  PROTOTYPE  #
** ###############
*/

/*
** checking
*/
int					ft_isspace(char c);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);

/*
** list
*/
t_list				*ft_lstnew(const void *content, size_t content_size);
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
/*

** math
*/
size_t				ft_skip_char(const char *s, size_t i, char c, int flags);
size_t				ft_count_word(const char *str, char space);
size_t				ft_count_digit(int n);
size_t				ft_count_ldigit(long n);
size_t				ft_count_lldigit(long long n);
size_t				ft_count_udigit(unsigned long n);
size_t				ft_count_umaxdigit(unsigned long n);
size_t				ft_count_imaxdigit(intmax_t n);
uintmax_t			ft_abs_imax(intmax_t n);
unsigned int		ft_conv_fbase(char *nb, int base);
unsigned int		ft_abs(int n);
uintmax_t			ft_abs_imax(intmax_t n);
unsigned long		ft_abs_l(long n);
long				ft_power(long nb, long power);
unsigned long long	ft_abs_ll(long long n);
char				*ft_conv_nbase(int n, unsigned int base);
char				*ft_convu_nbase(unsigned int n, unsigned int base);
char				*ft_convlu_nbase(unsigned long long n, unsigned int base);
char				*ft_convimax_nbase(intmax_t n, unsigned int base);
char				*ft_convumax_nbase(uintmax_t n, unsigned int base);
char				*ft_addbit(char *bin);
/*
** memmory
*/
void				ft_bzero(void *s, size_t n);
void				ft_memdel(void **ap);
void				ft_memswap(void **a, void **b);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memset(void *s, int c, size_t n);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_memdup(const void *src, size_t size);
void				*ft_memalloc(size_t size);

/*
** morphing
*/
int					ft_toupper(int c);
char				*ft_strlower(char *str);
int					ft_tolower(int c);
long				ft_atoi(const char *str);
char				*ft_itoa(int n);

/*
** print
*/
void				ft_putchar(char c);
void				ft_putstr(const char *str);
void				ft_putendl(const char *str);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(const char *str, int fd);
void				ft_putendl_fd(const char *str, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_putstab(const char **tab);
void				ft_puttab(const int *tab, size_t size);
void				ft_putdtab(const int **tab, size_t x, size_t y);
void				ft_putnchar(char c, size_t n);
void				ft_putnofstr(const char *str, size_t n);
void				ft_putlnbr_fd(long long nb, int fd);
void				ft_putlnbr(long long nb);
void				ft_putunbr_fd(unsigned long long nb, int fd);
void				ft_putunbr(unsigned long long nb);
void				ft_putumaxnbr(uintmax_t nb);
void				ft_putumaxnbr_fd(uintmax_t nb, int fd);
void				ft_putimaxnbr(intmax_t nb);
void				ft_putimaxnbr_fd(intmax_t nb, int fd);
void				ft_putnchar_fd(char c, size_t n, int fd);
int					ft_error(char *message, int error);

/*
** str
*/
void				ft_strclr(char *s);
void				ft_striter(char *c, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
size_t				ft_strlen(const char *s);
size_t				ft_strlen_till(const char *s, char stop);
size_t				ft_strlen_c(const char *str, char c);
size_t				ft_strlen_till_skipspace(const char *str, char stop);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_strequ(const char *s1, const char *s2);
int					ft_strnequ(const char *s1, const char *s2, size_t n);
int					ft_strdel(char **as);
int					*ft_strtotab(const char *str, size_t *size);
char				*ft_strrev(char *str);
char				*ft_strupper(char *str);
char				*ft_strsub_to(const char *s, unsigned int start, char stop);
char				*ft_strtrim_full(const char *);
char				*ft_strdup(const char *s);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strncpy(char *dest, const char *src, size_t n);
char				*ft_strcat(char *dest, const char *src);
char				*ft_strncat(char *dest, const char *src, size_t n);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *str, const char *to_find);
char				*ft_strnstr(const char *str, const char *to_find, size_t n);
char				*ft_strnew(size_t size);
char				*ft_strmap(const char *s, char (*f)(char));
char				*ft_strmapi(const char *s, char (*f)(unsigned int, char));
char				*ft_strsub(const char *s, unsigned int start, size_t len);
char				*ft_strjoin(const char *s1, const char *s2);
char				*ft_strtrim(const char *s);
char				*ft_strmiam(char *str, char stop);
char				**ft_strsplit(const char *s, char c);

/*
** tab
*/
void				ft_tabdel(void **tab);
size_t				ft_tablen(char **tab);
void				**ft_tabdup(void **src, size_t size);
char				**ft_tabsdup(char **src);
char				**ft_tabcpy(char **src, char **dest);
int					**ft_tabnew(int x, int y);

#endif
