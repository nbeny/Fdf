#include "fdf.h"

t_tab	*ft_stock(t_env *env, t_m *m)
{
	t_tab	*s;
	t_tab	*tab;
	int		i;

	if ((tab = ft_init_tab()) == NULL)
		return (NULL);
	get_next_line(env->fd, &(env->line));
	tab->split = ft_split(env->line);
	ft_strdel(&(env->line));
	s = tab;
	while (get_next_line(env->fd, &(env->line)) != 0)
    {
		if ((s->next = ft_init_tab()) == NULL)
			return (NULL);
		s = s->next;
		s->split = ft_split(env->line);
		i = 0;
		if ()
		while (s->split[i] != NULL)
			
		ft_strdel(&(env->line));
	}
	if ((tab = ft_make_x_y(tab, m)) == NULL)
		return (NULL);
	close(env->fd);
	return (tab);
}

void	ft_fdf(t_env *env, t_tab *tab, t_m *m)
{
	t_tab	*b;
	t_tab	*s;
	int		i;
	int		j;
	int		y;

	b = NULL;
	s = tab;
	j = 1;
	while (s->next != NULL)
	{
		i = -1;
		while (s->split[++i] != NULL)
		{
			ft_putstr(s->split[i]);
			ft_putchar(' ');
			if (ft_atoi(s->split[i]) != 0)
				y = m->y - ft_atoi(s->split[i]);
			else
				y = m->y;
			s->x[i] = m->x;
			s->y[i] = y;
			mlx_pixel_put(env->mlx, env->win, m->x, y, 0xFFFFFF);
			if (ft_atoi(s->split[i]) == 0)
				ft_ttrace_y(m, env);
			else if (i != 0)
				ft_trace_y(s->x[i - 1], s->y[i - 1], m->x, y, env);
			m->x = m->x + PIX;
			m->y = m->y + PIX;
			if (ft_atoi(s->split[i]) == 0)
				ft_ttrace_x(m, env);
			else if (i != 0 && b != NULL)
				ft_trace_x(b->x[i], b->y[i], m->x, y, env);
		}
		m->x = START_X - (j * PIX);
		m->y = START_Y + ((j * PIX) >> 2);
		j++;
		b = s;
		s = s->next;
	}
}