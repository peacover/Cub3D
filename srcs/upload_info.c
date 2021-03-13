/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   upload_info.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yer-raki <yer-raki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 09:56:06 by yer-raki          #+#    #+#             */
/*   Updated: 2021/02/02 10:29:01 by yer-raki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	u_resolution(char *line, t_data *tmp)
{
	char	**w;
	int		i;

	i = 0;
	if (tmp->r == 1)
		errors_msg(14);
	tmp->r = 1;
	w = ft_split(line, ' ');
	if (ft_strlen2(w) != 3)
		errors_msg(20);
	if (ft_isdigit(w[1]) == 0 || ft_isdigit(w[2]) == 0)
		errors_msg(19);
	tmp->rx = (ft_atoi(w[1]) == -1 || ft_strlen3(w[1]) > 5)
	? WITH_MAX : ft_atoi(w[1]);
	tmp->ry = (ft_atoi(w[2]) == -1 || ft_strlen3(w[2]) > 5)
	? HEIGHT_MAX : ft_atoi(w[2]);
	u_resolution2(tmp);
	free_t2(w, 3);
}

void	u_resolution2(t_data *tmp)
{
	if (tmp->rx > WITH_MAX)
		tmp->rx = WITH_MAX;
	if (tmp->ry > HEIGHT_MAX)
		tmp->ry = HEIGHT_MAX;
	if (tmp->rx == 0 || tmp->ry == 0)
		errors_msg(15);
}

void	path_textures_no(char *line, t_data *tmp)
{
	char	**w;
	int		fd;
	int		i;

	i = 0;
	if (tmp->no == 1)
		errors_msg(14);
	tmp->no = 1;
	w = ft_split(line, ' ');
	if (ft_strlen2(w) != 2)
		errors_msg(18);
	tmp->s_no = malloc(sizeof(char) * (ft_strlen(w[1]) + 1));
	tmp->s_no = ft_strcpy(tmp->s_no, w[1]);
	fd = open(tmp->s_no, O_RDONLY);
	if (fd < 0)
		errors_msg(11);
	free_t2(w, 2);
}

void	path_textures_so(char *line, t_data *tmp)
{
	char	**w;
	int		fd;
	int		i;

	i = 0;
	if (tmp->so == 1)
		errors_msg(14);
	tmp->so = 1;
	w = ft_split(line, ' ');
	if (ft_strlen2(w) != 2)
		errors_msg(22);
	tmp->s_so = malloc(sizeof(char) * (ft_strlen(w[1]) + 1));
	tmp->s_so = ft_strcpy(tmp->s_so, w[1]);
	fd = open(tmp->s_so, O_RDONLY);
	if (fd < 0)
		errors_msg(11);
	free_t2(w, 2);
}

void	path_textures_we(char *line, t_data *tmp)
{
	char	**w;
	int		fd;
	int		i;

	i = 0;
	if (tmp->we == 1)
		errors_msg(14);
	tmp->we = 1;
	w = ft_split(line, ' ');
	if (ft_strlen2(w) != 2)
		errors_msg(23);
	tmp->s_we = malloc(sizeof(char) * (ft_strlen(w[1]) + 1));
	tmp->s_we = ft_strcpy(tmp->s_we, w[1]);
	fd = open(tmp->s_we, O_RDONLY);
	if (fd < 0)
		errors_msg(11);
	free_t2(w, 2);
}
