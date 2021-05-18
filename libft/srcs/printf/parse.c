/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvenet <gvenet@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 13:31:10 by gvenet            #+#    #+#             */
/*   Updated: 2021/02/09 11:28:53 by gvenet           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

const char			*parse_digit_dot(const char *f, va_list ap, t_d *d)
{
	f = parse(f, d);
	d->nb_s = ft_atoi(d->tmp);
	free(d->tmp);
	d->tmp = NULL;
	if (*f == '.')
		f = select_precision(f, ap, d);
	return (f);
}

const char			*parse_dot_digit(const char *f, t_d *d)
{
	d->precision_casted = 1;
	f = parse(f, d);
	d->nb_z = ft_atoi(d->tmp);
	free(d->tmp);
	d->tmp = NULL;
	return (f);
}

const char			*parse(const char *f, t_d *d)
{
	int i;

	i = 0;
	while (f[i] >= '0' && f[i] <= '9')
		i++;
	if (!(d->tmp = (char*)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = 0;
	while (*f >= '0' && *f <= '9')
		d->tmp[i++] = *f++;
	d->tmp[i] = '\0';
	return (f);
}

const char			*parse_star_dot(const char *f, va_list ap, t_d *d)
{
	f++;
	d->nb_s = (int)va_arg(ap, int);
	if (*f == '.')
		f = select_precision(f, ap, d);
	return (f);
}

const char			*parse_dot_star(const char *f, va_list ap, t_d *d)
{
	d->precision_casted = 1;
	d->nb_z = (int)va_arg(ap, int);
	f++;
	return (f);
}
