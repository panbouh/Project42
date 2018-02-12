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
# include <string.h>
# include <stdio.h>
# include <ctype.h>
# include <unistd.h>
# include <sys/types.h>
# include <fcntl.h>

# include "get_next_line.h"

/*
** ###########
** #  MACRO  #
** ###########
*/

# define FAIL	-1
# define OK		0
# define TILL	96
# define ALL	69
# define STOP	1
# define GO		3

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
**
** ---libperso---
*/
char				*ft_strrev(char *str);
char				*ft_conv_nbase(int n, unsigned int base);
char				*ft_convu_nbase(unsigned int n, unsigned int base);
char				*ft_convlu_nbase(unsigned long long n, unsigned int base);
char				*ft_convimax_nbase(intmax_t n, unsigned int base);
char				*ft_convumax_nbase(uintmax_t n, unsigned int base);
char				*ft_strupper(char *str);
char				*ft_strsub_to(const char *s, unsigned int start, char stop);
char				*ft_strtrim_full(const char *);
char				*ft_addbit(char *bin);

size_t				ft_skip_char(const char *s, size_t i, char c, int flags);
size_t				ft_count_word(const char *str, char space);
size_t				ft_count_digit(int n);
size_t				ft_count_ldigit(long n);
size_t				ft_count_lldigit(long long n);
size_t				ft_count_udigit(unsigned long n);
size_t				ft_count_umaxdigit(unsigned long n);
size_t				ft_count_imaxdigit(intmax_t n);
uintmax_t			ft_abs_imax(intmax_t n);
size_t				ft_strlen_till(const char *s, char stop);

long				ft_power(long nb, long power);
unsigned long		ft_abs_l(long n);
unsigned long long	ft_abs_ll(long long n);
unsigned int		ft_abs(int n);
uintmax_t			ft_abs_imax(intmax_t n);
unsigned int		ft_conv_fbase(char *nb, int base);

void				ft_puttab(const char **tab);
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


/*
** ---libsujet---
*/
void				ft_bzero(void *s, size_t n);
void				ft_memdel(void **ap);
void				ft_strclr(char *s);
void				ft_striter(char *c, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
void				ft_putchar(char c);
void				ft_putstr(const char *str);
void				ft_putendl(const char *str);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(const char *str, int fd);
void				ft_putendl_fd(const char *str, int fd);
void				ft_putnbr_fd(int n, int fd);

char				**ft_strsplit(const char *s, char c);

void				*ft_memset(void *s, int c, size_t n);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_memalloc(size_t size);

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
char				*ft_itoa(int n);

int					ft_memcmp(const void *s1, const void *s2, size_t n);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
int					ft_strequ(const char *s1, const char *s2);
int					ft_strnequ(const char *s1, const char *s2, size_t n);
int					ft_strdel(char **as);

long				ft_atoi(const char *str);

size_t				ft_strlen(const char *s);
size_t				ft_strlcat(char *dst, const char *src, size_t size);

/*
** ---libbonus---
*/
t_list				*ft_lstnew(const void *content, size_t content_size);
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));

#endif
