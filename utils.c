/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hai <hai@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 10:44:25 by hai               #+#    #+#             */
/*   Updated: 2024/05/19 10:50:36 by hai              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strdup_nl(char *s1)
{
	char	*dest;
	size_t	i;
	size_t	len;

	if (!s1)
		return (NULL);
	len = 0;
	i = 0;
	while (s1[len] && s1[len] != '\n')
		len++;
	dest = (char *)malloc(len + 1);
	if (!dest)
		return (NULL);
	while (i < len)
	{
		dest[i] = s1[i];
		i++;
	}
	dest[len] = 0;
	return (dest);
}

int	close_window(t_game *game)
{
	if (game->score != game->collect && game->win != NULL)
		ft_printf("You lost the game(:\n");
	free_all(game);
	exit(EXIT_SUCCESS);
}

void	free_all(t_game *game)
{
	if (game->map != NULL)
		free_map(game->map);
	if (game->map_copy != NULL)
		free_map(game->map_copy);
	if (game->img != NULL)
		clean_img(game);
	if (game->img)
		free(game->img);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	free(game);
	return ;
}

void	clean_img(t_game *game)
{
	if (game->img->mario_left != NULL)
		mlx_destroy_image(game->mlx, game->img->mario_left);
	if (game->img->mario_right != NULL)
		mlx_destroy_image(game->mlx, game->img->mario_right);
	if (game->img->meadow != NULL)
		mlx_destroy_image(game->mlx, game->img->meadow);
	if (game->img->mushroom != NULL)
		mlx_destroy_image(game->mlx, game->img->mushroom);
	if (game->img->wall != NULL)
		mlx_destroy_image(game->mlx, game->img->wall);
	if (game->img->exit != NULL)
		mlx_destroy_image(game->mlx, game->img->exit);
	if (game->img->mario_win != NULL)
		mlx_destroy_image(game->mlx, game->img->mario_win);
	if (game->img->scorehold != NULL)
		mlx_destroy_image(game->mlx, game->img->scorehold);
	if (game->win != NULL)
		mlx_destroy_window(game->mlx, game->win);
	return ;
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}
