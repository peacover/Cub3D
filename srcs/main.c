/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yer-raki <yer-raki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 09:31:02 by yer-raki          #+#    #+#             */
/*   Updated: 2021/01/31 16:47:44 by yer-raki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_data	tmp;

	if ((argc == 2 || (argc == 3 && name_save(argv[2])))
			&& name_map(argv[1]) == 1)
	{
		if (argc == 3)
			g_arg_save = 1;
		init(&tmp);
		r_file(&tmp, argv[1]);
	}
	else
		ft_putstr("Error\ncheck arguments!!");
	return (0);
}
