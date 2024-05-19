/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hai <hai@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 11:02:12 by hai               #+#    #+#             */
/*   Updated: 2024/05/19 11:05:47 by hai              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_wall(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (i == 0 || i == game->height - 1)
				check_cell(game->map[i][j], game);
			else if (j == 0 || j == game->width - 1)
				check_cell(game->map[i][j], game);
			j++;
		}
		i++;
	}
}

void	check_cell(char c, t_game *game)
{
	if (c != '1')
	{
		ft_printf("Error map\nMap must have complete walls\n");
		close_window(game);
	}
}

void	check_path(t_game *game)
{
	find_player(game);
	move_on_path(game->player_x, game->player_y, game);
	if (game->c_check != 0 || game->e_check >= game->exit)
	{
		ft_printf("Error\nMap contains invalid path\n");
		close_window(game);
	}
}

void	find_player(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'P')
			{
				game->player_x = j;
				game->player_y = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	move_on_path(int x, int y, t_game *game)
{
	char	c;

	if (x < 0 || x >= game->width || y < 0 || y >= game->height)
		return ;
	c = game->map_copy[y][x];
	if (c == 'C')
	{
		game->c_check -= 1;
		game->map_copy[y][x] = '1';
	}
	else if (c == 'E')
	{
		game->e_check -= 1;
		game->map_copy[y][x] = '1';
	}
	else if (c == '0' || c == 'P')
		game->map_copy[y][x] = '1';
	else
		return ;
	move_on_path(x + 1, y, game);
	move_on_path(x - 1, y, game);
	move_on_path(x, y + 1, game);
	move_on_path(x, y - 1, game);
}
