/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freerror.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumorale <lumorale@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 12:17:18 by lumorale          #+#    #+#             */
/*   Updated: 2023/04/11 13:19:11 by lumorale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	error(char *msg)
{
	ft_putstr_fd(ft_strjoin("Error\n", msg), 2);
	exit(1);
}

void	console_msg(char *msg)
{
	ft_putstr_fd(msg, 1);
	ft_putstr_fd("\n", 1);
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
