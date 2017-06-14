#include "fdf.h"

void	ft_count_size(t_tab *tab, t_m *m)
{
	t_tab *s;

	if (tab == NULL || m == NULL)
		return ;
	while (tab->split[m->i] != NULL)
		m->i++;
	s = tab;
	while (s != NULL)
	{
		m->j++;
		s = s->next;
	}
	ft_printf(0, "%i, %i\n", m->i, m->j);
}

t_tab	*ft_make_x_y(t_tab *tab, t_m *m)
{
	t_tab	*s;

	s = tab;
	while (s != NULL)
	{
		if (!(s->x = (int *)malloc(sizeof(int) * m->i)))
			return (NULL);
		s->x[m->i - 1] = 0;
		if (!(s->y = (int *)malloc(sizeof(int) * m->i)))
			return (NULL);
		s->y[m->i - 1] = 0;
		s = s->next;
	}
	return (tab);
}
