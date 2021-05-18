/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_p.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvenet <gvenet@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 16:53:16 by gvenet            #+#    #+#             */
/*   Updated: 2021/02/09 11:28:15 by gvenet           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

const char		*arg_p(const char *f, va_list ap, t_d *d)
{
	unsigned long int arg_p;

	arg_p = (unsigned long)va_arg(ap, unsigned long);
	arg_p_calc(arg_p, d);
	while (d->flag_minus == 0 && d->nb_s > 0)
		space_print(d);
	write(1, "0x", 2);
	d->prt += 2;
	ft_putnbr_base(arg_p, "0123456789abcdef", d);
	while (d->flag_minus == 1 && d->nb_s > 0)
		space_print(d);
	f++;
	return (f);
}

void			arg_p_calc(unsigned long arg_p, t_d *d)
{
	x_len(arg_p, d);
	if (d->nb_s < 0)
	{
		d->flag_minus = 1;
		d->nb_s *= -1;
	}
	if (arg_p == 0 && d->precision == 1)
		d->prt_0 = 0;
	d->nb_s += -d->x_len - 2;
}

void			x_len(unsigned long n, t_d *d)
{
	while (n > 15)
	{
		n = n / 16;
		d->x_len++;
	}
	d->x_len++;
}
