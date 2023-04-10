/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumorale <lumorale@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 13:51:53 by lumorale          #+#    #+#             */
/*   Updated: 2023/04/10 16:22:04 by lumorale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/includes/libft.h"
# include "../ft_printf/includes/ft_printf.h"
# include "../get_next_line/includes/get_next_line.h"
# include "../MLX42/include/MLX42/MLX42.h"
# include <math.h>

// Constants defines
# define INVALID_EXT "The file extension must be <.bar>\n"
# define INVALID_PATH "The path for take the map must be <map/>\n"
# define INVALID_NARG "The valid usage is = ./so_long <map/mapName.bar>\n"
# define INVALID_FDMAP "Fail opening the map or map doesn't exist\n"
# define MAP_NOTVALID "The map have bad struct\n"
# define BAD_ROWSIZE "The map does not have the correct dimensions\n"
# define BAD_CONTAIN "The map contain not valid character\n"
# define BAD_ELEMENTS "This map have bad number of players, collectors or exit\n"
# define IMPOSIBLE_WIN "The map has no viable way to complete the game\n"
# define EMPTY_MAP "The map is empty\n"
# define INVALID_MAP "The map is not valid\n"
# define WIN_OK "Congratulations, you are so good!!"
# define WIN_KO "You need take all items for win!!"
# define N_MOVES " Movements"

# define SPR 64

typedef struct s_game
{
	char		*no_map;
	char		**map;
	char		**to_check;
	int			fd;
	int			y_player;
	int			x_player;
	int			new_yp;
	int			new_xp;
	int			total_y;
	int			total_x;
	int			p_count;
	int			c_count;
	int			e_count;
	int			moves;
	int			map_width;
	int			map_height;
	mlx_t		*mlx;
	mlx_image_t	*limit_img;
	mlx_image_t	*floor_img;
	mlx_image_t	*player_img;
	mlx_image_t	*collect_img;
	mlx_image_t	*gate_img;
}	t_game;

typedef struct s_textures
{
	mlx_texture_t	*limits;
	mlx_texture_t	*floor;
	mlx_texture_t	*player;
	mlx_texture_t	*collect;
	mlx_texture_t	*gate;
}	t_textures;

/*Functions for checker.c*/
void	check_args(char **argv);
void	check_map(t_game *game);

/*Functions for freerror.c*/
void	error(char *msg, int to_exit);
void	console_msg(char *msg);
void	free_matrix(char **str);
void	final_free(t_game *game);

/*Functions for game.c*/
void	game_start(t_game *game);
void	print_map(t_game *game);

/*Functions for moves_controls.c*/
void	controls(mlx_key_data_t keydata, void *gv);
#endif
