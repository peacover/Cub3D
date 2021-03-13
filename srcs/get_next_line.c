/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yer-raki <yer-raki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 11:13:54 by yer-raki          #+#    #+#             */
/*   Updated: 2021/01/14 11:30:41 by yer-raki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		read_file(char **str, int fd)
{
	int		ret;
	char	*s;
	char	buf[BUFFER_SIZE + 1];

	if ((ret = read(fd, buf, BUFFER_SIZE)) == -1)
		return (-1);
	buf[ret] = '\0';
	s = *str;
	*str = ft_strjoin(*str, buf);
	if (*s != 0)
		free(s);
	return (ret);
}

int		get_line(char **str, char **line, char *s)
{
	int		i;
	char	*join;

	i = 0;
	if (*s == '\n')
		i = 1;
	*s = 0;
	*line = ft_strjoin("", *str);
	if (i == 0 && ft_strlen(*str) != 0)
		return (0);
	join = *str;
	*str = ft_strjoin(s + 1, "");
	free(join);
	return (i);
}

int		get_next_line(int const fd, char **line)
{
	int			ret;
	char		*s;
	static char	*str;
	int			i;

	i = 0;
	if (str == 0)
		str = "";
	if (!line || BUFFER_SIZE < 1)
		return (-1);
	ret = BUFFER_SIZE;
	while (line)
	{
		s = str;
		while (*s || ret < BUFFER_SIZE)
		{
			if (*s == '\n' || *s == 0 || *s == -1)
				return (get_line(&str, line, s));
			s++;
		}
		ret = read_file(&str, fd);
		if (ret == -1)
			return (-1);
	}
	return (0);
}
