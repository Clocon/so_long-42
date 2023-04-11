/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_controls.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumorale <lumorale@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 11:44:03 by lumorale          #+#    #+#             */
/*   Updated: 2023/04/11 12:31:37 by lumorale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

static char	check_evol(t_game *game)
{
	if (game->map[game->y_player][game->x_player] != 'P')
		return (game->map[game->y_player][game->x_player]);
	if (game->moves <= 9)
		game->map[game->new_yp][game->new_xp] = 'K';
	else if (game->moves > 9 && game->moves <= 19)
		game->map[game->new_yp][game->new_xp] = 'T';
	else if (game->moves > 19)
		game->map[game->new_yp][game->new_xp] = 'F';
	return (game->map[game->new_yp][game->new_xp]);
}

static void	win_condition(t_game *game)
{
	if (game->c_count == 0)
	{
		game->map[game->new_yp][game->new_xp] = 'P';
		game->map[game->y_player][game->x_player] = '0';
		print_map(game);
		mlx_close_window(game->mlx);
		console_msg(WIN_OK, 0);
		exit(0);
	}
	else
		console_msg(WIN_KO, 0);
}

static void	get_action(t_game *game, char new_p, char old_p)
{
	game->moves++;
	if (game->map[game->new_yp][game->new_xp] == 'C')
		console_msg(EVOL, 0);
	game->map[game->new_yp][game->new_xp] = new_p;
	game->map[game->y_player][game->x_player] = old_p;
	print_map(game);
	print_moves(game);
	game->x_player = game->new_xp;
	game->y_player = game->new_yp;
}

static void	moves(t_game *game)
{
	if (game->map[game->new_yp][game->new_xp] == '1')
		return ;
	else if (game->map[game->new_yp][game->new_xp] == 'C')
	{
		game->c_count--;
		get_action(game, check_evol(game), '0');
	}
	else if (game->map[game->new_yp][game->new_xp] == '0')
		get_action(game, game->map[game->y_player][game->x_player], '0');
	else if (game->map[game->new_yp][game->new_xp] == 'E')
	{
		win_condition(game);
		return ;
	}
	else if (game->map[game->new_yp][game->new_xp] == 'R' ||
		game->map[game->new_yp][game->new_xp] == 'L')
		console_msg(LOSE, 1);
}

void	controls(mlx_key_data_t keydata, void *gv)
{
	t_game	*game;

	game = gv;
	game->new_xp = game->x_player;
	game->new_yp = game->y_player;
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_RELEASE)
		game->new_yp--;
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_RELEASE)
		game->new_xp--;
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_RELEASE)
		game->new_yp++;
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_RELEASE)
		game->new_xp++;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_RELEASE)
		exit(0);
	moves(game);
}
