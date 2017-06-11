/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <nbeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/11 13:42:33 by nbeny             #+#    #+#             */
/*   Updated: 2017/06/11 13:42:34 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		draw(t_env *e, t_ctx *ctx)
{
	ft_min_max(e);
	e->col = ft_count_columns_int(e->mapi[1]);
	e->row = ft_count_rows(e->filename);
	ctx->i = 1;
	ctx->j = 1;
	ctx->y = 50;
	ctx->x = 200;
	e->space = (WIN_H - 200) / (10 + e->row);
	e->count = e->space;
	ctx->tabp = (t_3d **)malloc(sizeof(t_3d *) * e->row + 2);
	while (e->mapi[1][0] >= ctx->i && ctx->x < e->width - 50)
	{
		ft_draw_loop(*e, ctx);
		ctx->i += 1;
		ctx->j = 1;
		ctx->y = 50;
		ctx->x += e->space;
		ft_free_structp(ctx->p);
	}
	ctx->tabp[e->row + 1] = NULL;
	ft_printf_line(*ctx, *e);
	ft_free_tab_struct(ctx->tabp);
}

int			key_hook(int keycode, t_env *e)
{
	if (keycode == 53)
		exit(0);
	else if (keycode <= 126 && keycode >= 69)
	{
		ft_scale(e, keycode);
		ft_test(e, keycode);
	}
	else if (keycode == 12)
	{
		e->factor += 0.03;
		mlx_clear_window(e->mlx, e->win);
		test2(e);
	}
	else if (keycode == 13)
	{
		e->factor -= 0.03;
		mlx_clear_window(e->mlx, e->win);
		test2(e);
	}
	return (0);
}

int			expose_hook(t_env *e)
{
	test2(e);
	return (0);
}

int			ft_test(t_env *e, int keycode)
{
	int		y;
	int		i;

	i = 1;
	if (keycode == 69 || keycode == 78)
		while (e->mapi[i] != NULL)
		{
			y = 1;
			while (y <= e->mapi[i][0])
			{
				if (e->mapi[i][y] != 0)
				{
					if (keycode == 69)
						e->mapi[i][y]++;
					if (keycode == 78)
						e->mapi[i][y]--;
				}
				y++;
			}
			i++;
		}
	mlx_clear_window(e->mlx, e->win);
	test2(e);
	return (0);
}

int			main(int ac, char **av)
{
	t_env	e;

	e.w = ac;
	e = ft_argv(ac, av, e);
	if (e.error == 1)
		return (0);
	e.filename = av[1];
	e.factor = 0.2;
	ft_init_ftmain(&e);
	e = ft_main(&e, av[1]);
	if (e.error == 1)
		return (0);
	e.width = 1200;
	e.height = 900;
	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, e.width, e.height, "Fdf");
	mlx_key_hook(e.win, key_hook, &e);
	mlx_expose_hook(e.win, expose_hook, &e);
	mlx_loop(e.mlx);
	ft_freestyle(&e);
	return (0);
}
