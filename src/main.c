#include "fdf.h"

void	ft_init_fdf(t_env *e)
{

	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, WIN_X, WIN_Y, "Fdf");
	e->s_y = 0;
	e->s_x = 0;
	e->loop = NULL;
	e->x = 0;
	e->y = 0;
	e->z = 0;
	e->xi = 100;
	e->xf = 150;
	e->yi = 100;
	e->yf = 150;
}

int ft_key_hook(int keycode, t_env *e)
{
	if(keycode == 13)
		e->yf-= 25;
	else if(keycode == 1)
		e->yf+= 25;
		else if(keycode == 0)
			e->xf-= 25;
			else if(keycode == 2)
				e->xf+= 25;
				if(keycode == 126)
					e->yi+= 25;
				else if(keycode == 122)
					e->yi-= 25;
					else if(keycode == 123)
						e->xi-= 25;
						else if(keycode == 125)
							e->xi+= 25;
							if(keycode == 53)
								exit(1);
							return(1);

}

int		ft_help(void)
{
	ft_printf(0, "usage: ./fdf [map]\n");
	ft_printf(0, "sample map:\n");
	ft_printf(0, "0 0 0 0 0 0 0 0 0 0\n");
	ft_printf(0, "0 4 4 0 0 0 2 2 2 0\n");
	ft_printf(0, "0 4 0 0 0 0 0 0 2 0\n");
	ft_printf(0, "0 4 0 4 0 0 2 2 2 0\n");
	ft_printf(0, "0 4 4 4 4 0 2 0 0 0\n");
	ft_printf(0, "0 0 0 4 0 0 2 2 2 0\n");
	ft_printf(0, "0 0 0 4 0 0 0 0 0 0\n");
	ft_printf(0, "0 0 0 0 0 0 0 0 0 0\n");
	ft_printf(0, "Good luck !\n");
	return (0);
}

int ft_close()
{
	exit(1);
}

int		main(int ac, char **av)
{
	t_env	e;

	if (ac == 2)
	{
		if (!ft_strncmp(av[1], "help\0", 5))
			return (ft_help());
		ft_init_fdf(&e);
		if (!ft_parce_arguments(av))
		{
			ft_printf(2, "usage: ./fdf [map]\n");
			return (-1);
		}
		ft_printf(2, "yeah man\n");
		if (!ft_transform_map(&e, av))
		{
			ft_printf(2, "usage: ./fdf [help]\n");
			return (-1);
		}
		ft_printf(2, "yeah man 2\n");
		if (!(ft_loop_3d(&e)))
			return (-1);
		ft_printf(2, "yeah man 3\n");
		mlx_loop_hook(e.mlx, ft_put_fdf, &e);
		mlx_hook(e.win, 2, 0, ft_key_hook, &e);
		mlx_hook(e.win, 17, 0, ft_close, NULL);
		mlx_expose_hook(e.win, ft_put_fdf, &e);
		mlx_loop(e.mlx);
	}
	return (0);
}
