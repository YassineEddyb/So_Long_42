/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yed-dyb <yed-dyb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 10:03:08 by yed-dyb           #+#    #+#             */
/*   Updated: 2022/01/03 17:13:50 by yed-dyb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*put_imgae(t_vars vars, int i, int j)
{
	void	*img;

	if (i % 2 == 0)
	{
		if (j % 2 == 0)
			img = get_image(vars, "./images/white.xpm");
		else
			img = get_image(vars, "./images/black.xpm");
	}
	else
	{
		if (j % 2 != 0)
			img = get_image(vars, "./images/white.xpm");
		else
			img = get_image(vars, "./images/black.xpm");
	}
	return (img);
}

void	render_map(char **map, t_vars vars, t_Player *p, int rr)
{
	int		i;
	int		j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == '1' && rr)
				render_image(vars, "./images/wall.xpm", i, j);
			else if (map[i][j] == 'E')
				render_image(vars, g_door, i, j);
			else if (map[i][j] == 'C' && rr)
				render_image(vars, "./images/coin.xpm", i, j);
			else if (map[i][j] != '0' && map[i][j] != 'Y' && \
				map[i][j] != 'P' && rr)
			{
				printf("\n\033[0;31m=> %s\n\n", "ERROR : MAP NOT VALID");
				exit(1);
			}
		}
	}
	render_image(vars, g_thief, p->y, p->x);
}

void	render_background(char **map, t_vars vars)
{
	int		i;
	int		j;
	void	*img;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] && map[i][j] != '\n')
		{
			img = put_imgae(vars, i, j);
			mlx_put_image_to_window (vars.mlx, vars.win, img, \
				j * PIXELS, i * PIXELS);
			j++;
		}
		i++;
	}
}

void	render_image(t_vars vars, char *path, int i, int j)
{
	void	*img;

	img = get_image(vars, path);
	mlx_put_image_to_window (vars.mlx, vars.win, img, \
		j * PIXELS, i * PIXELS);
}

void	render_pixel(t_vars vars, int i, int j)
{
	void	*img;

	img = get_image(vars, "./images/white_image.xpm");
	mlx_put_image_to_window (vars.mlx, vars.win, img, 0, 0);
	img = put_imgae(vars, i, j);
	mlx_put_image_to_window (vars.mlx, vars.win, img, \
		j * PIXELS, i * PIXELS);
}
