/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yer-raki <yer-raki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 14:32:01 by yer-raki          #+#    #+#             */
/*   Updated: 2021/01/14 14:33:44 by yer-raki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	copy_map3(t_data *tmp, int i, int j, char *line)
{
	if (check_line_map(tmp, line) == 1)
	{
		while (line[j])
		{
			tmp->map[i][j] = line[j];
			j++;
		}
		while (tmp->nb_col > j)
		{
			tmp->map[i][j] = ' ';
			j++;
		}
		tmp->map[i][j] = '\0';
	}
}

void	copy_map2(t_data *tmp, int fd, int num_line)
{
	char	*line;
	int		ret;
	int		i;
	int		j;

	ret = 1;
	i = 0;
	j = 0;
	while (ret > 0)
	{
		ret = get_next_line(fd, &line);
		if (++num_line >= tmp->num_start_map)
		{
			j = 0;
			copy_map3(tmp, i, j, line);
			i++;
		}
		free(line);
	}
}

void	copy_map(t_data *tmp, char *file_name)
{
	int		fd;
	int		i;
	int		num_line;
	int		j;

	i = -1;
	num_line = -1;
	fd = open(file_name, O_RDONLY);
	if (!(tmp->map = malloc(sizeof(char*) * tmp->nb_row + 1)))
		errors_msg(12);
	while (++i < tmp->nb_row)
	{
		if (!(tmp->map[i] = malloc(sizeof(char) * tmp->nb_col + 1)))
			errors_msg(12);
	}
	i = 0;
	j = 0;
	copy_map2(tmp, fd, num_line);
	close(fd);
	check_map(tmp);
	count_sprites(tmp);
	init_map(tmp);
	free_t2(tmp->map, tmp->nb_row);
}
