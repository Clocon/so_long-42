/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumorale <lumorale@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 13:25:52 by lumorale          #+#    #+#             */
/*   Updated: 2023/04/11 13:18:14 by lumorale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_args(char **argv)
{
	if (ft_strncmp(argv[1], "map/", 4) != 0)
		error(INVALID_PATH);
	if (ft_strncmp(&argv[1][(ft_strlen(argv[1]) - 4)], ".ber", 4) != 0)
		error(INVALID_EXT);
}

static void	is_played(char **to_check)
{
	int	i;
	int	j;

	i = -1;
	while (to_check[++i])
	{
		j = -1;
		while (to_check[i][++j])
		{
			if (to_check[i][j] != '1' && to_check[i][j] != '0')
				error(IMPOSIBLE_WIN);
		}
	}
}

static void	flood_fill(t_game *game, int py, int px)
{
	if (game->to_check[py][px] == 'E')
	{
		game->to_check[py][px] = '1';
		return ;
	}
	game->to_check[py][px] = '1';
	if (game->to_check[py - 1][px] != '1')
		flood_fill(game, py - 1, px);
	if (game->to_check[py + 1][px] != '1')
		flood_fill(game, py + 1, px);
	if (game->to_check[py][px - 1] != '1')
		flood_fill(game, py, px - 1);
	if (game->to_check[py][px + 1] != '1')
		flood_fill(game, py, px + 1);
}

static void	check_padding(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (++y < game->total_y - 1)
	{
		x = 0;
		while (++x < game->total_x - 1)
		{
			if (game->map[y][x] == 'P')
			{
				game->y_player = y;
				game->x_player = x;
				game->p_count++;
			}
			else if (game->map[y][x] == 'E')
				game->e_count++;
			else if (game->map[y][x] == 'C')
				game->c_count++;
			else if (game->map[y][x] != '0' && game->map[y][x] != '1')
				error(BAD_CONTAIN);
		}
	}
	if (game->p_count != 1 || game->c_count < 1 || game->e_count != 1)
		error(BAD_ELEMENTS);
}

void	check_map(t_game *game)
{
	int	y;
	int	x;

	y = -1;
	while (game->map[++y])
	{
		if (game->total_x != ft_strlen(game->map[y]))
			error(BAD_ROWSIZE);
		x = -1;
		while (game->map[y][++x])
		{
			if (y == 0 || x == 0 || y == game->total_y - 1
				|| x == game->total_x - 1)
				if (game->map[y][x] != '1')
					error(MAP_NOTVALID);
		}
	}
	check_padding(game);
	flood_fill(game, game->y_player, game->x_player);
	is_played(game->to_check);
}
