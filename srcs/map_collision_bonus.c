/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_collision_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yer-raki <yer-raki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 17:56:56 by yer-raki          #+#    #+#             */
/*   Updated: 2021/01/14 14:25:02 by yer-raki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		check_wall(t_data *tmp, double x, double y, int keycode)
{
	int v;
	int w;

	v = 0;
	w = 0;
	if (keycode == FORWARD_W || keycode == BACK_S)
	{
		v = (x + 0 * tmp->p_movespeed * cos(tmp->p_rotationangle)
				* tmp->walk_d) / (TILE_SIZE);
		w = (y + 0 * tmp->p_movespeed * sin(tmp->p_rotationangle)
				* tmp->walk_d) / (TILE_SIZE);
	}
	else if (keycode == RIGHT_D || keycode == LEFT_A)
	{
		v = (x + 0 * tmp->p_movespeed * cos(tmp->p_rotationangle -
					(M_PI / 10) * tmp->walk_r)) / (TILE_SIZE);
		w = (y + 0 * tmp->p_movespeed * sin(tmp->p_rotationangle -
					(M_PI / 2) * tmp->walk_r)) / (TILE_SIZE);
	}
	if (tmp->map[w][v] == '1' || tmp->map[w][v] == '2')
		return (1);
	return (0);
}

int		check_wall2(t_data *tmp, double x, double y)
{
	int i;
	int j;

	i = (x / TILE_SIZE);
	j = (y / TILE_SIZE);
	if (ray_facing_ud(tmp) == 'u')
		j--;
	if (i >= tmp->nb_col || j >= tmp->nb_row || j < 0 ||
			i < 0 || tmp->map[j][i] == '1')
		return (1);
	return (0);
}

int		check_wall3(t_data *tmp, double x, double y)
{
	int i;
	int j;

	i = (x / TILE_SIZE);
	j = (y / TILE_SIZE);
	if (ray_facing_rl(tmp) == 'l')
		i--;
	if (j >= tmp->nb_row || i >= tmp->nb_col || j < 0 ||
			i < 0 || tmp->map[j][i] == '1')
		return (1);
	return (0);
}

double	total_nb_delta_h(t_data *tmp)
{
	double d;

	tmp->h_v = tmp->xinter_h;
	tmp->h_w = tmp->yinter_h;
	while (check_wall2(tmp, tmp->h_v, tmp->h_w) == 0)
	{
		tmp->h_v += tmp->xdelta_h;
		tmp->h_w += tmp->ydelta_h;
	}
	d = sqrt(pow((tmp->h_v - tmp->xinter_h), 2) +
			pow((tmp->h_w - tmp->yinter_h), 2));
	return (d);
}

double	total_nb_delta_v(t_data *tmp)
{
	double d;

	tmp->v_v = tmp->xinter_v;
	tmp->v_w = tmp->yinter_v;
	while (check_wall3(tmp, tmp->v_v, tmp->v_w) == 0)
	{
		tmp->v_v += tmp->xdelta_v;
		tmp->v_w += tmp->ydelta_v;
	}
	d = sqrt(pow((tmp->v_v - tmp->xinter_v), 2) +
			pow((tmp->v_w - tmp->yinter_v), 2));
	return (d);
}
