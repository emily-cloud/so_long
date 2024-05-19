/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_data2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hai <hai@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 10:58:06 by hai               #+#    #+#             */
/*   Updated: 2024/05/19 10:58:46 by hai              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_collect(t_game *game)
{
	int	i;
	int	j;
	int	collect;

	i = 0;
	collect = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'C')
				collect++;
			j++;
		}
		i++;
	}
	return (collect);
}

int	count_exit(t_game *game)
{
	int	i;
	int	j;
	int	exit;

	i = 0;
	exit = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'E')
				exit++;
			j++;
		}
		i++;
	}
	return (exit);
}

int	count_start(t_game *game)
{
	int	i;
	int	j;
	int	start;

	i = 0;
	start = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'P')
				start++;
			j++;
		}
		i++;
	}
	return (start);
}
