/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hai <hai@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 10:51:35 by hai               #+#    #+#             */
/*   Updated: 2024/05/19 10:51:52 by hai              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	input_process(int keysym, t_game *game)
{
	if (keysym == W_KEY || keysym == UP_ARROW)
		mario_up(game);
	if (keysym == A_KEY || keysym == LEFT_ARROW)
		mario_left(game);
	if (keysym == S_KEY || keysym == DOWN_ARROW)
		mario_down(game);
	if (keysym == D_KEY || keysym == RIGHT_ARROW)
		mario_right(game);
	if (keysym == ESC_KEY)
		close_window(game);
	return (0);
}

void	update_score(t_game *game)
{
	game->score += 1;
	if (!game->score_str)
		malloc_failed(game);
}

void	update_moves(t_game *game)
{
	game->moves += 1;
	if (!game->moves_str)
		malloc_failed(game);
}
