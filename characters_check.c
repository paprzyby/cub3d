/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   characters_check.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaluszk <dpaluszk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 17:48:16 by dpaluszk          #+#    #+#             */
/*   Updated: 2025/01/31 18:39:50 by dpaluszk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	increment_counters(t_game *game)
{
	game->player_x = game->x;
	game->player_y = game->y;
	game->player_counter++;
	game->x++;
}

void	character_check_logic(t_game *game)
{
	if (game->map[game->y][game->x] == '0'
		|| game->map[game->y][game->x] == '1')
		game->x++;
	else if (game->map[game->y][game->x] == 'N')
		increment_counters(game);
	else if (game->map[game->y][game->x] == 'S')
		increment_counters(game);
	else if (game->map[game->y][game->x] == 'E')
		increment_counters(game);
	else if (game->map[game->y][game->x] == 'W')
		increment_counters(game);
	else if (game->map[game->y][game->x] == ' '
		|| game->map[game->y][game->x] == '\t')
		game->x++;
	else if (game->map[game->y][game->x])
	{
		ft_putstr_fd("Error\n\"", 1);
		ft_putchar_fd(game->map[game->y][game->x], 1);
		ft_putstr_fd("\"", 1);
		ft_putstr_fd(" is an invalid character\n", 1);
		exit(1);
	}
}

void	characters_check(t_game *game)
{
	while (game->map[game->y])
	{
		game->x = 0;
		while (game->map[game->y][game->x])
			character_check_logic(game);
		game->y++;
	}
	if (game->player_counter != 1)
	{
		ft_putstr_fd("Error\nThere must be one player in the game\n", 1);
		exit(1);
	}
}
