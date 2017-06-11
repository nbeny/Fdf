/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_coord2d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <nbeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/11 13:42:13 by nbeny             #+#    #+#             */
/*   Updated: 2017/06/11 13:42:15 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_2d		*ft_create2d(int x, int y)
{
	t_2d	*p;

	if (!(p = malloc(sizeof(t_2d *))))
		return (NULL);
	if (p)
	{
		p->x = x;
		p->y = y;
	}
	return (p);
}

t_2d		ft_transform2d(t_3d p, t_env e)
{
	t_2d	np;

	np.x = (p.x * e.factor * 3) - (p.y * e.factor * 3) -
			(p.z / (16 * e.factor)) + (WIN_H / 2) - e.xcmp;
	np.y = (p.x * e.factor * 2) + (p.y * e.factor * 2) -
		(p.z * (16 * e.factor)) - ((WIN_H * e.factor) -
				(1000 * e.factor)) - e.ycmp;
	return (np);
}

t_2d		ft_3d_to_2d(t_3d p)
{
	t_2d	pp;
	t_env	e;

	e.factor = 0.2;
	pp = ft_transform2d(p, e);
	return (pp);
}

void		ft_print2d(t_2d p, unsigned int color, t_env *e)
{
	if (p.x > 0 && p.x < e->width && p.y > 0 && e->height)
		mlx_pixel_put(e->mlx, e->win, p.x, p.y, color);
}
