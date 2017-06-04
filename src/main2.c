#include "fdf.h"

t_coor	*ft_init_coor(char **av)
{
	t_coor	*c;

	if (!(c = (t_coor *)malloc(sizeof(t_coor))))
		return (NULL);
	c->mlx = mlx_init();
	c->win = mlx_new_window(c->mlx, MAX_X, MAX_Y, "Fdf");
	c->j = 1;
	c->x = 50;
	c->y = 50;
	c->z = 0;
	c->fd = open(av[1], O_RDONLY);
	c->powa = NULL;
	return (c);
}

int		main(int ac, char **av)
{
	t_coor	*c;
	char	*line;
	int		x;
	int		y;

	if (ac != 2)
	{
		ft_printf(2, "usage: ./fdf [path_map]\n");
		return (-1);
	}
	c = ft_init_coor(av);
	while (get_next_line(c->fd, &line) > 0)
	{
		c->powa = ft_strsplit(line, ' ');
		c->x = 50;
		while (c->powa[c->i++])
		{
			x = 0.6 * c->x - 0.6 * c->y;
			y = ft_atoi(c->powa[c->i]) + (0.6 / 2) * c->x + (0.6 / 2) *c->y;
			mlx_pixel_put(c->mlx, c->win, x, y, 0xFFFFFF);
			c->x += 10;
		}
		c->y += 10;
	}
	return (0);
}
