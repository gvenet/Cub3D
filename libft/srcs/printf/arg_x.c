/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_x.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvenet <gvenet@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 12:56:11 by gvenet            #+#    #+#             */
/*   Updated: 2021/02/09 11:28:41 by gvenet           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

const char		*arg_x(const char *f, va_list ap, t_d *d, char *base)
{
	unsigned int arg_x;

	arg_x = (unsigned int)va_arg(ap, unsigned int);
	arg_x_calc(arg_x, d);
	while (d->flag_minus == 0 && d->nb_s > 0)
		space_print(d);
	ft_putnbr_base(arg_x, base, d);
	while (d->flag_minus == 1 && d->nb_s > 0)
		space_print(d);
	f++;
	return (f);
}

void			arg_x_calc(unsigned long arg_x, t_d *d)
{
	x_len(arg_x, d);
	if (d->nb_z < 0)
		d->precision = 0;
	if (d->precision == 1)
		arg_x_calc_precision_true(arg_x, d);
	else if (d->precision == 0)
	{
		if (d->flag_zero == 1 && d->nb_s > 0)
		{
			d->nb_z = d->nb_s - d->x_len;
			d->nb_s = 0;
		}
		arg_x_calc_algo(d);
	}
}

void			arg_x_calc_precision_true(unsigned long arg_x, t_d *d)
{
	if (arg_x == 0)
	{
		d->prt_0 = 0;
		d->x_len = 0;
		arg_x_calc_algo(d);
	}
	else if (arg_x > 0)
	{
		d->nb_z += -d->x_len;
		if (d->nb_z < 0)
			d->nb_z = 0;
		arg_x_calc_algo(d);
	}
	else if (arg_x < 0)
	{
		d->x_len--;
		d->nb_z += -d->x_len;
		d->x_len++;
		if (d->nb_z < 0)
			d->nb_z = 0;
		arg_x_calc_algo(d);
	}
}

void			arg_x_calc_algo(t_d *d)
{
	if (d->nb_z < 0)
		d->nb_z = 0;
	if (d->nb_s >= 0)
		d->nb_s += -d->nb_z - d->x_len;
	else if (d->nb_s < 0)
	{
		d->flag_minus = 1;
		d->nb_s = (d->nb_s * -1) - d->nb_z - d->x_len;
	}
}

void			ft_putnbr_base(unsigned long n, char *base, t_d *d)
{
	unsigned long	len_base;

	len_base = ft_strlen(base);
	if (len_base > 1)
	{
		if (n >= len_base)
		{
			ft_putnbr_base(n / len_base, base, d);
			ft_putnbr_base(n % len_base, base, d);
		}
		else
		{
			while (d->nb_z > 0)
				zero_print(d);
			if (d->prt_0 == 1)
			{
				d->prt++;
				ft_putchar(base[n % len_base]);
			}
		}
	}
}
