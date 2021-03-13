/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_utils4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yer-raki <yer-raki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 09:51:25 by yer-raki          #+#    #+#             */
/*   Updated: 2021/01/25 16:15:08 by yer-raki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	count_sprites(t_data *tmp)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (y < tmp->nb_row)
	{
		x = 0;
		while (tmp->map[y][x])
		{
			if (tmp->map[y][x] == '2')
				tmp->nb_sp++;
			x++;
		}
		y++;
	}
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x < data->rx && y >= 0 && y < data->ry)
	{
		dst = data->addr + (y * data->line_l + x *
				(data->bpp / 8));
		*(unsigned int*)dst = color;
	}
}

float	calcul_offset(t_data *tmp, int i)
{
	if (tmp->hit_type == 'h')
		return (fmod(tmp->h_v, TILE_SIZE) * tmp->t_ht[i] / TILE_SIZE);
	return (fmod(tmp->v_w, TILE_SIZE));
}

void	init_straight(t_data *tmp)
{
	double	i;
	double	x;
	double	y;

	x = 0;
	y = 0;
	i = 0;
	if (tmp->n_p == 'S')
		tmp->p_rotationangle = 90 * (M_PI / 180);
	else if (tmp->n_p == 'N')
		tmp->p_rotationangle = 270 * (M_PI / 180);
	else if (tmp->n_p == 'W')
		tmp->p_rotationangle = 180 * (M_PI / 180);
	else if (tmp->n_p == 'E')
		tmp->p_rotationangle = 0;
	draw_rays(tmp);
}

double	fix_angle(double angle)
{
	angle = fmod(angle, (2 * M_PI));
	if (angle < 0)
		angle = angle + (2 * M_PI);
	return (angle);
}
