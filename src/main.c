#include "fdf.h"

t_coor	*ft_init_coor(char **av)
{
	t_coor	*c;

	if (!(c = (t_coor *)malloc(sizeof(t_coor))))
		return (NULL);
	c->mlx = mlx_init();
	c->win = mlx_new_window(c->mlx, 800, 600, "mlx 42");
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
		while (c->powa[c->i++] != NULL)
		{
			mlx_pixel_put(c->mlx, c->win, c->x, c->y, 0xFFFFFF);
			c->x += SIZE;
		}
		ft_free_tabstr(c->powa);
		ft_strdel(&line);
		c->y += SIZE;
	}
	mlx_loop(c->mlx);
	return (0);
}
