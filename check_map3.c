/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hai <hai@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 11:04:01 by hai               #+#    #+#             */
/*   Updated: 2024/05/19 11:05:32 by hai              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_char(t_game *game)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			c = game->map[i][j];
			if (c != '1' && c != '0' && c != 'E' && c != 'C' && c != 'P')
			{
				ft_printf("Error\nMap contains invalid characters\n");
				close_window(game);
			}
			j++;
		}
		i++;
	}
}

void	check_map_size(t_game *game)
{
	if (game->height * 32 > 1080 || game->width * 32 > 1920)
	{
		ft_printf("Error\nMap size is too big\n");
		close_window(game);
	}
}
