/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yer-raki <yer-raki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 11:27:13 by yer-raki          #+#    #+#             */
/*   Updated: 2021/01/14 15:12:30 by yer-raki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_straight2(t_data *tmp)
{
	tmp->xdelta_v = TILE_SIZE;
	ray_facing_rl(tmp) == 'l' ? (tmp->xdelta_v *= -1)
		: (tmp->xdelta_v *= 1);
	tmp->ydelta_v = tan(tmp->p_rotationangle) * TILE_SIZE;
	(ray_facing_ud(tmp) == 'u' && tmp->ydelta_v > 0) ?
		(tmp->ydelta_v *= -1) : (tmp->ydelta_v *= 1);
	(ray_facing_ud(tmp) == 'd' && tmp->ydelta_v < 0) ?
		(tmp->ydelta_v *= -1) : (tmp->ydelta_v *= 1);
	tmp->d_h = (tmp->yinter_h - tmp->py) / sin(tmp->p_rotationangle)
		+ total_nb_delta_h(tmp);
	tmp->d_v = sqrt(pow((tmp->px - tmp->xinter_v), 2) +
			pow((tmp->py - tmp->yinter_v), 2)) + total_nb_delta_v(tmp);
	tmp->hit_type = (fabs(tmp->d_h) > fabs(tmp->d_v)) ? 'v' : 'h';
	tmp->d = fmin(fabs(tmp->d_h), fabs(tmp->d_v));
}

void	draw_straight(t_data *tmp)
{
	tmp->p_rotationangle = fix_angle(tmp->p_rotationangle);
	tmp->yinter_h = (int)(tmp->py / TILE_SIZE) * TILE_SIZE;
	ray_facing_ud(tmp) == 'd' ? tmp->yinter_h += (TILE_SIZE) : 0;
	tmp->xinter_h = tmp->px + ((tmp->yinter_h - tmp->py) /
			tan(tmp->p_rotationangle));
	tmp->xinter_v = (int)(tmp->px / TILE_SIZE) * TILE_SIZE;
	ray_facing_rl(tmp) == 'r' ? tmp->xinter_v += (TILE_SIZE) : 0;
	tmp->yinter_v = tmp->py + ((tmp->xinter_v - tmp->px) *
			tan(tmp->p_rotationangle));
	tmp->ydelta_h = TILE_SIZE;
	ray_facing_ud(tmp) == 'u' ? (tmp->ydelta_h *= -1) : (tmp->ydelta_h *= 1);
	tmp->xdelta_h = (TILE_SIZE) / tan(tmp->p_rotationangle);
	(ray_facing_rl(tmp) == 'l' && tmp->xdelta_h > 0) ?
		(tmp->xdelta_h *= -1) : (tmp->xdelta_h *= 1);
	(ray_facing_rl(tmp) == 'r' && tmp->xdelta_h < 0) ?
		(tmp->xdelta_h *= -1) : (tmp->xdelta_h *= 1);
	draw_straight2(tmp);
}

void	draw_rays2(t_data *tmp, float end, float new_d, float t)
{
	int		x;
	float	i;
	float	step;

	x = 0;
	i = tmp->p_rotationangle;
	step = FOV_ANGLE / tmp->rx;
	while (i < end)
	{
		tmp->p_rotationangle += step;
		draw_straight(tmp);
		i += step;
		new_d = tmp->d * cos(tmp->p_rotationangle - t);
		g_ray_d[x] = tmp->d;
		tmp->disprojplane = (tmp->rx / 2.0) / tan(FOV_ANGLE / 1.5);
		tmp->wallstripheight = (TILE_SIZE / new_d) * tmp->disprojplane;
		draw_walls(tmp, x, (tmp->ry / 2) - (tmp->wallstripheight / 2),
				get_texture_index(tmp));
		x++;
	}
}

void	draw_rays(t_data *tmp)
{
	float		end;
	float		t;
	float		new_d;
	t_sprite	*s;

	new_d = 0;
	t = tmp->p_rotationangle;
	tmp->p_rotationangle -= (FOV_ANGLE / 2.0);
	end = tmp->p_rotationangle + (FOV_ANGLE);
	if (!(g_ray_d = malloc(sizeof(float) * (tmp->rx + 1))))
		errors_msg(12);
	draw_rays2(tmp, end, new_d, t);
	tmp->p_rotationangle = t;
	if (!(s = malloc(sizeof(t_sprite) * (tmp->nb_sp + 1))))
		errors_msg(12);
	sprite_info(tmp, s);
	free(g_ray_d);
}
