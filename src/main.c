#include "fdf.h"

t_coor	*ft_init_coor(char **av)
{
	t_coor	*c;

	if (!(c = (t_coor *)malloc(sizeof(t_coor))))
		return (NULL);
	c->mlx = mlx_init();
	c->win = mlx_new_window(c->mlx, MAX_X, MAX_Y, "mlx 42");
	c->j = 1;
	c->x = START_X;
	c->y = START_Y;
	c->z = 0;
	c->fd = open(av[1], O_RDONLY);
	c->powa = NULL;
	return (c);
}

void	ft_trace_x(t_coor *c)
{
	int	x;
	int	y;

	x = c->x - PIX_X;
	y = c->y - PIX_Y;
	while (x != c->x && y != c->y)
	{
		x++;
		y++;
		mlx_pixel_put(c->mlx, c->win, x, y, 0xFFFFFF);
	}
}

void	ft_trace_y(t_coor *c)
{
	int		x;
	int		y;
	int		i;
	int		j;

	x = c->x - (c->j * PIX_X);
	y = c->y - (c->j * PIX_Y) / 2;
	i = c->x;
	j = c->y;
	while (i != x && j != y)
	{
		i--;
		if (i % 2 == 0)
			j++;
		mlx_pixel_put(c->mlx, c->win, i, j, 0xFFFFFF);
	}
}

int		main(int ac, char **av)
{
	t_coor	*c;
	char	*line;
	int		x;
//	int		y;

	if (ac != 2)
	{
		ft_printf(2, "usage: ./fdf [path_map]\n");
		return (-1);
	}
	c = ft_init_coor(av);
	while (get_next_line(c->fd, &line) > 0)
	{
		c->i = 0;
		c->powa = ft_strsplit(line, ' ');
		while (c->powa[c->i++])
		{
//			x = 0.6 * c->x - 0.6 * c->y;
//			y = ft_atoi(c->powa[c->i]) * (0.6 / 2) * c->x;
			if (ft_atoi(c->powa[c->i]) != 0)
				x = c->x + ft_atoi(c->powa[c->i]);
			else
				x = c->x;
			mlx_pixel_put(c->mlx, c->win, x, c->y, 0xFFFFFF);
			ft_trace_y(c);
			c->x = c->x + PIX_X;
			c->y = c->y + PIX_Y;
			ft_trace_x(c);
		}
		c->x = START_X - (c->j * PIX_X);
		c->y = START_Y + (c->j * PIX_Y) / 2;
		c->j++;
		ft_free_tabstr(c->powa);
		ft_strdel(&line);
	}
	mlx_loop(c->mlx);
	return (0);
}

/*
**screen.x = (map.x - map.y) * TILE_WIDTH_HALF;
**screen.y = (map.x + map.y) * TILE_HEIGHT_HALF;
**https://gamedevelopment.tutsplus.com/tutorials/creating-isometric-worlds-a-primer-for-game-developers--gamedev-6511
**http://clintbellanger.net/articles/isometric_math/
*/
