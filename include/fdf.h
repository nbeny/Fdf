/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <nbeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/20 10:09:56 by nbeny             #+#    #+#             */
/*   Updated: 2017/06/14 21:19:22 by jpeg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# define WIN_X 1200
# define WIN_Y 900
# define PIX 4
# define AXE_Z 10
# define DOT_X (WIN_X / 2)
# define DOT_Y (WIN_Y / 2)
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
	struct s_3d	**loop;
	struct s_3d	*floop;
	int			x;
	int			y;
	int			z;
	double xi;
	double xf;
	double yi;
	double yf;
}				t_env;

typedef struct	s_3d
{
	int		x;
	int		y;
}				t_3d;

typedef struct	s_inc
{
	double		x;
	double		y;
}				t_inc;

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
t_3d	ft_new_loop(int x, int y, int z);
int		ft_loop_3d(t_env *e);
/*
**put
*/
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
