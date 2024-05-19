/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_data1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hai <hai@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 10:54:47 by hai               #+#    #+#             */
/*   Updated: 2024/05/19 10:58:49 by hai              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_map_data(t_game *game, char *argv)
{
	int		fd;
	char	*line;

	fd = open(argv, O_RDONLY);
	file_open_error(game, fd);
	line = get_next_line(fd);
	if (!line)
	{
		ft_printf("Error map\nEmpty map\n");
		free(line);
		close(fd);
		close_window(game);
	}
	game->width = ft_strlen(line) - 1;
	game->height = get_map_height(game, fd);
	read_map(game, argv);
	game->collect = count_collect(game);
	game->exit = count_exit(game);
	game->start = count_start(game);
	game->c_check = game->collect;
	game->e_check = game->exit;
	free(line);
	close(fd);
}

void	file_open_error(t_game *game, int fd)
{
	if (fd == -1)
	{
		perror("Error opening file\n");
		close_window(game);
	}
}

int	get_map_height(t_game *game, int fd)
{
	int		height;
	char	*line;

	(void)game;
	height = 1;
	line = get_next_line(fd);
	while (line)
	{
		height++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	return (height);
}

void	read_map(t_game *game, char *argv)
{
	char	*line;
	int		i;
	int		fd;

	i = 0;
	fd = open(argv, O_RDONLY);
	game->map = (char **)ft_calloc(game->height + 1, sizeof(char *));
	if (!game->map)
		malloc_failed(game);
	game->map_copy = (char **)ft_calloc(game->height + 1, sizeof(char *));
	if (!game->map_copy)
		malloc_failed(game);
	while (i < game->height)
	{
		line = get_next_line(fd);
		game->map[i] = ft_strdup_nl(line);
		game->map_copy[i] = ft_strdup_nl(line);
		free(line);
		i++;
	}
	game->map[game->height] = NULL;
	game->map_copy[game->height] = NULL;
}
