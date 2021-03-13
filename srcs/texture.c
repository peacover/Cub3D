/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yer-raki <yer-raki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 10:03:02 by yer-raki          #+#    #+#             */
/*   Updated: 2021/01/17 12:22:15 by yer-raki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	textures(t_data *t)
{
	int k;

	t->t_img[0] = mlx_xpm_file_to_image(t->mlx_ptr,
			t->s_no, &t->t_wh[0], &t->t_ht[0]);
	t->t_img[1] = mlx_xpm_file_to_image(t->mlx_ptr,
			t->s_so, &t->t_wh[1], &t->t_ht[1]);
	t->t_img[2] = mlx_xpm_file_to_image(t->mlx_ptr,
			t->s_we, &t->t_wh[2], &t->t_ht[2]);
	t->t_img[3] = mlx_xpm_file_to_image(t->mlx_ptr,
			t->s_ea, &t->t_wh[3], &t->t_ht[3]);
	t->t_img[4] = mlx_xpm_file_to_image(t->mlx_ptr,
			t->s_s, &t->t_wh[4], &t->t_ht[4]);
	if (t->t_img[0] == 0 || t->t_img[1] == 0 || t->t_img[2] == 0
			|| t->t_img[3] == 0 || t->t_img[4] == 0)
		errors_msg(30);
	t->addr_t_img[0] = (int *)mlx_get_data_addr(t->t_img[0], &k, &k, &k);
	t->addr_t_img[1] = (int *)mlx_get_data_addr(t->t_img[1], &k, &k, &k);
	t->addr_t_img[2] = (int *)mlx_get_data_addr(t->t_img[2], &k, &k, &k);
	t->addr_t_img[3] = (int *)mlx_get_data_addr(t->t_img[3], &k, &k, &k);
	t->addr_t_img[4] = (int *)mlx_get_data_addr(t->t_img[4], &k, &k, &k);
	free(t->s_ea);
	free(t->s_no);
	free(t->s_so);
	free(t->s_we);
	free(t->s_s);
}

void	draw_walls(t_data *tmp, int i, int j, int index)
{
	double	y;
	int		color;
	double	ratio;

	y = 0;
	ratio = tmp->t_ht[index] / tmp->wallstripheight;
	while (y < j)
	{
		my_mlx_pixel_put(tmp, i, y,
		rgb_to_int(tmp->c_rgb_r, tmp->c_rgb_g, tmp->c_rgb_b));
		y++;
	}
	while (y < j + tmp->wallstripheight && y < tmp->ry)
	{
		color = tmp->addr_t_img[index][(int)calcul_offset(tmp, index)
			+ (int)((y - j) * ratio) * tmp->t_wh[index]];
		my_mlx_pixel_put(tmp, i, y, color);
		y++;
	}
	while (y < tmp->ry)
	{
		my_mlx_pixel_put(tmp, i, y,
		rgb_to_int(tmp->f_rgb_r, tmp->f_rgb_g, tmp->f_rgb_b));
		y++;
	}
}

int		get_texture_index(t_data *tmp)
{
	int index;

	if (tmp->hit_type == 'h')
	{
		if (sin(tmp->p_rotationangle) >= 0)
			index = 0;
		else
			index = 1;
	}
	if (tmp->hit_type == 'v')
	{
		if (cos(tmp->p_rotationangle) >= 0)
			index = 2;
		else
			index = 3;
	}
	return (index);
}
