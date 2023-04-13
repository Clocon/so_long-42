/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumorale <lumorale@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 13:03:58 by lumorale          #+#    #+#             */
/*   Updated: 2023/04/11 16:43:13 by lumorale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

static void	init_struct(t_game *game)
{
	game->map = ft_split(game->no_map, '\n');
	game->to_check = ft_split(game->no_map, '\n');
	game->total_x = ft_strlen(game->map[1]);
	game->p_count = 0;
	game->c_count = 0;
	game->e_count = 0;
	game->moves = 0;
	game->map_width = game->total_x * SPR;
	game->map_height = game->total_y * SPR;
	game->counter = 0;
	game->move_count = 0;
	game->c_enemy = 0;
}

static void	map_taker(t_game *game)
{
	char	*tmp;

	game->total_y = 0;
	game->no_map = 0;
	while (1)
	{
		tmp = get_next_line(game->fd);
		if (!tmp)
			break ;
		game->no_map = ft_strjoin_free(game->no_map, tmp);
		free(tmp);
		game->total_y++;
	}
	if (!game->no_map)
		error(EMPTY_MAP);
	if (game->no_map[0] == '\n')
		error(INVALID_MAP);
	init_struct(game);
	check_map(game);
}

static void	check_args(char **argv)
{
	if (ft_strncmp(argv[1], "map/bonus/", 10) != 0)
		error(INVALID_PATH);
	if (ft_strncmp(&argv[1][(ft_strlen(argv[1]) - 4)], ".ber", 4) != 0)
		error(INVALID_EXT);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc == 2)
		check_args(argv);
	else
		error(INVALID_NARG);
	game.fd = open(argv[1], O_RDONLY);
	if (game.fd == -1)
		error(INVALID_FDMAP);
	map_taker(&game);
	game_start(&game);
	final_free(&game);
}
