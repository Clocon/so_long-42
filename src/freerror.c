/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freerror.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumorale <lumorale@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 12:17:18 by lumorale          #+#    #+#             */
/*   Updated: 2023/04/05 13:01:06 by lumorale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	error(char *msg, int to_exit)
{
	ft_putstr_fd(ft_strjoin("Error\n", msg), 2);
	if (to_exit == 1)
		exit (1);
}

void	free_matrix(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	final_free(t_game *game)
{
	close(game->fd);
	free(game->no_map);
	free_matrix(game->map);
	free_matrix(game->to_check);
}
