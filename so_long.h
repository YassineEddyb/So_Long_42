/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yed-dyb <yed-dyb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 21:13:56 by yed-dyb           #+#    #+#             */
/*   Updated: 2021/12/21 11:04:36 by yed-dyb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdio.h>
# include <fcntl.h>
# include "libft/libft.h"
# include "get_next_line/get_next_line.h"

# define PIXELS 40

typedef struct s_vars
{
	void	*mlx;
	void	*win;
}	t_vars;

typedef struct s_Player
{
	int	x;
	int	y;
}	t_Player;

typedef struct s_Enemy
{
	int	x;
	int	y;
	int	dir;
}	t_Enemy;

int			g_move;
int			g_total_coins;
int			g_coins;
int			g_enemies;
int			g_width;
int			g_frame;
char		*g_door;
char		*g_thief;

int		validate_map(char *path, char **map, int count);
void	render_background(char **map, t_vars vars);
void	render_image(t_vars vars, char *path, int i, int j);
void	render_pixel(t_vars vars, int i, int j);
void	render_map(char **map, t_vars vars, t_Player *p, int rr);
void	move_down(char **map, t_Player *p);
void	move_up(char **map, t_Player *p);
void	move_left(char **map, t_Player *p);
void	move_right(char **map, t_Player *p);
void	get_player_and_enemies(char **map, t_Player *p, t_Enemy *e);
void	check_coins_and_exit(t_vars g_vars, char **map, t_Player *p);
void	get_direction(char **map, t_Enemy *e, int i);
void	*get_image(t_vars vars, char *path);
int		validate_component(int p, int e);
void	check_collision(t_Player *p);
int		close_window(t_vars *vars);
char	*read_file(int fd);

#endif
