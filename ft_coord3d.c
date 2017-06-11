/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_coord3d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <nbeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/11 13:42:20 by nbeny             #+#    #+#             */
/*   Updated: 2017/06/11 13:42:22 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_3d		*ft_create3d(int x, int y, int z)
{
	t_3d	*p;

	if (!(p = malloc(sizeof(t_2d *))))
		return (NULL);
	p->x = x;
	p->y = y;
	p->z = z;
	return (p);
}

t_3d		ft_create_3d_point_from_2d(t_2d pdx, int z)
{
	t_3d	p;

	p.x = pdx.x;
	p.y = pdx.y;
	p.z = z;
	return (p);
}
