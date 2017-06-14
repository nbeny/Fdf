/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <nbeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/20 10:09:56 by nbeny             #+#    #+#             */
/*   Updated: 2017/05/20 10:10:52 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# define WIN_X 1200
# define WIN_Y 900
# define PIX 20
# define DOT_X (WIN_X / 2)
# define DOT_Y (WIN_Y / e->s_y)
# include "../ft_printf/include/ft_printf.h"
# include "../minilibx/mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include <sys/stat.h>

typedef struct	s_env
{
	void		*mlx;
	void		*win;
	int			**mapi;
	int			s_y;
	int			s_x;
	struct s_3d	***loop;
	int			x;
	int			y;
	int			z;
}				t_env;

typedef struct	s_3d
{
	int		x;
	int		y;
}				t_3d;

typedef struct	s_pixel
{
	double	x;
	double	y;
}				t_pixel;
/*
**main
*/
void	ft_init_fdf(t_env *e);
int		ft_help(void);
int		main(int ac, char **av);
/*
**parcing
*/
int		ft_parce_arguments(char **av);
int		*ft_char_to_int(char *str);
int		ft_transform_map(t_env *e, char **av);
t_3d	*ft_new_loop(int x, int y, int z);
int		ft_loop_3d(t_env *e);
/*
**put
*/
void	ft_segment(t_3d *i, t_3d *f, t_env *e);
int		ft_put_fdf(t_env *e);
/*
**tools
*/
int		ft_len(char *str);
int		ft_count_rows(char *name);
/*
**free
*/
#endif
