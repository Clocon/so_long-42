/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freerror.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumorale <lumorale@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 12:17:18 by lumorale          #+#    #+#             */
/*   Updated: 2023/04/10 18:08:37 by lumorale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	error(char *msg)
{
	ft_putstr_fd(ft_strjoin("Error\n", msg), 2);
	exit (1);
}

void	console_msg(char *msg, int to_exit)
{
	ft_putstr_fd(msg, 1);
	ft_putstr_fd("\n", 1);
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
