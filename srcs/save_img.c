/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yer-raki <yer-raki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 09:15:44 by yer-raki          #+#    #+#             */
/*   Updated: 2021/01/25 17:27:26 by yer-raki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	header_file_img(t_data *tmp, int fd)
{
	int	size_file;
	int	img_offset;
	int	size_header;
	int	size_img;
	int	plane;

	img_offset = 54;
	size_file = img_offset + tmp->rx * tmp->ry * 4;
	write(fd, "BM", 2);
	write(fd, &size_file, 4);
	write(fd, "\0\0\0\0", 4);
	write(fd, &img_offset, 4);
	size_header = 40;
	size_img = tmp->rx * tmp->ry * 4;
	plane = 1;
	write(fd, &size_header, 4);
	write(fd, &tmp->rx, 4);
	write(fd, &tmp->ry, 4);
	write(fd, &plane, 2);
	write(fd, &tmp->bpp, 2);
	write(fd, "\0\0\0\0", 4);
	write(fd, &size_img, 4);
	write(fd, "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0", 16);
}

void	save_img(t_data *tmp)
{
	int	fd;
	int	x;
	int	y;

	if ((fd = open("./image.bmp", O_WRONLY |
					O_CREAT | O_TRUNC, 0666)) == -1)
		errors_msg(13);
	header_file_img(tmp, fd);
	y = tmp->ry - 1;
	while (y >= 0)
	{
		x = 0;
		while (x < tmp->rx)
		{
			write(fd, &tmp->addr[y * tmp->line_l + x * tmp->bpp / 8], 1);
			write(fd, &tmp->addr[y * tmp->line_l + x * tmp->bpp / 8 + 1], 1);
			write(fd, &tmp->addr[y * tmp->line_l + x * tmp->bpp / 8 + 2], 1);
			write(fd, "\0", 1);
			x++;
		}
		y--;
	}
	close(fd);
	exit(0);
}
