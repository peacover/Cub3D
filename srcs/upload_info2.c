/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   upload_info2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yer-raki <yer-raki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 09:39:53 by yer-raki          #+#    #+#             */
/*   Updated: 2021/01/17 15:12:50 by yer-raki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	path_textures_s(char *line, t_data *tmp)
{
	char	**w;
	int		fd;
	int		i;

	i = 0;
	if (tmp->s == 1)
		errors_msg(14);
	tmp->s = 1;
	w = ft_split(line, ' ');
	if (ft_strlen2(w) != 2)
		errors_msg(25);
	tmp->s_s = malloc(sizeof(char) * (ft_strlen(w[1]) + 1));
	tmp->s_s = ft_strcpy(tmp->s_s, w[1]);
	fd = open(tmp->s_s, O_RDONLY);
	if (fd < 0)
		errors_msg(11);
	free_t2(w, 2);
}

void	u_f2(char *line, t_data *tmp, char **w)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while (line[i])
	{
		if (line[i] == ',')
			j++;
		i++;
	}
	i = ft_strlen2(w);
	if (j != 2 || line[(int)(ft_strlen(line) - 1)] == ',')
		errors_msg(29);
	free_t2(w, i);
	if (tmp->f_rgb_r >= 256 || tmp->f_rgb_g >= 256 || tmp->f_rgb_b >= 256
	|| tmp->f_rgb_r < 0 || tmp->f_rgb_g < 0 || tmp->f_rgb_b < 0)
		errors_msg(10);
}

void	u_f(char *line, t_data *tmp, int i)
{
	int		j;
	char	**w;
	char	**w1;

	j = -1;
	if (tmp->f == 1)
		errors_msg(14);
	tmp->f = 1;
	w = ft_split(line, ' ');
	w1 = ft_split(w[1], ',');
	if (ft_strlen2(w) != 2 || ft_strlen2(w1) != 3)
		errors_msg(26);
	while (w[++i])
	{
		while (w1[++j])
		{
			if (ft_isdigit(w1[j]) == 0)
				errors_msg(28);
			tmp->f_rgb_r = ft_atoi(w1[0]);
			tmp->f_rgb_g = ft_atoi(w1[1]);
			tmp->f_rgb_b = ft_atoi(w1[2]);
		}
	}
	u_f2(line, tmp, w);
	free_t2(w1, j);
}

void	u_c2(char *line, t_data *tmp, char **w)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while (line[i])
	{
		if (line[i] == ',')
			j++;
		i++;
	}
	i = ft_strlen2(w);
	if (j != 2 || line[(int)(ft_strlen(line) - 1)] == ',')
		errors_msg(29);
	free_t2(w, i);
	if (tmp->c_rgb_r >= 256 || tmp->c_rgb_g >= 256 || tmp->c_rgb_b >= 256
			|| tmp->c_rgb_r < 0 || tmp->c_rgb_g < 0 || tmp->c_rgb_b < 0)
		errors_msg(10);
}

void	u_c(char *line, t_data *tmp, int i)
{
	int		j;
	char	**w;
	char	**w1;

	j = -1;
	if (tmp->c == 1)
		errors_msg(14);
	tmp->c = 1;
	w = ft_split(line, ' ');
	w1 = ft_split(w[1], ',');
	if (ft_strlen2(w) != 2 || ft_strlen2(w1) != 3)
		errors_msg(27);
	while (w[++i])
	{
		while (w1[++j])
		{
			if (ft_isdigit(w1[j]) == 0)
				errors_msg(28);
			tmp->c_rgb_r = ft_atoi(w1[0]);
			tmp->c_rgb_g = ft_atoi(w1[1]);
			tmp->c_rgb_b = ft_atoi(w1[2]);
		}
	}
	u_c2(line, tmp, w);
	free_t2(w1, j);
}
