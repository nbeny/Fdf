/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <nbeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 19:14:23 by nbeny             #+#    #+#             */
/*   Updated: 2017/06/15 19:14:27 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_free_int(int **mapi, int fx)
{
	int	x;

	x = -1;
	while (++x < fx)
	{
		if (mapi[x] != NULL)
		{
			free(mapi[x]);
			mapi[x] = NULL;
		}
	}
	free(mapi);
	mapi = NULL;
}

void	ft_free_struct(t_3d **loop, int fx)
{
	int	x;

	x = -1;
	while (++x < fx)
	{
		if (loop[x] != NULL)
		{
			free(loop[x]);
			loop[x] = NULL;
		}
	}
	free(loop);
	loop = NULL;
}

void	ft_freestyle(t_env *e)
{
	ft_free_int(e->mapi, e->s_x);
	ft_free_struct(e->loop, e->s_x);
}
