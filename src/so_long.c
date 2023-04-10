/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumorale <lumorale@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 13:03:58 by lumorale          #+#    #+#             */
/*   Updated: 2023/04/10 17:30:35 by lumorale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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
		error(EMPTY_MAP, 1);
	if (game->no_map[0] == '\n')
		error(INVALID_MAP, 1);
	init_struct(game);
	check_map(game);
}
/* void ft_void(void)
{
	system("leaks -q so_long");
} */

int	main(int argc, char **argv)
{
	//atexit(ft_void);
	t_game	game;

	if (argc == 2)
		check_args(argv);
	else
		error(INVALID_NARG, 1);
	game.fd = open(argv[1], O_RDONLY);
	if (game.fd == -1)
		error(INVALID_FDMAP, 1);
	map_taker(&game);
	game_start(&game);
	final_free(&game);
}
