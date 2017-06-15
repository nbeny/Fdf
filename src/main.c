/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <nbeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 19:14:39 by nbeny             #+#    #+#             */
/*   Updated: 2017/06/15 19:14:41 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		if (!ft_transform_map(&e, av))
		{
			ft_printf(2, "usage: ./fdf [help]\n");
			return (-1);
		}
		if (!(ft_loop_3d(&e)))
			return (-1);
		ft_mlx(&e);
		ft_freestyle(&e);
	}
	return (0);
}
