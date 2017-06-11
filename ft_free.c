/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <nbeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/11 13:42:39 by nbeny             #+#    #+#             */
/*   Updated: 2017/06/11 13:42:40 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_free_structp(t_3d *p)
{
	if (p != NULL)
	{
		free(p);
		p = NULL;
	}
}

static void	ft_free_tabstr(char **tab)
{
	int		i;

	i = 0;
	if (tab != NULL)
	{
		if (tab[i] != NULL)
			while (tab[i] != NULL)
			{
				ft_strdel(&tab[i]);
				tab[i] = NULL;
				i++;
			}
		free(tab);
		tab = NULL;
	}
}

static void	ft_free_tabint(int **tab, char *filename)
{
	int		i;

	i = 0;
	if (tab != NULL)
	{
		if (tab[i] != NULL)
			while (i < (ft_count_rows(filename) + 10))
			{
				if (tab[i] != NULL)
				{
					free(tab[i]);
					tab[i] = NULL;
				}
				i++;
			}
		free(tab);
		tab = NULL;
	}
}

void		ft_free_tab_struct(t_3d **tabp)
{
	int		i;

	i = 1;
	if (tabp != NULL)
	{
		while (tabp[i] != NULL)
		{
			if (tabp[i] != NULL)
			{
				free(tabp[i]);
				tabp[i] = NULL;
			}
		}
		free(tabp);
		tabp = NULL;
		i++;
	}
}

void		ft_freestyle(t_env *e)
{
	ft_free_tabstr(e->map);
	ft_free_tabint(e->mapi, e->filename);
	ft_strdel(&(e->filename));
	if (e->mlx != NULL)
	{
		free(e->mlx);
		e->mlx = NULL;
	}
	if (e->win != NULL)
	{
		free(e->win);
		e->win = NULL;
	}
}
