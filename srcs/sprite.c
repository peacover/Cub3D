/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yer-raki <yer-raki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 09:49:15 by yer-raki          #+#    #+#             */
/*   Updated: 2021/01/25 17:25:35 by yer-raki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	sprite_info2(t_data *tmp, t_sprite *t)
{
	int i;

	sort_sprites(tmp, t);
	i = -1;
	while (++i < tmp->nb_sp)
		sprite_calcul(tmp, t, i);
	free(t);
}

void	sprite_info(t_data *tmp, t_sprite *t)
{
	int			x;
	int			y;
	int			i;

	y = -1;
	i = 0;
	while (++y < tmp->nb_row)
	{
		x = 0;
		while (tmp->map[y][x])
		{
			if (tmp->map[y][x] == '2')
			{
				t[i].x = (x * TILE_SIZE) + (TILE_SIZE / 2.0);
				t[i].y = (y * TILE_SIZE) + (TILE_SIZE / 2.0);
				t[i].d = sqrtf(pow((tmp->px - t[i].x), 2) +
						pow((tmp->py - t[i].y), 2));
				i++;
			}
			x++;
		}
	}
	sprite_info2(tmp, t);
}

void	sprite_calcul(t_data *tmp, t_sprite *t, int i)
{
	float	sp_angle;
	float	sp_size;

	sp_angle = atan2(t[i].y - tmp->py, t[i].x - tmp->px);
	while (sp_angle - tmp->p_rotationangle > M_PI)
		sp_angle -= 2.0 * M_PI;
	while (sp_angle - tmp->p_rotationangle < -M_PI)
		sp_angle += 2.0 * M_PI;
	sp_size = (TILE_SIZE / t[i].d) * (tmp->rx / 2.0) / tan(FOV_ANGLE / 1.5);
	t[i].x_offset = (sp_angle - tmp->p_rotationangle) /
		FOV_ANGLE * tmp->rx + (tmp->rx / 2 - sp_size / 2);
	t[i].y_offset = (tmp->ry / 2 - sp_size / 2);
	draw_sprite(tmp, t, i, sp_size);
}

void	sort_sprites(t_data *tmp, t_sprite *t)
{
	int			i;
	int			j;
	t_sprite	temp;

	i = 0;
	while (i < tmp->nb_sp)
	{
		j = 0;
		while (j < tmp->nb_sp - i - 1)
		{
			if (t[j].d < t[j + 1].d)
			{
				temp = t[j];
				t[j] = t[j + 1];
				t[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

void	draw_sprite(t_data *tmp, t_sprite *t, int k, float sp_size)
{
	int i;
	int j;
	int color;

	i = -1;
	while (++i < sp_size - 1)
	{
		if (t[k].x_offset + i < 0 || t[k].x_offset + i > tmp->rx
				|| g_ray_d[(int)t[k].x_offset + i] <= t[k].d)
			continue ;
		j = -1;
		while (++j < sp_size - 1)
		{
			if (t[k].y_offset + j < 0 || t[k].y_offset + j > tmp->ry)
				continue ;
			color = tmp->addr_t_img[4][(i * tmp->t_wh[4] / (int)sp_size)
				+ (j * tmp->t_ht[4] / (int)sp_size) * tmp->t_wh[4]];
			if (color != tmp->addr_t_img[4][0])
				my_mlx_pixel_put(tmp, t[k].x_offset + i,
						t[k].y_offset + j, color);
		}
	}
}
