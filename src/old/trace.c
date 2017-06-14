#include "fdf.h"

void	ft_trace_x(int xi,int yi,int xf,int yf, t_env *env)
{
	int	dx;
	int	dy;
	int	cumul;
	int	x;
	int	y;

	x = xi;
	y = yi;
	dx = xf - xi;
	dy = yf - yi;
	mlx_pixel_put(env->mlx, env->win, x, y, 0xFFFFFF);
	cumul = dx / 2;
	x = xi + 1;
	while (x++ <= xf)
	{
		cumul += dy;
		if (cumul >= dx)
		{
			cumul -= dx;
			y += 1;
		}
		mlx_pixel_put(env->mlx, env->win, x, y, 0xFFFFFF);
	}
}

void	ft_trace_y(int xi,int yi,int xf,int yf, t_env *env)
{
	int dx;
	int	dy;
	int	i;
	int	xinc;
	int	yinc;
	int	cumul;
	int	x;
	int	y;

	x = xi;
	y = yi;
	dx = xf - xi;
	dy = yf - yi;
	xinc = ( dx > 0 ) ? 1 : -1;
	yinc = ( dy > 0 ) ? 1 : -1;
	dx = abs(dx);
	dy = abs(dy);
	mlx_pixel_put(env->mlx, env->win, x, y, 0xFFFFFF);
	if (dx > dy)
	{
		cumul = dx >> 2;
		i = 1;
		while (i++ <= dx)
		{
			x += xinc;
			cumul += dy;
			if (cumul >= dx)
			{
				cumul -= dx;
				y += yinc;
			}
			mlx_pixel_put(env->mlx, env->win, x, y, 0xFFFFFF);
		}
	}
	else
	{
		cumul = dy >> 2;
		i = 1;
		while (i++ <= dy)
		{
			y += yinc;
			cumul += dx;
			if (cumul >= dy)
			{
				cumul -= dy;
				x += xinc;
			}
			mlx_pixel_put(env->mlx, env->win, x, y, 0xFFFFFF);
		}
	}
}

void    ft_ttrace_x(t_m *m, t_env *env)
{
    int x;
    int y;

    x = m->x - PIX;
    y = m->y - PIX;
    while (x != m->x && y != m->y)
    {
        x++;
        y++;
        mlx_pixel_put(env->mlx, env->win, x, y, 0xFFFFFF);
    }
}

void    ft_ttrace_y(t_m *m, t_env *env)
{
    int     x;
    int     y;
    int     i;
    int     j;

    x = m->x - (m->j * PIX);
    y = m->y - ((m->j * PIX) >> 2);
    i = m->x;
    j = m->y;
    while (i != x && j != y)
    {
        i--;
        if (i % 4 == 0)
            j++;
        mlx_pixel_put(env->mlx, env->win, i, j, 0xFFFFFF);
    }
}
/*
int		ft_ride_around(t_env *env, t_m *m)
{
	t_save	*save;
	int		i;
	int		y;

	i = 0;
	save = ft_init_save();
	while (env->split[i++] != NULL)
	{
		if (ft_atoi(env->split[i]) != 0)
			y = m->y + ft_atoi(env->split[i]);
		else
			y = m->y;
		mlx_pixel_put(env->mlx, env->win, m->x, y, 0xFFFFFF);
		if (ft_atoi(env->split[i]) == 0)
			ft_ttrace_y(m, env, i);
		else
		{
			save->x = START_X - (m->j - 1) * PIX;
			save->y = START_Y + (((m->j - 1) * PIX) >> 2);
			ft_trace_y(save->x, save->y, m->x, y, env);
		}
		m->x = m->x + PIX;
		m->y = m->y + PIX;
		save->x = m->x;
		save->y = y;
		if (ft_atoi(env->split[i]) == 0)
			ft_ttrace_x(m, env, i);
		else
			ft_trace_x(save->x, save->y, m->x, y, env);
	}
	m->x = START_X - (m->j * PIX);
	m->y = START_Y + ((m->j * PIX) >> 2);
	return (0);
}
*/
