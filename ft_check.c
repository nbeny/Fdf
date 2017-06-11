#include "fdf.h"

int			ft_count_rows(char *name)
{
	char	*ret;
	int		res;
	int		f;

	res = 0;
	f = open(name, O_RDONLY);
	while (get_next_line(f, &ret) > 0)
	{
		res++;
		if (ret != NULL)
		{
			ft_strdel(&ret);
			ret = NULL;
		}
	}
	close(f);
	return (res);
}

int			ft_count_columns(char *str)
{
	int		c;

	c = 0;
	while (str[c] != '\0')
		c++;
	return (c);
}

int			ft_count_columns_int(int *str)
{
	int		c;

	c = 1;
	while (c <= str[0] + 1)
		c++;
	return (c);
}

t_env		ft_main_suite(t_env *e, int fd, int i, char *line)
{
	while (get_next_line(fd, &line) > 0)
	{
		e->map[i] = (char *)malloc(sizeof(char) *
							((ft_strlen(line) / 2)));
		if (e->map[i] == NULL)
			return (*e);
		e->map[i] = line;
		ft_char_to_int(*e, line, i);
		ft_strdel(&line);
		i++;
	}
	e->mapi[i] = NULL;
	e->map[i] = NULL;
	i = 1;
	if (e->mapi[i])
		ft_min_max(e);
	else
		e->error = 1;
	close(fd);
	return (*e);
}

void		ft_stock_mapi(t_ctx ctx)
{
	ctx.tabp[ctx.j][ctx.i] = *ctx.p;
}
