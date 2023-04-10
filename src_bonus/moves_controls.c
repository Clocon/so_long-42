/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_controls.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumorale <lumorale@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 11:44:03 by lumorale          #+#    #+#             */
/*   Updated: 2023/04/10 12:31:46 by lumorale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	win_condition(t_game *game)
{
	if (game->c_count == 0)
	{
		game->map[game->new_yp][game->new_xp] = 'P';
		game->map[game->y_player][game->x_player] = '0';
		print_map(game);
		mlx_close_window(game->mlx);
		console_msg(WIN_OK);
		exit(0);
	}
	else
		console_msg(WIN_KO);
}

static void	get_action(t_game *game, char new_p, char old_p)
{
	char	*str;

	game->map[game->new_yp][game->new_xp] = new_p;
	game->map[game->y_player][game->x_player] = old_p;
	game->moves++;
	str = ft_itoa(game->moves);
	str = ft_strjoin_free(str, N_MOVES);
	console_msg(str);
	free(str);
	print_map(game);
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
		get_action(game, 'P', '0');
	}
	else if (game->map[game->new_yp][game->new_xp] == '0')
		get_action(game, 'P', '0');
	else if (game->map[game->new_yp][game->new_xp] == 'E')
	{
		win_condition(game);
		return ;
	}
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
