/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yer-raki <yer-raki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 10:15:11 by yer-raki          #+#    #+#             */
/*   Updated: 2021/01/14 14:21:45 by yer-raki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	player(t_data *tmp)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (tmp->nb_row > j)
	{
		i = 0;
		while (tmp->nb_col > i)
		{
			if (tmp->map[j][i] == 'N' || tmp->map[j][i] == 'S' ||
					tmp->map[j][i] == 'E' || tmp->map[j][i] == 'W')
			{
				tmp->px = (i * TILE_SIZE) + (TILE_SIZE / 2);
				tmp->py = (j * TILE_SIZE) + (TILE_SIZE / 2);
			}
			i++;
		}
		j++;
	}
	init_straight(tmp);
	mlx_put_image_to_window(tmp->mlx_ptr, tmp->mlx_win, tmp->img, 0, 0);
}

void	move_player(t_data *tmp, int keycode)
{
	float x1;
	float y1;
	float x2;
	float y2;

	x1 = tmp->p_movespeed * cos(tmp->p_rotationangle) * tmp->walk_d;
	y1 = tmp->p_movespeed * sin(tmp->p_rotationangle) * tmp->walk_d;
	x2 = tmp->p_movespeed * cos(tmp->p_rotationangle - M_PI / 2) * tmp->walk_r;
	y2 = tmp->p_movespeed * sin(tmp->p_rotationangle - M_PI / 2) * tmp->walk_r;
	if ((keycode == FORWARD_W || keycode == BACK_S)
			&& !check_wall(tmp, tmp->px + x1, tmp->py + y1, keycode)
			&& !check_wall(tmp, tmp->px + x1, tmp->py, keycode)
			&& !check_wall(tmp, tmp->px, tmp->py + y1, keycode))
	{
		tmp->px += x1;
		tmp->py += y1;
	}
	else if ((keycode == LEFT_A || keycode == RIGHT_D)
			&& !check_wall(tmp, tmp->px + x2, tmp->py + y2, keycode)
			&& !check_wall(tmp, tmp->px + x2, tmp->py, keycode)
			&& !check_wall(tmp, tmp->px, tmp->py + y2, keycode))
	{
		tmp->px += x2;
		tmp->py += y2;
	}
}
