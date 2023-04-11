/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumorale <lumorale@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 17:03:21 by lumorale          #+#    #+#             */
/*   Updated: 2023/04/11 12:38:58 by lumorale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

static void	bonus_textures(t_game *game)
{
	t_textures_b	bonus;

	bonus.hitmonlee = mlx_load_png("img/player_lee.png");
	bonus.hitmonchan = mlx_load_png("img/player_chan.png");
	bonus.hitmontop = mlx_load_png("img/player_top.png");
	bonus.enemy_l = mlx_load_png("img/enemy_l.png");
	bonus.enemy_r = mlx_load_png("img/enemy_r.png");
	game->hitmonlee = mlx_texture_to_image(game->mlx, bonus.hitmonlee);
	game->hitmonchan = mlx_texture_to_image(game->mlx, bonus.hitmonchan);
	game->hitmontop = mlx_texture_to_image(game->mlx, bonus.hitmontop);
	game->enemy_l = mlx_texture_to_image(game->mlx, bonus.enemy_l);
	game->enemy_r = mlx_texture_to_image(game->mlx, bonus.enemy_r);
	mlx_delete_texture(bonus.hitmonlee);
	mlx_delete_texture(bonus.hitmonchan);
	mlx_delete_texture(bonus.hitmontop);
	mlx_delete_texture(bonus.enemy_l);
	mlx_delete_texture(bonus.enemy_r);
}

static void	window_generator(t_game *game)
{
	t_textures	img;

	game->mlx = mlx_init(game->map_width, game->map_height, "so_long", false);
	img.limits = mlx_load_png("img/limit.png");
	img.floor = mlx_load_png("img/floor.png");
	img.player = mlx_load_png("img/player.png");
	img.collect = mlx_load_png("img/collect.png");
	img.gate = mlx_load_png("img/gate.png");
	game->limit_img = mlx_texture_to_image(game->mlx, img.limits);
	game->floor_img = mlx_texture_to_image(game->mlx, img.floor);
	game->player_img = mlx_texture_to_image(game->mlx, img.player);
	game->collect_img = mlx_texture_to_image(game->mlx, img.collect);
	game->gate_img = mlx_texture_to_image(game->mlx, img.gate);
	mlx_delete_texture(img.limits);
	mlx_delete_texture(img.floor);
	mlx_delete_texture(img.player);
	mlx_delete_texture(img.collect);
	mlx_delete_texture(img.gate);
	bonus_textures(game);
}

void	game_start(t_game *game)
{
	window_generator(game);
	game->counter = mlx_get_time();
	print_map(game);
	print_moves(game);
	mlx_key_hook(game->mlx, &controls, game);
	if (game->c_enemy == 1)
		mlx_loop_hook(game->mlx, &enemy_moves, game);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
}
