/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumorale <lumorale@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 13:03:58 by lumorale          #+#    #+#             */
/*   Updated: 2023/04/04 13:47:43 by lumorale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
	int	fd;

	if (argc == 2)
	{
		if (ft_strncmp(&argv[1][(ft_strlen(argv[1]) - 4)], ".bar", 5) != 0)
			error(INVALID_ARG, 1);
		fd = open(ft_strjoin("map/", argv[1]), O_RDONLY);
		if (fd == -1)
			error(INVALID_MAP, 1);
	}
	else
		error(INVALID_NARG, 1);
}
