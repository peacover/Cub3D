/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yer-raki <yer-raki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 11:11:18 by yer-raki          #+#    #+#             */
/*   Updated: 2021/01/14 10:49:45 by yer-raki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t t;

	t = 0;
	if (!str)
		return (0);
	while (str[t])
		t++;
	return (t);
}

void	ft_putstr(char *s)
{
	int i;

	i = 0;
	if (!s)
		return ;
	while (s[i] != '\0')
	{
		write(1, &s[i], 1);
		i++;
	}
}

char	*ft_strdup(const char *str1)
{
	char	*d;
	size_t	x;
	size_t	len;

	x = 0;
	len = ft_strlen(str1);
	d = (char *)malloc(sizeof(char) * (len + 1));
	while (str1[x])
	{
		d[x] = str1[x];
		x++;
	}
	d[x] = '\0';
	return (d);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	y;
	char	*d;
	size_t	ls;

	ls = ft_strlen(s);
	d = (char *)malloc(sizeof(char) * (ls + 1));
	if (!d || !s)
		return (NULL);
	if ((size_t)len > ls)
		return (ft_strdup(""));
	y = 0;
	while (len > y && s[y])
	{
		d[y] = s[start + y];
		y++;
	}
	d[y] = '\0';
	return (d);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	ls1;
	size_t	ls2;
	char	*dst;

	ls1 = ft_strlen(s1);
	ls2 = ft_strlen(s2);
	dst = (char *)malloc(sizeof(char) * (ls1 + ls2 + 1));
	if (!dst)
		return (NULL);
	i = 0;
	while (*s1)
		dst[i++] = *s1++;
	while (*s2)
		dst[i++] = *s2++;
	dst[i] = '\0';
	return (dst);
}
