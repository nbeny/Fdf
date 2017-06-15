/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <nbeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 19:14:46 by nbeny             #+#    #+#             */
/*   Updated: 2017/06/15 19:14:49 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_parce_arguments(char **av)
{
	struct stat	st;

	if (stat(av[1], &st) == -1)
	{
		ft_printf(2, "fdf: please give me a map.\n");
		exit(EXIT_FAILURE);
	}
	if (S_ISREG(st.st_mode) == 1)
		return (1);
	else
	{
		ft_printf(2, "fdf: please give me a map.\n");
		return (0);
	}
}

int		*ft_char_to_int(char *str)
{
	int		*map;
	int		i;
	int		max;

	i = 0;
	max = ft_len(str);
	if (!(map = (int *)malloc(sizeof(int) * (max + 1))))
		return (NULL);
	while (*str)
	{
		if (*str == ' ')
			str++;
		else
		{
			map[i] = ft_atoi(str);
			while (*str != ' ' && *str != '\0')
				str++;
			i++;
		}
	}
	return (map);
}

int		ft_transform_map(t_env *e, char **av)
{
	int		fd;
	char	*line;
	int		i;

	e->s_y = ft_count_rows(av[1]);
	i = 0;
	if (!(e->mapi = (int **)malloc(sizeof(int *) * (e->s_y + 1))))
		return (0);
	fd = open(av[1], O_RDONLY);
	get_next_line(fd, &line);
	e->s_x = ft_len(line);
	if ((e->mapi[i] = ft_char_to_int(line)) == NULL)
		return (0);
	ft_strdel(&line);
	i++;
	while (get_next_line(fd, &line))
	{
		if (e->s_x != ft_len(line))
			return (0);
		if ((e->mapi[i] = ft_char_to_int(line)) == NULL)
			return (0);
		ft_strdel(&line);
		i++;
	}
	return (1);
}

t_3d	ft_new_loop(int x, int y, int z)
{
	t_3d	p;

	p.x = x;
	p.y = y - (z * AXE_Z);
	return (p);
}

int		ft_loop_3d(t_env *e)
{
	int		i;
	int		j;

	if (!(e->loop = (t_3d **)malloc(sizeof(t_3d *) * (e->s_y + 1))))
		return (0);
	i = -1;
	e->x = DOT_X;
	e->y = DOT_Y;
	while (++i < e->s_y)
	{
		if (!(e->loop[i] = (t_3d *)malloc(sizeof(t_3d) * (e->s_x + 1))))
			return (0);
		j = -1;
		e->x = DOT_X - (PIX * (i + 1));
		e->y = (DOT_Y + (PIX * (i + 1))) >> 2;
		while (++j < e->s_x)
		{
			e->x += PIX;
			e->y += PIX;
			e->loop[i][j] = ft_new_loop(e->x, e->y, e->mapi[i][j]);
		}
	}
	e->loop[i] = NULL;
	return (1);
}
