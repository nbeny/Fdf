#include "fdf.h"

t_env	*ft_init_mlx(char **av)
{
	t_env	*env;

	if (!(env = (t_env *)malloc(sizeof(t_env))))
		return (NULL);
	env->mlx = mlx_init();
	env->win = mlx_new_window(env->mlx, WIN_X, WIN_Y, "Fdf");
	env->line = NULL;
	env->split = NULL;
	env->fd = open(av[1], O_RDONLY);
	return (env);
}

t_m		*ft_init_map(void)
{
	t_m	*m;

	if (!(m = (t_m *)malloc(sizeof(t_m))))
		return (NULL);
	m->x = START_X;
	m->y = START_Y;
	m->j = 1;
	m->z = 0;
	m->i = 0;
	return (m);
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

t_tab	*ft_init_tab(void)
{
	t_tab	*tab;

	if (!(tab = (t_tab *)malloc(sizeof(t_tab))))
		return (NULL);
	tab->next = NULL;
	return (tab);
}


int		main(int ac, char **av)
{
	t_env	*env;
	t_m		*m;
	t_tab	*tab;

	if (ac != 2)
	{
		ft_printf(2, "usage: ./Fdf [map]\n");
		return (-1);
	}
	env = ft_init_mlx(av);
	m = ft_init_map();
	if ((tab = ft_stock(env, m)) == NULL)
	{
		ft_printf(2, "fdf: Malloc error !\n");
		return (-1);
	}
	ft_count_size(tab, m);
	ft_fdf(env, tab, m);
	while (tab != NULL)
	{
		m->i = 0;
		while (tab->split[m->i++] != NULL)
			ft_printf(0, "%s ", tab->split[m->i]);
		ft_putstr("\n");
		tab = tab->next;
		}
	mlx_loop(env->mlx);
	return (0);
}
