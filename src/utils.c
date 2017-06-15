/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <nbeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 19:15:00 by nbeny             #+#    #+#             */
/*   Updated: 2017/06/15 19:15:02 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_len(char *str)
{
	int		len;
	int		i;
	int		l;

	l = 0;
	i = 0;
	len = 0;
	while (str[i])
	{
		if (str[i] == ' ' && l == 1)
			l = 0;
		if (str[i] != ' ' && l == 0)
		{
			len++;
			l = 1;
		}
		i++;
	}
	return (len);
}

int		ft_count_rows(char *name)
{
	char	*ret;
	int		res;
	int		f;

	res = 0;
	f = open(name, O_RDONLY);
	while (get_next_line(f, &ret) > 0)
	{
		res++;
		if (ret != NULL)
		{
			ft_strdel(&ret);
			ret = NULL;
		}
	}
	close(f);
	return (res);
}
