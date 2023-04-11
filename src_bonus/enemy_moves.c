/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumorale <lumorale@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 16:58:31 by lumorale          #+#    #+#             */
/*   Updated: 2023/04/11 13:07:31 by lumorale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

int	free_way(t_game *game, int y)
{
	int	i;

	i = 0;
	if (y > 0 && y < game->total_y)
	{
		while (++i < game-> total_x)
		{
			if (game->map[y][i] == '0' || game->map[y][i] == 'C')
				if (game->map[y][i + 1] == '0' || game->map[y][i + 1] == 'C')
					return (1);
		}
	}
	return (0);
}

static void	check_lose(t_game *game)
{
	if (game->map[game->y_enemy][game->x_enemy - 1] == 'P' ||
		game->map[game->y_enemy][game->x_enemy - 1] == 'K' ||
		game->map[game->y_enemy][game->x_enemy - 1] == 'T' ||
		game->map[game->y_enemy][game->x_enemy - 1] == 'F')
		console_msg(LOSE, 1);
	else if (game->map[game->y_enemy][game->x_enemy + 1] == 'P' ||
		game->map[game->y_enemy][game->x_enemy + 1] == 'K' ||
		game->map[game->y_enemy][game->x_enemy + 1] == 'T' ||
		game->map[game->y_enemy][game->x_enemy + 1] == 'F')
		console_msg(LOSE, 1);
}

static void	enemy_left(t_game *game)
{
	if (game->map[game->y_enemy][game->x_enemy - 1] != '0')
	{
		check_lose(game);
		game->map[game->y_enemy][game->x_enemy] = 'R';
		print_moves(game);
	}
	else
	{
		game->map[game->y_enemy][game->x_enemy] = '0';
		game->x_enemy--;
		game->map[game->y_enemy][game->x_enemy] = 'L';
		print_moves(game);
	}
}

static void	enemy_right(t_game *game)
{
	if (game->map[game->y_enemy][game->x_enemy + 1] != '0')
	{
		check_lose(game);
		game->map[game->y_enemy][game->x_enemy] = 'L';
		print_moves(game);
	}
	else
	{
		game->map[game->y_enemy][game->x_enemy] = '0';
		game->x_enemy++;
		game->map[game->y_enemy][game->x_enemy] = 'R';
		print_moves(game);
	}
}

void	enemy_moves(void *vg)
{
	t_game	*game;

	game = vg;
	game->counter += game->mlx->delta_time;
	if (game->counter > 0.5)
	{
		if (game->map[game->y_enemy][game->x_enemy] == 'L')
			enemy_left(game);
		else if (game->map[game->y_enemy][game->x_enemy] == 'R')
			enemy_right(game);
		game->counter = 0;
	}
}
