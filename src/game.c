/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumorale <lumorale@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 17:03:21 by lumorale          #+#    #+#             */
/*   Updated: 2023/04/10 20:41:05 by lumorale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	print_map(t_game *game)
{
	int		y;
	int		x;
	mlx_t	*mlx;

	mlx = game->mlx;
	y = -1;
	while (++y < game->total_y)
	{
		x = -1;
		while (++x < game->total_x)
		{
			if (game->map[y][x] == '0')
				mlx_image_to_window(mlx, game->floor_img, x * SPR, y * SPR);
			else if (game->map[y][x] == '1')
				mlx_image_to_window(mlx, game->limit_img, x * SPR, y * SPR);
			else if (game->map[y][x] == 'P')
				mlx_image_to_window(mlx, game->player_img, x * SPR, y * SPR);
			else if (game->map[y][x] == 'C')
				mlx_image_to_window(mlx, game->collect_img, x * SPR, y * SPR);
			else if (game->map[y][x] == 'E')
				mlx_image_to_window(mlx, game->gate_img, x * SPR, y * SPR);
		}
	}
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
}

/*
sprite_w = tamaño ancho
sprite_h = tamaño alto
map_w = ancho mapa
map_h = alto mapa
map_nr = nº row?
map_nc = nº col?
*/

void	game_start(t_game *game)
{
	window_generator(game);
	print_map(game);
	mlx_key_hook(game->mlx, &controls, game);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
}
