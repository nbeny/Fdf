/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <nbeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/11 13:42:52 by nbeny             #+#    #+#             */
/*   Updated: 2017/06/11 13:42:53 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_scale(t_env *e, int keycode)
{
	if (keycode == 124)
		e->xcmp += 15;
	if (keycode == 123)
		e->xcmp -= 15;
	if (keycode == 125)
		e->ycmp += 15;
	if (keycode == 126)
		e->ycmp -= 15;
}

t_env		ft_useless(t_env e, int agc)
{
	if (agc == 1)
	{
		ft_putstr("Too few arguments, please make sure to use ./fdf");
		ft_putendl(" [~/Path/maps] R[255] G[100] B[0]");
		e.error = 1;
	}
	else if (agc == 2)
		ft_palette(&e);
	else if (agc != 5)
	{
		ft_putstr("If you want some colors, please make sure to use");
		ft_putendl(" [~/Path/maps] R[255] G[100] B[0]");
		ft_palette(&e);
		exit(0);
	}
	return (e);
}

int			ft_check_av(char **agv)
{
	int		i;

	i = 0;
	while (agv[2][i] && agv[2][i] != '\0')
	{
		if (ft_isdigit(agv[2][i]) == 0)
			return (-1);
		i++;
	}
	i = 0;
	while (agv[2][i] && agv[2][i] != '\0')
	{
		if (ft_isdigit(agv[2][i]) == 0)
			return (-1);
		i++;
	}
	i = 0;
	while (agv[2][i] && agv[2][i] != '\0')
	{
		if (ft_isdigit(agv[2][i]) == 0)
			return (-1);
		i++;
	}
	return (0);
}
