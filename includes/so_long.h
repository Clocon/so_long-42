/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumorale <lumorale@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 13:51:53 by lumorale          #+#    #+#             */
/*   Updated: 2023/04/04 18:39:56 by lumorale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/includes/libft.h"
# include "../ft_printf/includes/ft_printf.h"
# include "../get_next_line/includes/get_next_line.h"
# include "../MLX42/include/MLX42/MLX42.h"
# include <math.h>

# define INVALID_EXT "The file extension must be <.bar>\n"
# define INVALID_PATH "The path for take the map must be <map/>\n"
# define INVALID_NARG "The valid usage is = ./so_long <map/mapName.bar>\n"
# define INVALID_MAP "Fail opening the map or map doesn't exist\n"
# define MAP_NOTVALID "The map have bad struct\n"
# define BAD_ROWSIZE "The map does not have the correct dimensions\n"
# define BAD_CONTAIN "The map contain not valid character\n"
# define BAD_ELEMENTS "This map have bad number of players, collectors or exit\n"

typedef struct s_game
{
	char	*no_map;
	char	**map;
	int		fd;
	int		y_player;
	int		x_player;
	int		total_y;
	int		total_x;
	int		p_count;
	int		c_count;
	int		e_count;
}	t_game;

/*Functions for checker.c*/
void	error(char *msg, int to_exit);
void	check_args(char **argv);
void	check_map(t_game *game);

#endif
