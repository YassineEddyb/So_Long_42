/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_helpers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yed-dyb <yed-dyb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 21:13:44 by yed-dyb           #+#    #+#             */
/*   Updated: 2021/12/21 11:05:10 by yed-dyb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*read_file(int fd)
{
	char	*str;
	char	*line;

	line = get_next_line(fd);
	str = NULL;
	while (line)
	{
		if (line[0] == '\n')
		{
			printf("\n\033[0;31m=> EPMTY LINE IN THE MAP\n\n");
			exit(1);
		}
		str = ft_str_join(str, line);
		free(line);
		line = get_next_line(fd);
		g_width++;
	}
	close(fd);
	return (str);
}

void	get_player_and_enemies(char **map, t_Player *p, t_Enemy *e)
{
	int	i;
	int	j;
	int	k;

	i = -1;
	k = 0;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j] && map[i][j] != '\n')
		{
			if (map[i][j] == 'P')
			{
				p->y = i;
				p->x = j;
			}
			else if (map[i][j] == 'Y')
			{
				e[k].y = i;
				e[k].x = j;
				e[k++].dir = 1;
			}
		}
	}
}

void	check_coins_and_exit(t_vars vars, char **map, t_Player *p)
{
	char	*moves;

	if (map[p->y][p->x] == 'E' && g_coins == g_total_coins)
	{
		printf("\n\033[0;32m=> YOU WIN\n\n");
		exit(1);
	}
	if (map[p->y][p->x] == 'C')
	{
		g_coins++;
		map[p->y][p->x] = 0;
		render_pixel(vars, p->y, p->x);
	}
	if (g_coins == g_total_coins)
		g_door = "./images/open_door.xpm";
	moves = ft_itoa(g_move);
	mlx_string_put(vars.mlx, vars.win, 10, 10, 0x00000000, moves);
	free(moves);
}

void	get_direction(char **map, t_Enemy *e, int i)
{
	if (e[i].dir)
	{
		if (map[e[i].y + 1][e[i].x] != '1')
			e[i].y = e[i].y + 1;
		else
			e[i].dir = 0;
	}
	else
	{
		if (map[e[i].y - 1][e[i].x] != '1')
			e[i].y = e[i].y - 1;
		else
			e[i].dir = 1;
	}
}

void	*get_image(t_vars vars, char *path)
{
	int		img_w;
	int		img_h;
	void	*img;

	img = mlx_xpm_file_to_image(vars.mlx, path, &img_w, &img_h);
	return (img);
}
