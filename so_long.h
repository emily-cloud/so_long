/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hai <hai@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 09:46:02 by hai               #+#    #+#             */
/*   Updated: 2024/05/19 12:28:26 by hai              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include <X11/X.h>
# include <X11/Xlib.h>
# include <X11/keysym.h>
# include <errno.h>
# include <fcntl.h>
# include <mlx.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>

//defines values of keyboard inputs
typedef enum e_key_code
{
	CLOSE_KEY = 17,
	ESC_KEY = 65307,
	KEY_PRESS = 2,
	UP_ARROW = 65362,
	DOWN_ARROW = 65364,
	LEFT_ARROW = 65361,
	RIGHT_ARROW = 65363,
	W_KEY = 119,
	A_KEY = 97,
	S_KEY = 115,
	D_KEY = 100
}			t_key_code;

typedef struct s_img
{
	void	*mario_left;
	void	*mario_right;
	void	*meadow;
	void	*mushroom;
	void	*wall;
	void	*exit;
	void	*mario_win;
	void	*scorehold;
}			t_img;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	char	*moves_str;
	int		moves;
	int		score;
	char	*score_str;
	int		mario_direction;
	int		width;
	int		height;
	int		collect;
	int		c_check;
	int		exit;
	int		e_check;
	int		start;
	int		player_x;
	int		player_y;
	char	**map;
	char	**map_copy;
	t_img	*img;
}			t_game;

void		check_map(t_game *game, char *argv);
void		check_name(t_game *game, char *argv);
void		check_newline(t_game *game);
void		*check_number(t_game *game);
void		check_rect(t_game *game);
void		check_char(t_game *game);
void		check_map_size(t_game *game);
void		check_wall(t_game *game);
void		check_cell(char c, t_game *game);
void		check_path(t_game *game);
void		find_player(t_game *game);
void		move_on_path(int x, int y, t_game *game);

//functions to creat the game outlook
t_img		*create_img(t_game *game);
void		assign_img(t_img *img, t_game *game);
void		create_display(t_game *game);
void		fill_pixel(int x, int y, t_game *game);
void		display_move_score(t_game *game);

// functions to read all the date of the map
void		init_game_data(t_game *game);
void		get_map_data(t_game *game, char *argv);
void		file_open_error(t_game *game, int fd);
int			get_map_height(t_game *game, int fd);
void		read_map(t_game *game, char *argv);
int			count_collect(t_game *game);
int			count_exit(t_game *game);
int			count_start(t_game *game);

//main functions and some other help func
int			main(int argc, char **argv);
void		malloc_failed(t_game *game);
void		init_game(t_game *game, char *argv);
int			input_process(int keysym, t_game *game);
void		update_score(t_game *game);
void		update_moves(t_game *game);
int			close_window(t_game *game);
void		free_all(t_game *game);
void		clean_img(t_game *game);
void		free_map(char **map);

//movements function
void		mario_down(t_game *game);
void		down_win(t_game *game);
void		renew_win_down(t_game *game);
void		renew_pixel_down(t_game *game);
void		mario_left(t_game *game);
void		left_win(t_game *game);
void		left_helper(t_game *game);
void		renew_win_left(t_game *game);
void		renew_pixel_left(t_game *game);
void		mario_right(t_game *game);
void		right_win(t_game *game);
void		right_helper(t_game *game);
void		renew_win_right(t_game *game);
void		renew_pixel_right(t_game *game);
void		mario_up(t_game *game);
void		up_win(t_game *game);
void		renew_win_up(t_game *game);
void		renew_pixel_up(t_game *game);

//utils
char		*ft_strdup_nl(char *s1);

#endif
