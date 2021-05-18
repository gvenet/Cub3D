/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvenet <gvenet@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 13:34:43 by gvenet            #+#    #+#             */
/*   Updated: 2021/02/09 11:29:11 by gvenet           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

void		ft_putchar(char c)
{
	write(1, &c, 1);
}

int			intlen(long long nl)
{
	int			len;

	len = 1;
	if (nl < 0)
	{
		nl *= -1;
		len++;
	}
	while (nl > 9)
	{
		nl /= 10;
		len++;
	}
	return (len);
}

void		zero_print(t_d *d)
{
	d->prt++;
	ft_putchar('0');
	d->nb_z--;
}

void		space_print(t_d *d)
{
	d->prt++;
	ft_putchar(' ');
	d->nb_s--;
}
