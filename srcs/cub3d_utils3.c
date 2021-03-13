/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_utils3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yer-raki <yer-raki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 10:29:07 by yer-raki          #+#    #+#             */
/*   Updated: 2021/01/14 14:22:45 by yer-raki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		rgb_to_int(int r, int g, int b)
{
	int t;

	t = 0;
	t = r * 65536 + g * 256 + b;
	return (t);
}

char	*ft_strcpy(char *dest, char *src)
{
	int i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*d;
	char	*s;
	size_t	i;

	i = 0;
	d = (char *)dst;
	s = (char *)src;
	if (d == NULL && s == NULL)
		return (NULL);
	while (n > i)
	{
		d[i] = s[i];
		i++;
	}
	return (d);
}

int		ft_strlen2(char **w)
{
	int i;

	i = 0;
	while (w[i])
		i++;
	return (i);
}

void	init(t_data *tmp)
{
	tmp->p_rotationspeed = 5 * (M_PI / 180);
	tmp->p_movespeed = 10;
}
