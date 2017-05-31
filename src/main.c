#include "fdf.h"

t_coor	*ft_init_coor(char **av)
{
	t_coor	*c;

	if (!(c = (t_coor *)malloc(sizeof(t_coor))))
		return (NULL);
	c->mlx = mlx_init();
	c->win = mlx_new_window(c->mlx, 600, 800, "mlx 42");
	c->x = SIZE;
	c->y = SIZE;
	c->z = 0;
	c->fd = open(av[1], O_RDONLY);
	c->powa = NULL;
	return (c);
}

int		main(int ac, char **av)
{
	t_coor	*c;
	char	*line;
	int		i;
	int		j;

	if (ac != 2)
	{
		ft_printf(2, "usage: ./fdf [path_map]\n");
		return (-1);
	}
	c = ft_init_coor(av);
	while (get_next_line(c->fd, &line) != 0)
	{
		c->i = 0;
		c->powa = ft_strsplit(line, ' ');
		c->x = SIZE;
		j = (c->x + c->y) * 200;
		while (c->powa[c->i++] != NULL)
		{
			i = (c->x - c->y) * 150;
			mlx_pixel_put(c->mlx, c->win, i, j, 0xFFFFFF);
			c->x += SIZE;
		}
		ft_free_tabstr(c->powa);
		ft_strdel(&line);
		c->y += SIZE;
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
