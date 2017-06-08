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
# define WIN_X 800
# define WIN_Y 600
# define PIX 10
# define START_X 400
# define START_Y 50
# include "../ft_printf/include/ft_printf.h"
# include "../minilibx/mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h> 

typedef struct	s_env
{
	void	*mlx;
	void	*win;
	char	*line;
	char	**split;
	int		fd;
}				t_env;

typedef struct	s_tab
{
	char			**split;
	int				*x;
	int				*y;
	struct s_tab	*next;
}				t_tab;

typedef struct	s_m
{
	int	x;
	int	y;
	int	z;
	int	i;
	int	j;
}				t_m;

typedef struct	s_save
{
	int	x;
	int	y;
	int	z;
	int	i;
	int	j;
}				t_save;
/*
**main
*/
t_env	*ft_init_mlx(char **av);
t_m		*ft_init_map(void);
t_save	*ft_init_save(void);
t_tab	*ft_init_tab(void);
int		main(int ac, char **av);
/*
**core
*/
t_tab	*ft_stock(t_env *env, t_m *m);
void	ft_fdf(t_env *env, t_tab *tab, t_m *m);
/*
**trace
*/
void	ft_trace_x(int xi, int yi, int xf, int yf, t_env *env);
void	ft_trace_y(int xi, int yi, int xf, int yf, t_env *env);
void	ft_ttrace_x(t_m *m, t_env *env);
void	ft_ttrace_y(t_m *m, t_env *env);
int		ft_ride_around(t_env *env, t_m *m);
/*
**tools
*/
void	ft_count_size(t_tab *tab, t_m *m);
t_tab	*ft_make_x_y(t_tab *tab, t_m *m);
/*
**free
*/
void	ft_free_tabstr(char **tab);
#endif
