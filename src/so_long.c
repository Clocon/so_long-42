/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumorale <lumorale@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 13:03:58 by lumorale          #+#    #+#             */
/*   Updated: 2023/04/04 16:33:32 by lumorale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	map_taker(t_game *game)
{
	char	*tmp;

	game->no_map = 0;
	while (1)
	{
		tmp = get_next_line(game->fd);
		if (!tmp)
			break ;
		game->no_map = ft_strjoin(game->no_map, tmp);
	}
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc == 2)
		check_args(argv);
	else
		error(INVALID_NARG, 1);
	game.fd = open(argv[1], O_RDONLY);
	if (game.fd == -1)
		error(INVALID_MAP, 1);
	map_taker(&game);
}
