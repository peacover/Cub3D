/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yer-raki <yer-raki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 03:49:21 by yer-raki          #+#    #+#             */
/*   Updated: 2021/01/17 12:05:36 by yer-raki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	errors_msg3(int c)
{
	if (c == 25)
		ft_putstr("more or less element(s) in S!!");
	else if (c == 26)
		ft_putstr("more or less element(s) in F!!");
	else if (c == 27)
		ft_putstr("more or less element(s) in C!!");
	else if (c == 28)
		ft_putstr("RGB should be numbers!!");
	else if (c == 29)
		ft_putstr("formule RGB invalid!!");
	else if (c == 30)
		ft_putstr("texture invalid!!");
}

void	errors_msg2(int c)
{
	if (c == 13)
		ft_putstr("image cant be save!!");
	else if (c == 14)
		ft_putstr("duplicated element!!");
	else if (c == 15)
		ft_putstr("resolution should be bigger than 0!!");
	else if (c == 16)
		ft_putstr("element or elements are missing!!");
	else if (c == 17)
		ft_putstr("path is missing!!");
	else if (c == 18)
		ft_putstr("more or less element(s) in NO!!");
	else if (c == 19)
		ft_putstr("resolution should be number positive!!");
	else if (c == 20)
		ft_putstr("more or less element(s) in R!!");
	else if (c == 21)
		ft_putstr("there's no player!!");
	else if (c == 22)
		ft_putstr("more or less element(s) in SO!!");
	else if (c == 23)
		ft_putstr("more or less element(s) in WE!!");
	else if (c == 24)
		ft_putstr("more or less element(s) in EA!!");
	errors_msg3(c);
}

void	errors_msg(int c)
{
	ft_putstr("Error\n");
	if (c == 1)
		ft_putstr("wrong name map!!");
	else if (c == 2)
		ft_putstr("wrong name of the third argument!!");
	else if (c == 3)
		ft_putstr("Invalid file!!");
	else if (c == 4)
		ft_putstr("element invalid in the file!!");
	else if (c == 5)
		ft_putstr("Map doesnt exist in the file!!");
	else if (c == 6)
		ft_putstr("map invalid!!");
	else if (c == 7)
		ft_putstr("More than one player in the map!!");
	else if (c == 9)
		ft_putstr("empty line in the map!!");
	else if (c == 10)
		ft_putstr("color should be between 0 and 255!!");
	else if (c == 11)
		ft_putstr("file doesn't exist!!");
	else if (c == 12)
		ft_putstr("allocation failed!!");
	errors_msg2(c);
	exit(0);
}

int		check_file(char *line)
{
	int i;

	i = 0;
	if ((line[i] == 'R' || line[i] == 'S' || line[i] == 'F' || line[i] == 'C')
			&& line[i + 1] == ' ')
		return (1);
	else if (line[i] == 'N' && line[i + 1] == 'O' && line[i + 2] == ' ')
		return (1);
	else if (line[i] == 'S' && line[i + 1] == 'O' && line[i + 2] == ' ')
		return (1);
	else if (line[i] == 'W' && line[i + 1] == 'E' && line[i + 2] == ' ')
		return (1);
	else if (line[i] == 'E' && line[i + 1] == 'A' && line[i + 2] == ' ')
		return (1);
	else if (line[i] == ' ' || line[i] == '1' || line[i] == '\n'
			|| line[i] == '\0')
		return (1);
	else
		errors_msg(4);
	return (0);
}

void	free_t2(char **w, int x)
{
	int i;

	i = 0;
	while (x > i)
	{
		free(w[i]);
		i++;
	}
	free(w);
}
