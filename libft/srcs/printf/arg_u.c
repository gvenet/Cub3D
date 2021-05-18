/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_u.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvenet <gvenet@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 15:18:56 by gvenet            #+#    #+#             */
/*   Updated: 2021/02/09 11:28:35 by gvenet           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

const char		*arg_u(const char *f, va_list ap, t_d *d)
{
	unsigned int arg_u;

	arg_u = (unsigned int)va_arg(ap, unsigned int);
	arg_u_calc(arg_u, d);
	while (d->flag_minus == 0 && d->nb_s > 0)
		space_print(d);
	ft_putnbr_printf_u(arg_u, d);
	while (d->flag_minus == 1 && d->nb_s > 0)
		space_print(d);
	f++;
	return (f);
}

void			arg_u_calc(unsigned int arg_u, t_d *d)
{
	d->d_len = intlen(arg_u);
	if (d->nb_z < 0)
		d->precision = 0;
	if (d->precision == 1)
		arg_u_calc_precision_true(arg_u, d);
	else if (d->precision == 0)
	{
		if (d->flag_zero == 1 && d->nb_s > 0)
		{
			d->nb_z = d->nb_s - d->d_len;
			d->nb_s = 0;
		}
		arg_u_calc_algo(d);
	}
}

void			arg_u_calc_precision_true(unsigned int arg_u, t_d *d)
{
	if (arg_u == 0)
	{
		d->prt_0 = 0;
		d->d_len = 0;
		arg_u_calc_algo(d);
	}
	else if (arg_u > 0)
	{
		d->nb_z += -d->d_len;
		arg_u_calc_algo(d);
	}
}

void			arg_u_calc_algo(t_d *d)
{
	if (d->nb_z < 0)
		d->nb_z = 0;
	if (d->nb_s >= 0)
		d->nb_s += -d->nb_z - d->d_len;
	else if (d->nb_s < 0)
	{
		d->flag_minus = 1;
		d->nb_s = (d->nb_s * -1) - d->nb_z - d->d_len;
	}
}

void			ft_putnbr_printf_u(unsigned int nb, t_d *d)
{
	if (nb < 0)
	{
		d->prt++;
		ft_putchar('-');
		nb *= -1;
	}
	if (nb > 9)
	{
		d->prt++;
		ft_putnbr_printf(nb / 10, d);
		ft_putchar((nb % 10) + '0');
	}
	else
	{
		while (d->nb_z > 0)
			zero_print(d);
		if (d->prt_0 == 1)
		{
			d->prt++;
			ft_putchar(nb + '0');
		}
	}
}
