/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <nbeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 19:14:54 by nbeny             #+#    #+#             */
/*   Updated: 2017/06/15 19:14:55 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_draw_l(int steps, t_inc inc, t_3d a, t_env *e)
{
	int		i;
	int		x;
	int		y;

	i = 0;
	while (i <= steps)
	{
		x = inc.x * i + a.x;
		y = inc.y * i + a.y;
		if (x < WIN_X && x > 0 && y > 0 && y < WIN_Y)
			mlx_pixel_put(e->mlx, e->win, x, y, 0xFFFFFF);
		i++;
	}
}

void	ft_draw_line(t_3d a, t_3d b, t_env *e)
{
	double		dx;
	double		dy;
	int			steps;
	t_inc		inc;

	dx = b.x - a.x;
	dy = b.y - a.y;
	steps = (fabs(dx) > fabs(dy) ? fabs(dx) : fabs(dy));
	inc.x = dx * (1.0 / steps);
	inc.y = dy * (1.0 / steps);
	ft_draw_l(steps, inc, a, e);
}

int		ft_put_fdf(t_env *e)
{
	int		i;
	int		j;

	i = -1;
	mlx_clear_window(e->mlx, e->win);
	while (++i < e->s_y)
	{
		j = -1;
		while (++j < e->s_x)
		{
			mlx_pixel_put(e->mlx, e->win,\
				e->loop[i][j].x, e->loop[i][j].y, 0xFFFFFF);
			if (j != (e->s_x - 1))
				ft_draw_line(e->loop[i][j], e->loop[i][j + 1], e);
			if (i != (e->s_y - 1))
				ft_draw_line(e->loop[i + 1][j], e->loop[i][j], e);
		}
	}
	return (1);
}
