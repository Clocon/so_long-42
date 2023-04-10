/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumorale <lumorale@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 16:58:31 by lumorale          #+#    #+#             */
/*   Updated: 2023/04/10 20:36:36 by lumorale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	print_moves(t_game *game)
{
	char	*str;

	str = ft_itoa(game->moves);
	mlx_delete_image(game->mlx, game->move_count);
	game->move_count = mlx_put_string(game->mlx, str, 15, 14);
	free(str);
}

static void	check_lose(t_game *game)
{
	if (game->map[game->y_enemy][game->x_enemy - 1] == 'P' ||
		game->map[game->y_enemy][game->x_enemy - 1] == 'K' ||
		game->map[game->y_enemy][game->x_enemy - 1] == 'T' ||
		game->map[game->y_enemy][game->x_enemy - 1] == 'F')
		console_msg(LOSE, 1);
}

static void	enemy_left(t_game *game)
{
	if (game->map[game->y_enemy][game->x_enemy - 1] != '0')
	{
		check_lose(game);
		game->map[game->y_enemy][game->x_enemy] = 'R';
		print_map(game);
		print_moves(game);
	}
	else
	{
		game->map[game->y_enemy][game->x_enemy] = '0';
		game->x_enemy--;
		game->map[game->y_enemy][game->x_enemy] = 'L';
		print_map(game);
		print_moves(game);
	}
}

static void	enemy_right(t_game *game)
{
	if (game->map[game->y_enemy][game->x_enemy + 1] != '0')
	{
		check_lose(game);
		game->map[game->y_enemy][game->x_enemy] = 'L';
		print_map(game);
		print_moves(game);
	}
	else
	{
		game->map[game->y_enemy][game->x_enemy] = '0';
		game->x_enemy++;
		game->map[game->y_enemy][game->x_enemy] = 'R';
		print_map(game);
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
