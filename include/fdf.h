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
# define SIZE 20
# include "../ft_printf/include/ft_printf.h"
# include "../minilibx/mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h> 

typedef struct s_coor
{
	int		i;
	int		x;
	int		y;
	int		z;
	void	*mlx;
	void	*win;
	int		fd;
	char	*line;
	char	**powa;
}				t_coor;


/*
**main
*/
t_coor	*ft_init_coor(char **av);
int		main(int ac, char **av);
/*
**free
*/
void	ft_free_tabstr(char **tab);
#endif
