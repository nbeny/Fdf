#include "fdf.h"

t_mlx	*ft_init_mlx(char **av)
{
	t_mlx	*mlx;

	if (!(mlx = (t_mlx *)malloc(sizeof(t_mlx))))
		return (NULL);
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, WIN_X, WIN_Y, ":-)-:");
	mlx->line = NULL;
	mlx->split = NULL;
	mlx->fd = open(av[1], O_RDONLY);
	return (mlx);
}

t_map	*ft_init_map(void)
{
	t_map	*map;

	if (!(map = (t_map *)malloc(sizeof(t_map))))
		return (NULL);
	map->x = START_X;
	map->y = START_Y;
	map->z = 0;
	map->i = 0;
	map->j = 0;
	return (map);
}

t_save	*ft_init_save(void)
{
	t_save *save;

	if (!(save = (t_save *)malloc(sizeof(t_save))))
		return (NULL);
	save->x = 0;
	save->y = 0;
	save->z = 0;
	save->i = 0;
	save->j = 0;
	return (save);
}

int		ft_fdf(t_mlx *mlx, t_map *map)
{
	int	j;

	j = 1;
	while (get_next_line(mlx->fd, &(mlx->line)) != 0)
	{
		mlx->split = ft_strsplit(mlx->line, ' ');
		ft_ride_around(mlx, map, j);
		j++;
		ft_free_tabstr(mlx->split);
		ft_strdel(&(mlx->line));
	}
	return (0);
}

int		main(int ac, char **av)
{
	t_mlx	*mlx;
	t_map	*map;

	if (ac != 2)
	{
		ft_printf(2, "Fdf: too mush arguments.\n");
		return (-1);
	}
	if ((mlx = ft_init_mlx(av)) == NULL)
		return (-1);
	if ((map = ft_init_map()) == NULL)
		return (-1);
	ft_fdf(mlx, map);
	return (0);
}
