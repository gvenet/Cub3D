/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvenet <gvenet@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 14:22:47 by gvenet            #+#    #+#             */
/*   Updated: 2021/02/09 11:29:02 by gvenet           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

const char			*select_flag(const char *f, va_list ap, t_d *d)
{
	f++;
	if (*f == '*')
		f = parse_star_dot(f, ap, d);
	else if (*f == '0')
	{
		d->flag_zero = 1;
		f = select_flag(f, ap, d);
	}
	else if (*f == '-')
	{
		d->flag_minus = 1;
		f = select_flag(f, ap, d);
	}
	else if (*f > '0' && *f <= '9')
		f = parse_digit_dot(f, ap, d);
	else if (*f == '.')
		f = select_precision(f, ap, d);
	f = select_arg(f, ap, d);
	return (f);
}

const char			*select_precision(const char *f, va_list ap, t_d *d)
{
	d->precision = 1;
	f++;
	if (*f == '*')
		f = parse_dot_star(f, ap, d);
	else if (*f >= '0' && *f <= '9')
		f = parse_dot_digit(f, d);
	return (f);
}

const char			*select_arg(const char *f, va_list ap, t_d *d)
{
	if (*f == '%')
		f = arg_perc(f, d);
	else if (*f == 'd' || *f == 'i')
		f = arg_d(f, ap, d);
	else if (*f == 'c')
		f = arg_c(f, ap, d);
	else if (*f == 's')
		f = arg_s(f, ap, d);
	else if (*f == 'u')
		f = arg_u(f, ap, d);
	else if (*f == 'x')
		f = arg_x(f, ap, d, "0123456789abcdef");
	else if (*f == 'X')
		f = arg_x(f, ap, d, "0123456789ABCDEF");
	else if (*f == 'p')
		f = arg_p(f, ap, d);
	return (f);
}
