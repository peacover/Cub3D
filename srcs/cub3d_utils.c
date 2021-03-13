/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yer-raki <yer-raki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 03:26:12 by yer-raki          #+#    #+#             */
/*   Updated: 2021/01/31 16:42:34 by yer-raki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*ft_strrchr(const char *s, int c)
{
	int		t;
	char	*dst;

	t = 0;
	dst = (char*)s;
	t = ft_strlen(dst);
	while (t - 1 >= 0)
	{
		if (s[t] == (char)c)
			return ((char *)dst + t);
		t--;
	}
	return (0);
}

int		ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
	{
		i++;
	}
	return (s1[i] - s2[i]);
}

int		check_point(char *str)
{
	int i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i])
	{
		if (str[i] == '.')
			return (1);
		i++;
	}
	return (0);
}

int		ft_atoi(const char *str)
{
	long	integer;
	int		i;
	int		sign;

	integer = 0;
	i = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		integer = integer * 10 + str[i] - '0';
		if (integer > 4294967296 && sign == 1)
			return (-1);
		if (integer > 4294967296 && sign == -1)
			return (0);
		i++;
	}
	return (integer * sign);
}

int		ft_isdigit(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] >= 48 && s[i] <= 57)
			i++;
		else
			return (0);
	}
	return (1);
}
