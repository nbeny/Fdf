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

typedef struct s_coor
{
	int		ret;
	int		i;
	int		j;
	int		x;
	int		y;
	int		z;
	void	*mlx;
	void	*win;
	int		fd;
	char	*line;
	char	**powa;
}				t_coor;

typedef struct	s_mlx
{
	void	*mlx;
	void	*win;
	char	*line;
	char	**split;
	int		fd;
}				t_mlx;

typedef struct	s_map
{
	int	x;
	int	y;
	int	z;
	int	i;
	int	j;
}				t_map;

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
t_mlx	*ft_init_mlx(char **av);
t_map	*ft_init_map(void);
t_save	*ft_init_save(void);
int		ft_fdf(t_mlx *mlx, t_map *map);
int		main(int ac, char **av);
/*
**trace
*/
void	ft_trace_x(int xi, int yi, int xf, int yf, t_mlx *mlx);
void	ft_trace_y(int xi, int yi, int xf, int yf, t_mlx *mlx);
int		ft_ride_around(t_mlx *mlx, t_map *map, int j);
/*
**free
*/
void	ft_free_tabstr(char **tab);
#endif
