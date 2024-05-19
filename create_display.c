/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_display.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hai <hai@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 11:08:43 by hai               #+#    #+#             */
/*   Updated: 2024/05/19 11:28:26 by hai              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_img	*create_img(t_game *game)
{
	int		img_width;
	int		img_height;
	char	*path;
	t_img	*img;

	img = malloc(sizeof(t_img));
	assign_img(img, game);
	path = "./pictures/exit.xpm";
	img->exit = mlx_xpm_file_to_image(game->mlx,
			path, &img_width, &img_height);
	path = "./pictures/score_area.xpm";
	img->scorehold = mlx_xpm_file_to_image(game->mlx,
			path, &img_width, &img_height);
	path = "./pictures/mario_win.xpm";
	img->mario_win = mlx_xpm_file_to_image(game->mlx,
			path, &img_width, &img_height);
	return (img);
}

void	assign_img(t_img *img, t_game *game)
{
	int		img_width;
	int		img_height;
	char	*path;

	path = "./pictures/mario_l.xpm";
	img->mario_left = mlx_xpm_file_to_image(game->mlx,
			path, &img_width, &img_height);
	path = "./pictures/mario_r.xpm";
	img->mario_right = mlx_xpm_file_to_image(game->mlx,
			path, &img_width, &img_height);
	path = "./pictures/meadow.xpm";
	img->meadow = mlx_xpm_file_to_image(game->mlx,
			path, &img_width, &img_height);
	path = "./pictures/mushroom.xpm";
	img->mushroom = mlx_xpm_file_to_image(game->mlx,
			path, &img_width, &img_height);
	path = "./pictures/brick.xpm";
	img->wall = mlx_xpm_file_to_image(game->mlx,
			path, &img_width, &img_height);
}

void	create_display(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			fill_pixel(x, y, game);
			x++;
		}
		y++;
	}
	game->score = 0;
	game->moves = 0;
	display_move_score(game);
}

void	fill_pixel(int x, int y, t_game *game)
{
	if (game->map[y][x] == 'P')
		mlx_put_image_to_window (game->mlx, game->win,
			game->img->mario_right, x * 32, y * 32);
	else if (game->map[y][x] == '0')
		mlx_put_image_to_window (game->mlx, game->win,
			game->img->meadow, x * 32, y * 32);
	else if (game->map[y][x] == 'C')
		mlx_put_image_to_window (game->mlx, game->win,
			game->img->mushroom, x * 32, y * 32);
	else if (game->map[y][x] == '1')
		mlx_put_image_to_window (game->mlx, game->win,
			game->img->wall, x * 32, y * 32);
	else if (game->map[y][x] == 'E')
		mlx_put_image_to_window (game->mlx, game->win,
			game->img->exit, x * 32, y * 32);
}

void	display_move_score(t_game *game)
{
	game->moves_str = ft_itoa(game->moves);
	game->score_str = ft_itoa(game->score);
	mlx_put_image_to_window(game->mlx, game->win, game->img->scorehold, 0, 0);
	mlx_string_put(game->mlx, game->win, 5, 12, 0xFF000000, "Mushrooms:");
	mlx_string_put(game->mlx, game->win, 67, 12, 0xFF000000, game->score_str);
	mlx_string_put(game->mlx, game->win, 5, 25, 0xFF000000, "Moves:");
	mlx_string_put(game->mlx, game->win, 67, 25, 0xFF000000, game->moves_str);
	free(game->moves_str);
	free(game->score_str);
}
