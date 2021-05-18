/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_c.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvenet <gvenet@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 14:19:16 by gvenet            #+#    #+#             */
/*   Updated: 2021/02/09 11:27:45 by gvenet           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

const char			*arg_c(const char *f, va_list ap, t_d *d)
{
	char arg_c;

	arg_c = (char)va_arg(ap, int);
	arg_c_calc(d);
	while (d->flag_minus == 0 && d->nb_s > 0)
		space_print(d);
	write(1, &arg_c, 1);
	d->prt++;
	while (d->flag_minus == 1 && d->nb_s > 0)
		space_print(d);
	f++;
	return (f);
}

void				arg_c_calc(t_d *d)
{
	if (d->nb_s < 0)
	{
		d->flag_minus = 1;
		d->nb_s *= -1;
	}
	d->nb_s += -1;
}
