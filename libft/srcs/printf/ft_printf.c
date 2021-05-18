/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvenet <gvenet@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 08:12:49 by gvenet            #+#    #+#             */
/*   Updated: 2021/02/24 08:09:34 by gvenet           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

static void				data_init(t_d *d)
{
	d->nb_z = 0;
	d->nb_s = 0;
	d->prt_0 = 1;
	d->precision = 0;
	d->flag_minus = 0;
	d->flag_zero = 0;
	d->x_len = 0;
	d->d_len = 0;
	d->precision_casted = 0;
}

int						ft_printf(const char *f, ...)
{
	va_list	ap;
	t_d		d_;
	t_d		*d;

	va_start(ap, f);
	d = &d_;
	d->prt = 0;
	while (*f != '\0')
	{
		while (*f == '%')
		{
			data_init(d);
			f = select_flag(f, ap, d);
		}
		if (*f != '\0')
		{
			write(1, f, 1);
			f++;
			d->prt++;
		}
	}
	va_end(ap);
	return (d->prt);
}
