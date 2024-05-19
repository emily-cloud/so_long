/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hai <hai@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 11:01:47 by hai               #+#    #+#             */
/*   Updated: 2024/05/19 11:06:46 by hai              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_map(t_game *game, char *argv)
{
	check_name(game, argv);
	check_newline(game);
	check_number(game);
	check_rect(game);
	check_char(game);
	check_map_size(game);
	check_wall(game);
	check_path(game);
}

void	check_name(t_game *game, char *argv)
{
	size_t	len;

	len = ft_strlen(argv);
	if (len < 4 || argv[len - 1] != 'r' || argv[len - 2] != 'e'
		|| argv[len - 3] != 'b' || argv[len - 4] != '.')
	{
		ft_printf("Error map\nMap name format is wrong\n");
		close_window(game);
	}
}

void	check_newline(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->height)
	{
		if (*game->map[i] == '\0')
		{
			ft_printf("Error map\nFound newline outside the map\n");
			close_window(game);
		}
		i++;
	}
}

void	*check_number(t_game *game)
{
	if (game->exit != 1 || game->start != 1 || game->collect <= 1)
	{
		ft_printf("Error map\nMap must contain 1 start, 1 exit, 1+ collect\n");
		close_window(game);
	}
	return (0);
}

void	check_rect(t_game *game)
{
	int		i;
	size_t	len;

	i = 1;
	len = ft_strlen(game->map[0]);
	while (game->map[i])
	{
		if (len != ft_strlen(game->map[i]))
		{
			ft_printf("Error map\nMap must be rectangular\n");
			close_window(game);
		}
		i++;
	}
}
