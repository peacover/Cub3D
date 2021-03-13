/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_map.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yer-raki <yer-raki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 00:59:00 by yer-raki          #+#    #+#             */
/*   Updated: 2021/02/04 15:58:03 by yer-raki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		key_hook2(t_data *tmp)
{
	mlx_destroy_window(tmp->mlx_ptr, tmp->mlx_win);
	exit(0);
	return (0);
}

void	init_map(t_data *tmp)
{
	tmp->mlx_ptr = mlx_init();
	tmp->mlx_win = mlx_new_window(tmp->mlx_ptr, tmp->rx, tmp->ry, "");
	tmp->img = mlx_new_image(tmp->mlx_ptr, tmp->rx, tmp->ry);
	tmp->addr = mlx_get_data_addr(tmp->img, &tmp->bpp,
			&tmp->line_l, &tmp->endian);
	textures(tmp);
	player(tmp);
	mlx_hook(tmp->mlx_win, 02, 1L << 0, key_hook, tmp);
	mlx_hook(tmp->mlx_win, 17, 0, key_hook2, tmp);
	if (g_arg_save == 1)
		save_img(tmp);
	mlx_loop(tmp->mlx_ptr);
}

int		key_hook(int keycode, t_data *tmp)
{
	tmp->walk_d = 0;
	if (keycode == FORWARD_W)
		tmp->walk_d = 1;
	else if (keycode == BACK_S)
		tmp->walk_d = -1;
	else if (keycode == RIGHT_D)
		tmp->walk_r = -1;
	else if (keycode == LEFT_A)
		tmp->walk_r = 1;
	else if (keycode == ROTATE_RIGHT)
		tmp->turn_d = 1;
	else if (keycode == ROTATE_LEFT)
		tmp->turn_d = -1;
	if (keycode == ESC)
		exit(0);
	if (keycode == ROTATE_RIGHT || keycode == ROTATE_LEFT)
		tmp->p_rotationangle += tmp->turn_d * tmp->p_rotationspeed;
	move_player(tmp, keycode);
	draw_rays(tmp);
	mlx_put_image_to_window(tmp->mlx_ptr, tmp->mlx_win, tmp->img, 0, 0);
	return (1);
}

size_t	ft_strlen3(const char *str)
{
	size_t t;
	size_t i;

	t = 0;
	i = 0;
	if (!str)
		return (0);
	while (str[i] == '0')
		i++;
	while (str[i])
	{
		i++;
		t++;
	}
	return (t);
}
