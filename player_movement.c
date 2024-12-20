/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paprzyby <paprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 13:07:06 by paprzyby          #+#    #+#             */
/*   Updated: 2024/12/06 10:47:43 by paprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rotate_player(t_game *game, bool direction)
{
	t_player	*player;

	player = game->player;
	if (direction)
	{
		player->player_angle = player->player_angle + 0.045;
		if (player->player_angle > 2 * M_PI)
			player->player_angle = player->player_angle - (2 * M_PI);
	}
	else
	{
		player->player_angle = player->player_angle - 0.045;
		if (player->player_angle > 2 * M_PI)
			player->player_angle = player->player_angle + (2 * M_PI);
	}
	// data can be modified
}

void	new_player_position(t_game *game, int new_y, int new_x)
{
	int			map_grid_y;
	int			map_grid_x;
	t_player	*player;

	player = game->player;
	map_grid_y = roundf(player->pixel_pos_y + new_y) / 30;
	map_grid_x = roundf(player->pixel_pos_x + new_x) / 30;
	if (game->map[map_grid_y][map_grid_x] != '1')
	{
		player->pixel_pos_y = roundf(player->pixel_pos_y + new_y);
		player->pixel_pos_x = roundf(player->pixel_pos_x + new_x);
	}
}

void	player_movement(t_game *game, t_player *player)
{
	int	new_y;
	int	new_x;

	new_y = 0;
	new_x = 0;
	if (game->key_w)
	{
		new_y = sin(player->player_angle) * 4;
		new_x = cos(player->player_angle) * 4;
	}
	else if (game->key_s)
	{
		new_y = -sin(player->player_angle) * 4;
		new_x = -cos(player->player_angle) * 4;
	}
	if (game->key_a)
	{
		new_y = -cos(player->player_angle) * 4;
		new_x = sin(player->player_angle) * 4;
	}
	else if (game->key_d)
	{
		new_y = cos(player->player_angle) * 4;
		new_x = -sin(player->player_angle) * 4;
	}
	if (new_y || new_x)
		new_player_position(game, new_y, new_x);
	if (game->key_left)
		rotate_player(game, false);
	else if (game->key_right)
		rotate_player(game, true);
}
