#include "fdf.h"

void	ft_trace_x(int xi,int yi,int xf,int yf, t_mlx *mlx)
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
	mlx_pixel_put(mlx->mlx, mlx->win, x, y, 0xFFFFFF);
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
		mlx_pixel_put(mlx->mlx, mlx->win, x, y, 0xFFFFFF);
	}
}

void	ft_trace_y(int xi,int yi,int xf,int yf, t_mlx *mlx)
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
	mlx_pixel_put(mlx->mlx, mlx->win, x, y, 0xFFFFFF);
	if (dx > dy)
	{
		cumul = dx / 2;
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
			mlx_pixel_put(mlx->mlx, mlx->win, x, y, 0xFFFFFF);
		}
	}
	else
	{
		cumul = dy / 2;
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
			mlx_pixel_put(mlx->mlx, mlx->win, x, y, 0xFFFFFF);
		}
	}
}

int		ft_ride_around(t_mlx *mlx, t_map *map, int j)
{
	t_save	*save;
	int		i;
	int		x;

	i = 0;
	save = ft_init_save();
	while (mlx->split[i++] != NULL)
	{
		if (ft_atoi(mlx->split[i]) != 0)
			x = map->x + ft_atoi(mlx->split[i]);
		else
			x = map->x;
		mlx_pixel_put(mlx->mlx, mlx->win, x, map->y, 0xFFFFFF);
		if (j != 1)
			ft_trace_y(save->x, save->y, x, map->y, mlx);
		save->x = x;
		save->y = map->y;
		map->x = map->x + PIX;
		map->y = map->y + PIX;
		ft_trace_x(save->x, save->y, x, map->y, mlx);
	}
	map->x = START_X - (j * PIX);
	map->y = START_Y + (j * PIX) / 4;
	return (0);
}
