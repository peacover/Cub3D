/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yer-raki <yer-raki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 16:54:53 by yer-raki          #+#    #+#             */
/*   Updated: 2021/01/14 10:48:31 by yer-raki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int				nb_w(char const *s, char c)
{
	int i;
	int x;
	int l;

	i = 0;
	x = 0;
	l = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			x = 0;
		else if (x == 0)
		{
			x = 1;
			l++;
		}
		i++;
	}
	return (l);
}

unsigned long	nb_c(char const *s, char c, int i)
{
	int l;

	l = 0;
	while (s[i] != c && s[i] != '\0')
	{
		l++;
		i++;
	}
	return (l);
}

char			**ft_split(char const *s, char c)
{
	char	**w;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	if (!(w = (char**)malloc(sizeof(char *) * (nb_w(s, c) + 1))))
		return (NULL);
	while (s[i] != '\0' && nb_w(s, c) > j)
	{
		k = 0;
		while (s[i] == c)
			i++;
		w[j] = (char *)malloc(sizeof(char) * (nb_c(s, c, i) + 1));
		while (s[i] != c && s[i])
			w[j][k++] = s[i++];
		w[j][k] = '\0';
		j++;
	}
	w[j] = 0;
	return (w);
}
