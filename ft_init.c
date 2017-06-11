#include "fdf.h"

void			ft_init_ftmain(t_env *e)
{
	if (!(e->map = (char **)malloc(sizeof(char *) *\
					(ft_count_rows(e->filename) + 10))))
		e->map = NULL;
	if (!(e->mapi = (int **)malloc(sizeof(int *) *\
					(ft_count_rows(e->filename) + 10))))
		e->mapi = NULL;
}

void			ft_draw_loop(t_env e, t_ctx *ctx)
{
	while (e.row + 1 != ctx->j)
	{
		if (e.space == e.count)
		{
			e.count = 0;
			if (ctx->i <= e.mapi[1][0])
			{
				if (ctx->i == 1)
					ctx->tabp[ctx->j] = (t_3d *)malloc(sizeof(t_3d) * e.col);
				ctx->p = ft_create3d(ctx->x, ctx->y,
						e.mapi[ctx->j][ctx->i]);
				ft_stock_mapi(*ctx);
			}
			ctx->j += 1;
		}
		e.count = e.count + e.space;
		ctx->y += e.space;
	}
}

t_env			ft_argv(int agc, char **agv, t_env e)
{
	e = ft_useless(e, agc);
	if (agc == 5)
	{
		if (ft_check_av(agv) == 0)
		{
			agv[2] = agv[2];
			e.r = ft_atoi(agv[2]);
			e.g = ft_atoi(agv[3]);
			e.b = ft_atoi(agv[4]);
		}
		else
			e.r = -1;
		if (e.r > 255 || e.g > 255 || e.b > 255 || e.r < 0
			|| e.g < 0 || e.b < 0 || !ft_isdigit(agv[2][0]))
		{
			ft_putstr("Please make sure to use a Value");
			ft_putendl(" between 0 and 255, thanks !");
			e.error = 1;
		}
		ft_palette(&e);
	}
	else if (agc > 5)
		e.error = 1;
	return (e);
}

t_env			*ft_palette(t_env *e)
{
	e->k = 254;
	if (e->w == 5)
		e->palette[255] = (e->r * 65536) + (e->g * 256) + e->b;
	else
		e->k = 255;
	if (e->w < 5)
		while (e->k != 0)
			e->palette[e->k--] = 0xFFFFFF;
	else
	{
		while (e->k != 0)
		{
			e->palette[e->k] = e->palette[e->k + 1];
			if ((e->r -= 1) > 0)
				e->palette[e->k] = e->palette[e->k] - 0x010000;
			if ((e->g -= 1) > 0)
				e->palette[e->k] = e->palette[e->k] - 0x000100;
			if ((e->b -= 1) > 0)
				e->palette[e->k] = e->palette[e->k] - 0x000001;
			if (e->r <= 0 && e->g <= 0 && e->b <= 0)
				e->palette[e->k] = 0x000000;
			e->k--;
		}
	}
	return (e);
}

void			test2(t_env *e)
{
	t_ctx		ctx;

	(void)ctx;
	draw(e, &ctx);
}
