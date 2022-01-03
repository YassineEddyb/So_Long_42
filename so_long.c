/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yed-dyb <yed-dyb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 21:13:49 by yed-dyb           #+#    #+#             */
/*   Updated: 2022/01/03 17:16:19 by yed-dyb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <pthread.h>

t_vars		g_vars;
char		**g_map;
t_Enemy		*g_e;

void	check_collision(t_Player *p)
{
	int	i;

	i = 0;
	while (i < g_enemies)
	{
		if (g_e[i].x == p->x && g_e[i].y == p->y)
		{
			printf("\n\033[0;31m=> YOU LOSE\n\n");
			exit(1);
		}
		i++;
	}
}

int	move_player(int keycode, t_Player *p)
{
	int	i;
	int	j;

	i = p->x;
	j = p->y;
	render_pixel(g_vars, p->y, p->x);
	if (keycode == 125 || keycode == 1)
		move_down(g_map, p);
	else if (keycode == 126 || keycode == 13)
		move_up(g_map, p);
	else if (keycode == 123 || keycode == 0)
		move_right(g_map, p);
	else if (keycode == 124 || keycode == 2)
		move_left(g_map, p);
	else if (keycode == 53)
	{
		mlx_destroy_window(g_vars.mlx, g_vars.win);
		exit(1);
	}
	if (i != p->x || j != p->y)
		g_move++;
	check_coins_and_exit(g_vars, g_map, p);
	check_collision(p);
	render_map(g_map, g_vars, p, 0);
	return (0);
}

int	move_enemy(t_Player *p)
{
	int		i;
	char	*moves;

	i = 0;
	if (g_frame == 3000)
	{
		while (i < g_enemies)
		{
			render_pixel(g_vars, g_e[i].y, g_e[i].x);
			get_direction(g_map, g_e, i);
			check_collision(p);
			render_image(g_vars, "./images/cop.xpm", g_e[i].y, g_e[i].x);
			moves = ft_itoa(g_move);
			mlx_string_put(g_vars.mlx, g_vars.win, 10, 10, \
				0x00, moves);
			free(moves);
			i++;
		}
		g_frame = 0;
	}
	else
		g_frame++;
	return (0);
}

void	init(void)
{
	g_total_coins = 0;
	g_move = 0;
	g_coins = 0;
	g_frame = 0;
	g_door = "./images/close_door.xpm";
	g_thief = "./images/thief-left.xpm";
}

int	main(int argc, char **argv)
{
	int			fd;
	char		*str;
	t_Player	p;

	init();
	fd = open(argv[1], 2);
	str = read_file(fd);
	g_map = ft_split(str, '\n');
	if (argc > 2 || !g_map || fd < 0 ||!validate_map(argv[1], g_map, g_width))
	{
		printf("\n\033[0;31m=> %s\n\n", "ERROR : MAP NOT VALID OR FILE NOT EXIST");
		return (1);
	}
	g_e = malloc(g_enemies * sizeof(t_Enemy));
	get_player_and_enemies(g_map, &p, g_e);
	g_vars.mlx = mlx_init();
	g_vars.win = mlx_new_window(g_vars.mlx, (ft_strlen(g_map[0])) * PIXELS, \
		g_width * PIXELS, "so_long");
	render_background(g_map, g_vars);
	mlx_key_hook(g_vars.win, move_player, &p);
	render_map(g_map, g_vars, &p, 1);
	mlx_loop_hook(g_vars.mlx, move_enemy, &p);
	mlx_hook(g_vars.win, 17, 0, close_window, &g_vars);
	mlx_loop(g_vars.mlx);
	return (0);
}
