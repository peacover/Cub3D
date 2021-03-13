/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yer-raki <yer-raki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 09:36:49 by yer-raki          #+#    #+#             */
/*   Updated: 2021/02/08 09:28:48 by yer-raki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	u_map(char *line, t_data *tmp)
{
	int l;

	l = 0;
	if (char_map(line) == 1)
	{
		tmp->nb_row++;
		l = ft_strlen(line);
		if (l > tmp->nb_col)
			tmp->nb_col = l;
	}
}

int		check_line_map(t_data *tmp, char *line)
{
	int i;
	int l;

	i = 0;
	l = 0;
	if (line[i] == '\n')
		errors_msg(9);
	while (line[i] == ' ')
		i++;
	while (line[i])
	{
		if (line[i] == 'N' || line[i] == 'S' || line[i] == 'E'
		|| line[i] == 'W')
		{
			tmp->n_p = line[i];
			if (tmp->p == 1)
				errors_msg(7);
			tmp->p = 1;
		}
		i++;
	}
	l = ft_strlen(line) - 1;
	if (line[l] != '1' && line[l] != ' ')
		errors_msg(6);
	return (1);
}

void	check_map2(t_data *t, int i, int j)
{
	if (t->map[i][j] != '1' && t->map[i][j] != ' ' && t->map[i][j] != '0'
	&& t->map[i][j] != 'E' && t->map[i][j] != 'W' && t->map[i][j] != 'N' &&
	t->map[i][j] != 'S' && t->map[i][j] != '2')
		errors_msg(6);
	if (i == 0 || i == t->nb_row - 1)
	{
		if (t->map[i][j] != '1' && t->map[i][j] != ' ')
			errors_msg(6);
	}
	else if (t->map[i][j] == ' ' && ((t->map[i][j - 1] != ' '
	&& t->map[i][j - 1] != '1'
	&& t->map[i][j - 1] != '\0')
	|| (t->map[i][j + 1] != ' ' && t->map[i][j + 1] != '1'
	&& t->map[i][j + 1] != '\0')
	|| (t->map[i - 1][j] != ' ' && t->map[i - 1][j] != '1'
	&& t->map[i - 1][j] != '\0')
	|| (t->map[i + 1][j] != ' ' && t->map[i + 1][j] != '1'
	&& t->map[i + 1][j] != '\0')))
		errors_msg(6);
}

void	check_map(t_data *t)
{
	int i;
	int j;

	i = -1;
	while (t->nb_row > ++i)
	{
		j = 1;
		while (t->map[i][j])
		{
			check_map2(t, i, j);
			j++;
		}
	}
	if (t->p != 1)
		errors_msg(21);
}
