/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <nbeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 19:14:32 by nbeny             #+#    #+#             */
/*   Updated: 2017/06/15 19:14:34 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_key_hook(int keycode, t_env *e)
{
	e->un = 1;
	if (keycode == 53)
		exit(EXIT_SUCCESS);
	return (1);
}

int		ft_close(void)
{
	exit(EXIT_SUCCESS);
}

void	ft_mlx(t_env *e)
{
	mlx_loop_hook(e->mlx, ft_put_fdf, e);
	mlx_hook(e->win, 2, 0, ft_key_hook, e);
	mlx_hook(e->win, 17, 0, ft_close, NULL);
	mlx_expose_hook(e->win, ft_put_fdf, e);
	mlx_loop(e->mlx);
}
