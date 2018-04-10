#include "ft_ls.h"

static void add_maj(char *buff, dev_t d)
{
	char	*tmp;
	int	pad;
	size_t	i;
	int		m;

	i = 0;
	pad = 0;
	m = major(d);
	// ft_printf("major : %i\n", m);
	tmp = ft_itoa(m);
	if ((pad = 4 - ft_strlen(tmp)) < 0)
		pad = 0;
	while (i < pad)
		buff[i++] = ' ';
	ft_strcat(buff, tmp);
	buff[i + 4 - pad] = ',';
	ft_strdel(&tmp);
}

static void add_min(char *buff, dev_t d)
{
	char	*tmp;
	int		pad;
	size_t	i;
	size_t	size;
	int		m;

	size = ft_strlen(buff);
	i = size;
	pad = 0;
	m = minor(d);
	tmp = ft_itoa(m);
	if ((pad = 4 - ft_strlen(tmp)) < 0)
		pad = 0;
	while (i - size < pad)
		buff[i++] = ' ';
	ft_strcat(buff, tmp);
	ft_strdel(&tmp);
}

char	*get_size(t_finfo *f_info)
{
	char	buff[BUFF_MAX];

	ft_bzero(buff, BUFF_MAX);
	if (f_info->type == 'b' || f_info->type == 'c')
	{
		add_maj(buff, f_info->file_s.st_rdev);
		add_min(buff, f_info->file_s.st_rdev);
		return (ft_strdup(buff));
	}
	else
		return (ft_itoa(f_info->file_s.st_size));
}

int		get_max(t_finfo *f_info, t_maxf *maxf)
{
	size_t	s_n;
	size_t	s_un;
	size_t	s_gr;

	s_n = ft_strlen(f_info->name);
	s_un = ft_strlen(f_info->uidname);
	s_gr = ft_strlen(f_info->gidname);
	
	if (maxf->name < s_n)
		maxf->name = s_n;
	if (maxf->uname < s_un)
		maxf->uname = s_un;
	if (maxf->grname < s_gr)
		maxf->grname = s_gr;

	if (maxf->link < ft_count_digit(f_info->file_s.st_nlink))
		maxf->link = ft_count_digit(f_info->file_s.st_nlink);
	if (maxf->byte < ft_strlen(f_info->size))
		maxf->byte = ft_strlen(f_info->size);
	return (OK);//a optimiser
}