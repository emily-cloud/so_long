/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_up.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hai <hai@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 11:33:35 by hai               #+#    #+#             */
/*   Updated: 2024/05/19 11:38:42 by hai              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	mario_up(t_game *game)
{
	char	next_tile;

	next_tile = game->map[game->player_y - 1][game->player_x];
	if (next_tile == 'C')
		update_score(game);
	if (next_tile == 'E' && game->score == game->collect)
	{
		up_win(game);
		game->player_y -= 1;
		close_window(game);
	}
	if (next_tile == 'E' && game->score != game->collect)
		ft_printf("Mushrooms have been all collected before exit!\n");
	if ((next_tile != '1') && (next_tile != 'E'))
	{
		update_moves(game);
		renew_pixel_up(game);
		ft_printf("movements: %d\n", game->moves);
		if (next_tile == 'C')
			game->map[game->player_y - 1][game->player_x] = '0';
		game->player_y -= 1;
	}
	else if (next_tile == '1')
		ft_printf("Cannot move to the tile: %c\n", next_tile);
	display_move_score(game);
}

void	up_win(t_game *game)
{
	update_moves(game);
	ft_printf("movements: %d\n", game->moves);
	ft_printf("Congratulations\nYou win!\n");
	renew_win_up(game);
	display_move_score(game);
}

void	renew_win_up(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->win, game->img->meadow,
		game->player_x * 32, game->player_y * 32);
	mlx_put_image_to_window(game->mlx, game->win, game->img->mario_win,
		game->player_x * 32, (game->player_y - 1) * 32);
}

void	renew_pixel_up(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->win, game->img->meadow,
		game->player_x * 32, game->player_y * 32);
	if (game->mario_direction == 1)
		mlx_put_image_to_window(game->mlx, game->win, game->img->mario_right,
			game->player_x * 32, (game->player_y - 1) * 32);
	else
		mlx_put_image_to_window(game->mlx, game->win, game->img->mario_left,
			game->player_x * 32, (game->player_y - 1) * 32);
}
