/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvenet <gvenet@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 14:17:51 by gvenet            #+#    #+#             */
/*   Updated: 2021/02/09 11:28:01 by gvenet           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

const char		*arg_d(const char *f, va_list ap, t_d *d)
{
	int arg_d;

	arg_d = (int)va_arg(ap, int);
	arg_d_calc(arg_d, d);
	while (d->flag_minus == 0 && d->nb_s > 0)
		space_print(d);
	ft_putnbr_printf(arg_d, d);
	while (d->flag_minus == 1 && d->nb_s > 0)
		space_print(d);
	f++;
	return (f);
}

void			arg_d_calc(int arg_d, t_d *d)
{
	d->d_len = intlen(arg_d);
	if (d->nb_z < 0)
		d->precision = 0;
	if (d->precision == 1)
		arg_d_calc_precision_true(arg_d, d);
	else if (d->precision == 0)
	{
		if (d->flag_zero == 1 && d->nb_s > 0)
		{
			if (d->flag_minus == 0)
			{
				d->nb_z = d->nb_s - d->d_len;
				d->nb_s = 0;
			}
		}
		arg_d_calc_algo(d);
	}
}

void			arg_d_calc_precision_true(int arg_d, t_d *d)
{
	if (arg_d == 0)
	{
		d->prt_0 = 0;
		d->d_len = 0;
		arg_d_calc_algo(d);
	}
	else if (arg_d > 0)
	{
		d->nb_z += -d->d_len;
		arg_d_calc_algo(d);
	}
	else if (arg_d < 0)
	{
		d->d_len--;
		d->nb_z += -d->d_len;
		d->d_len++;
		arg_d_calc_algo(d);
	}
}

void			arg_d_calc_algo(t_d *d)
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

void			ft_putnbr_printf(int n, t_d *d)
{
	long nb;

	nb = n;
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
