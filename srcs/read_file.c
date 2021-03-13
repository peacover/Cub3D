/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yer-raki <yer-raki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 09:33:06 by yer-raki          #+#    #+#             */
/*   Updated: 2021/01/14 14:35:12 by yer-raki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	u_menu(char *line, t_data *tmp)
{
	if (check_file(line) == 1)
	{
		if (line[0] == 'R')
			u_resolution(line, tmp);
		if (line[0] == 'N' && line[1] == 'O')
			path_textures_no(line, tmp);
		if (line[0] == 'S' && line[1] == 'O')
			path_textures_so(line, tmp);
		if (line[0] == 'W' && line[1] == 'E')
			path_textures_we(line, tmp);
		if (line[0] == 'E' && line[1] == 'A')
			path_textures_ea(line, tmp);
		if (line[0] == 'C')
			u_c(line, tmp, 0);
		if (line[0] == 'F')
			u_f(line, tmp, 0);
		if (line[0] == 'S' && line[1] == ' ')
			path_textures_s(line, tmp);
		if (line[0] == ' ' || line[0] == '1')
			u_map(line, tmp);
		else
			tmp->num_start_map++;
	}
}

void	r_file(t_data *tmp, char *file_name)
{
	int		fd;
	char	*line;
	int		ret;

	ret = 1;
	if ((fd = open(file_name, O_RDONLY)) == -1)
		errors_msg(3);
	while (ret > 0)
	{
		ret = get_next_line(fd, &line);
		u_menu(line, tmp);
		free(line);
	}
	close(fd);
	if (tmp->nb_col == 0 || tmp->nb_row == 0)
		errors_msg(5);
	if (tmp->r != 1 || tmp->no != 1 || tmp->so != 1 || tmp->we != 1
		|| tmp->ea != 1 || tmp->s != 1 || tmp->f != 1 || tmp->c != 1)
		errors_msg(16);
	copy_map(tmp, file_name);
	free(line);
}

void	path_textures_ea(char *line, t_data *tmp)
{
	char	**w;
	int		fd;
	int		i;

	i = 0;
	if (tmp->ea == 1)
		errors_msg(14);
	tmp->ea = 1;
	w = ft_split(line, ' ');
	if (ft_strlen2(w) != 2)
		errors_msg(24);
	tmp->s_ea = malloc(sizeof(char) * (ft_strlen(w[1]) + 1));
	tmp->s_ea = ft_strcpy(tmp->s_ea, w[1]);
	fd = open(tmp->s_ea, O_RDONLY);
	if (fd < 0)
		errors_msg(11);
	free_t2(w, 2);
}
