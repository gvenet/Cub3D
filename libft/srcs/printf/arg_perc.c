/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_perc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvenet <gvenet@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 08:01:51 by gvenet            #+#    #+#             */
/*   Updated: 2021/02/09 11:28:21 by gvenet           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

const char			*arg_perc(const char *f, t_d *d)
{
	arg_perc_calc(d);
	while (d->flag_minus == 0 && d->nb_s > 0)
		space_print(d);
	while (d->nb_z > 0)
		zero_print(d);
	ft_putchar('%');
	d->prt++;
	while (d->flag_minus == 1 && d->nb_s > 0)
		space_print(d);
	f++;
	return (f);
}

void				arg_perc_calc(t_d *d)
{
	if (d->flag_zero == 1)
	{
		if (d->nb_s > 0)
		{
			d->nb_z = d->nb_s - 1;
			d->nb_s = 0;
		}
		else if (d->nb_s <= 0 && d->precision == 1)
			d->nb_z = 0;
	}
	if (d->nb_s < 0)
	{
		d->flag_minus = 1;
		d->nb_s *= -1;
	}
	if (d->precision == 1 && d->flag_zero == 0)
		d->nb_z = 0;
	d->nb_s += -1;
}
