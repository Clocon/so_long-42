/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumorale <lumorale@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 12:38:37 by lumorale          #+#    #+#             */
/*   Updated: 2023/04/11 12:38:57 by lumorale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	print_moves(t_game *game)
{
	char	*str;

	str = ft_itoa(game->moves);
	print_map(game);
	mlx_delete_image(game->mlx, game->move_count);
	game->move_count = mlx_put_string(game->mlx, str, 15, 14);
	free(str);
}

static void	print_map_bonus(t_game *game, int y, int x, mlx_t *mlx)
{
	if (game->map[y][x] == 'F')
		mlx_image_to_window(mlx, game->hitmonchan, x * SPR, y * SPR);
	else if (game->map[y][x] == 'K')
		mlx_image_to_window(mlx, game->hitmonlee, x * SPR, y * SPR);
	else if (game->map[y][x] == 'T')
		mlx_image_to_window(mlx, game->hitmontop, x * SPR, y * SPR);
	else if (game->map[y][x] == 'L')
		mlx_image_to_window(mlx, game->enemy_l, x * SPR, y * SPR);
	else if (game->map[y][x] == 'R')
		mlx_image_to_window(mlx, game->enemy_r, x * SPR, y * SPR);
}

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
			print_map_bonus(game, y, x, mlx);
		}
	}
}
