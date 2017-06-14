#include "fdf.h"

void	ft_draw_line(t_3d *i, t_3d *f, t_env *e)
{
	int		x;
	int		y;
	double	a;
	double	b;

	a = (double)abs(f->y - i->y) / (f->x - i->x);
	b = (double)fabs(i->y - a * i->x);
	x = i->x;
	while (x <= f->x)
	{
		y = (int)(a * x + b);
		mlx_pixel_put(e->mlx, e->win, x, y, 0xFFFFFF);
		x++;
	}
}

int		ft_put_fdf(t_env *e)
{
	int		i;
	int		j;

	i = -1;
	while (++i < e->s_y)
	{
		j = -1;
		while (++j < e->s_x)
		{
			mlx_pixel_put(e->mlx, e->win, e->loop[i][j]->x, e->loop[i][j]->y, 0xFFFFFF);
			if (j != (e->s_x - 1))
				ft_draw_line(e->loop[i][j], e->loop[i][j + 1], e);
			if (i != (e->s_y - 1))
				ft_draw_line(e->loop[i + 1][j], e->loop[i][j], e);
		}
	}
	return (1);
}
