/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hai <hai@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 10:46:25 by hai               #+#    #+#             */
/*   Updated: 2024/05/19 10:52:25 by hai              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc == 2)
	{
		game = malloc(sizeof(t_game));
		if (!game)
			malloc_failed(game);
		init_game_data(game);
		init_game(game, argv[1]);
		mlx_hook(game->win, KEY_PRESS, 1L << 0, &input_process, game);
		mlx_hook(game->win, CLOSE_KEY, 0, &close_window, game);
		mlx_loop(game->mlx);
		exit(EXIT_SUCCESS);
	}
	else
	{
		ft_printf("Error input\n");
		exit(EXIT_FAILURE);
	}
}

void	init_game_data(t_game *game)
{
	game->mlx = NULL;
	game->win = NULL;
	game->moves_str = NULL;
	game->moves = 0;
	game->score = 0;
	game->score_str = NULL;
	game->mario_direction = 1;
	game->width = 0;
	game->height = 0;
	game->collect = 0;
	game->c_check = 0;
	game->exit = 0;
	game->e_check = 0;
	game->start = 0;
	game->player_x = 0;
	game->player_y = 0;
	game->map = NULL;
	game->map_copy = NULL;
	game->img = NULL;
}

void	malloc_failed(t_game *game)
{
	(void)game;
	ft_printf("Malloc failed\n");
	exit(EXIT_FAILURE);
}

void	init_game(t_game *game, char *argv)
{
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		ft_printf("Error initalize MLX connection\n");
		free(game);
		exit(EXIT_FAILURE);
	}
	get_map_data(game, argv);
	check_map(game, argv);
	game->img = create_img(game);
	game->win = mlx_new_window(game->mlx, game->width * 32, game->height * 32,
			"simple mario");
	if (!game->win)
	{
		ft_printf("Error to creat new window\n");
		free(game->mlx);
		free(game);
		exit(EXIT_FAILURE);
	}
	create_display(game);
	ft_printf("moves: %d\n", game->moves);
}
