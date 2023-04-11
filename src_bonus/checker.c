/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumorale <lumorale@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 13:25:52 by lumorale          #+#    #+#             */
/*   Updated: 2023/04/11 13:08:02 by lumorale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

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

static void	bonus_check(t_game *game, int y, int x)
{
	if (game->map[y][x] == 'L' || game->map[y][x] == 'R')
	{
		game->y_enemy = y;
		game->x_enemy = x;
		game->c_enemy++;
		if (!free_way(game, y - 1) && !free_way(game, y + 1))
			error(CANT_SCAPE);
	}
	else if (game->map[y][x] != '0' && game->map[y][x] != 'L'
			&& game->map[y][x] != '1' && game->map[y][x] != 'R')
		error(BAD_CONTAIN);
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
			else
				bonus_check(game, y, x);
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
