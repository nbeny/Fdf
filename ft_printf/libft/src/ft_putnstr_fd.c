/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnstr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <nbeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/20 10:06:30 by nbeny             #+#    #+#             */
/*   Updated: 2017/05/20 10:06:32 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int		ft_putnstr_fd(int fd, char *s, size_t n)
{
	if (s && fd >= 0 && fd <= 2)
		write(fd, s, n);
	return (1);
}
