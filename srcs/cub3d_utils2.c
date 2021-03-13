/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yer-raki <yer-raki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 03:37:24 by yer-raki          #+#    #+#             */
/*   Updated: 2021/01/14 11:44:27 by yer-raki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		name_map(char *str)
{
	char *s;

	s = ft_strrchr(str, '.');
	if (check_point(str) == 1 && ft_strcmp(s, ".cub") == 0)
		return (1);
	else
		errors_msg(1);
	return (0);
}

int		name_save(char *str)
{
	if (ft_strcmp(str, "--save") == 0)
		return (1);
	else
		errors_msg(2);
	return (0);
}

int		char_map(char *line)
{
	int i;

	i = 0;
	if (line[i] == ' ' || line[i] == '1')
		return (1);
	else
		errors_msg(4);
	return (0);
}

char	ray_facing_ud(t_data *tmp)
{
	if (tmp->p_rotationangle > 0 && tmp->p_rotationangle < M_PI)
		return ('d');
	else
		return ('u');
}

char	ray_facing_rl(t_data *tmp)
{
	if (tmp->p_rotationangle < 0.5 * M_PI || tmp->p_rotationangle > 1.5 * M_PI)
		return ('r');
	else
		return ('l');
}
