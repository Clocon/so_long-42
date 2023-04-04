/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumorale <lumorale@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 13:25:52 by lumorale          #+#    #+#             */
/*   Updated: 2023/04/04 18:47:33 by lumorale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	error(char *msg, int to_exit)
{
	ft_putstr_fd(ft_strjoin("Error\n", msg), 2);
	if (to_exit == 1)
		exit (1);
}

void	check_args(char **argv)
{
	if (ft_strncmp(argv[1], "map/", 4) != 0)
		error(INVALID_PATH, 1);
	if (ft_strncmp(&argv[1][(ft_strlen(argv[1]) - 4)], ".bar", 4) != 0)
		error(INVALID_EXT, 1);
}

static void	check_padding(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	game->p_count = 0;
	game->c_count = 0;
	game->e_count = 0;
	while (++y < game->total_y - 1)
	{
		x = 0;
		while (++x < game->total_x - 1)
		{
			if (game->map[y][x] == 'P')
				game->p_count++;
			else if (game->map[y][x] == 'E')
				game->e_count++;
			else if (game->map[y][x] == 'C')
				game->c_count++;
			else if (game->map[y][x] != '0' && game->map[y][x] != '1')
				error(BAD_CONTAIN, 1);
		}
	}
	if (game->p_count != 1 || game->c_count < 1 || game->e_count != 1)
		error(BAD_ELEMENTS, 1);
}

void	check_map(t_game *game)
{
	int	y;
	int	x;

	game->total_x = strlen(game->map[1]);
	y = -1;
	while (game->map[++y])
	{
		if (game->total_x != ft_strlen(game->map[y]))
			error(BAD_ROWSIZE, 1);
		x = -1;
		while (game->map[y][++x])
		{
			if (game->map[y][x] == 'P')
			{
				game->y_player = y;
				game->y_player = y;
			}
			if (y == 0 || x == 0 || y == game->total_y - 1
				|| x == game->total_x - 1)
				if (game->map[y][x] != '1')
					error(MAP_NOTVALID, 1);
		}
	}
	check_padding(game);
}
