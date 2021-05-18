/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_s.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvenet <gvenet@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 08:11:57 by gvenet            #+#    #+#             */
/*   Updated: 2021/02/09 11:28:27 by gvenet           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

const char		*arg_s(const char *f, va_list ap, t_d *d)
{
	char *arg_s;
	void *trash;

	if (d->precision_casted != 0 || d->precision != 1)
	{
		arg_s = (char*)va_arg(ap, char*);
		arg_s_calc(&arg_s, d);
		while (d->flag_minus == 0 && d->nb_s > 0)
			space_print(d);
		ft_putstr_printf(arg_s, d);
		while (d->flag_minus == 1 && d->nb_s > 0)
			space_print(d);
	}
	else
		trash = (void*)va_arg(ap, void*);
	f++;
	return (f);
}

void			arg_s_calc(char **arg_s, t_d *d)
{
	int s_len;

	if (*arg_s == NULL)
		*arg_s = "(null)";
	s_len = ft_strlen(*arg_s);
	if (d->nb_z < 0)
		d->precision = 0;
	if (d->precision == 1)
		arg_s_calc_precision_true(d, s_len);
	else if (d->precision == 0)
		arg_s_calc_precision_false(d, s_len);
}

void			arg_s_calc_precision_true(t_d *d, int s_len)
{
	if (d->nb_s < 0)
	{
		d->flag_minus = 1;
		d->nb_s = (d->nb_s * -1);
	}
	if (d->nb_z < 0)
		d->nb_z *= -1;
	if (d->nb_z < s_len)
		d->nb_s += -d->nb_z;
	else if (d->nb_z >= s_len)
		d->nb_s += -s_len;
}

void			arg_s_calc_precision_false(t_d *d, int s_len)
{
	if (d->flag_zero == 1)
		d->nb_z = d->nb_s - s_len;
	else if (d->nb_s < 0)
	{
		d->flag_minus = 1;
		d->nb_s = (d->nb_s * -1) - s_len;
	}
	else
		d->nb_s = d->nb_s - s_len;
}

void			ft_putstr_printf(char *s, t_d *d)
{
	int i;

	i = 0;
	while (d->precision == 1 && i < d->nb_z && s[i] != 0)
	{
		write(1, &s[i], 1);
		d->prt++;
		i++;
	}
	while (d->precision == 0 && s[i] != 0)
	{
		write(1, &s[i], 1);
		d->prt++;
		i++;
	}
}
