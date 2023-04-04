/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumorale <lumorale@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 13:25:52 by lumorale          #+#    #+#             */
/*   Updated: 2023/04/04 14:20:14 by lumorale         ###   ########.fr       */
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
