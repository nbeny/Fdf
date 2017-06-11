#ifndef FDF_H

# define FDF_H

# include <math.h>
# include "../minilibx/mlx.h"
# include <unistd.h>
# include "./libft/include/libft.h"
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <sys/stat.h>

# define LINE_COLOR	0xccff00
# define WIN_H		900
# define WIN_W		1200
# define SPACE		115
# define BUFF_SIZE	10

typedef struct	s_env
{
	int		col;
	int		row;
	int		ycmp;
	int		xcmp;
	void	*mlx;
	void	*win;
	int		width;
	int		height;
	char	**map;
	int		**mapi;
	char	*filename;
	double	count;
	int		space;
	float	factor;
	int		max;
	int		min;
	int		red[12];
	int		palette[256];
	int		r;
	int		g;
	int		b;
	int		w;
	int		error;
	int		k;
}				t_env;

typedef struct	s_win
{
	int			w;
	int			h;
}				t_win;

typedef struct	s_2d
{
	int			x;
	int			y;
}				t_2d;

typedef struct	s_3d
{
	int			x;
	int			y;
	int			z;
}				t_3d;

typedef struct	s_line
{
	double		dx;
	double		dy;
	double		size;
}				t_line;

typedef struct	s_ctx
{
	int			x;
	int			y;
	int			i;
	int			j;
	t_3d		*p;
	t_3d		**tabp;
}				t_ctx;
typedef struct	s_color
{
	double		iterations;
	double		a;
	double		b;
	double		fac;
	t_2d		p0;
	t_2d		p1;
	int			ite_max;
	int			cpt;
	int			nb_pix;
	int			z_min;
	int			i;
	int			color_min;
	int			real_color;
	int			pass;
	int			color;
}				t_color;

int				get_next_line(const int fd, char **line);
t_color			ft_color_min(t_env *e, t_color c, t_3d p2, t_3d p3);
t_color			ft_degrader(t_color c, t_3d p2, t_3d p3);
int				ft_color(t_env e, t_3d p0, t_3d p1);
void			ft_min_max(t_env *e);
void			ft_printf_line(t_ctx ctx, t_env e);
void			ft_stock_mapi(t_ctx ctx);
int				ft_getnbr(char *str);
void			ft_char_to_int(t_env e, char *str, int i);
void			ft_draw_line(t_3d p0, t_3d p1, t_env *e);
t_3d			ft_create_3d_point_from_2d(t_2d pdx, int z);
t_3d			*ft_create3d(int x, int y, int z);
void			ft_print2d(t_2d p, unsigned int color, t_env *e);
t_2d			ft_transform2d(t_3d p, t_env e);
t_2d			*ft_create2d(int x, int y);
int				ft_count_columns(char *str);
int				ft_count_columns_int(int *str);
int				ft_count_rows(char *name);
void			draw(t_env *e, t_ctx *ctx);
int				expose_hook(t_env *e);
t_env			ft_main(t_env *e, char *file);
char			*ft_get_join(char *s1, char *s2);
void			ft_truc(char **line, char **tmp, int *ret);
void			ft_draw_loop(t_env e, t_ctx *ctx);
void			ft_init_ftmain(t_env *e);
int				key_hook(int keycode, t_env *e);
int				ft_test(t_env *e, int keycode);
t_env			*ft_palette(t_env *e);
t_env			ft_argv(int agc, char **agv, t_env e);
t_env			*ft_error_gnl(t_env *e, int err, char *file);
t_env			ft_main_suite(t_env *e, int fd, int i, char *line);
void			test2(t_env *e);
void			ft_scale(t_env *e, int keycode);
t_env			ft_useless(t_env e, int agc);
int				ft_check_av(char **agv);
void			ft_color_min_end(t_env *e, t_color c);
void			ft_freestyle(t_env *e);
void			ft_free_tab_struct(t_3d **tabp);
void			ft_free_structp(t_3d *p);
#endif
