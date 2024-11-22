/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paprzyby <paprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 14:28:49 by paprzyby          #+#    #+#             */
/*   Updated: 2024/11/22 16:05:24 by paprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	mlx_t	*mlx;

	mlx = NULL;
	if (ac == 2)
	{
		check_map_extension(av[1]);
		return (0);
	}
	ft_putstr_fd("Error\nInvalid number of arguments\n", 2);
	return (1);
}
