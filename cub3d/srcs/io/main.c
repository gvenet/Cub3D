/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvenet <gvenet@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 09:31:11 by gvenet            #+#    #+#             */
/*   Updated: 2021/03/01 14:14:59 by gvenet           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	render(t_data *d)
{
	minimap(d->mlx, &(d->map), &(d->p), d);
	if (d->save.save == false)
	{
		mlx_hook(d->win.win, 17, 0, red_cross, d);
		mlx_hook(d->map.w_map.win, 17, 0, red_cross, d);
		mlx_hook(d->win.win, 2, 0, key_presse, d);
		mlx_hook(d->win.win, 3, 0, key_release, d);
		mlx_loop_hook(d->mlx, move_player, d);
	}
	else
	{
		d->save.addr = (int*)mlx_get_data_addr(d->img.img, &d->img.bpp,
		&(d->img.l_size), &(d->img.endian));
		create_bmp("img.bmp", d);
		d->error = 0;
		leave(d);
	}
}

int		main(int ac, char **av)
{
	t_data	d_;
	t_data	*d;

	d = &d_;
	d->error = 1;
	d->save.save = false;
	alloc_var_init(d);
	if (ac == 3 && !ft_strcmp(av[2], "--save"))
		d->save.save = true;
	else if (ac != 2)
		leave(d);
	if (!av[1])
		leave(d);
	data_init(d, av[1]);
	render(d);
	mlx_loop(d->mlx);
	return (0);
}
