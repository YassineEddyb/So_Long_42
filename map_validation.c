/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yed-dyb <yed-dyb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 12:25:17 by yed-dyb           #+#    #+#             */
/*   Updated: 2021/12/17 10:58:18 by yed-dyb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_top_bottom_wall(char **map, int index)
{
	int	i;

	i = 0;
	while (map[index][i])
	{
		if (map[index][i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	check_left_right_wall(char **map, int index)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (map[i][index] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	check_map_components(char **map)
{
	int	i;
	int	j;
	int	p;
	int	e;

	i = 0;
	p = 0;
	e = 0;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'P')
				p++;
			else if (map[i][j] == 'Y')
				g_enemies++;
			else if (map[i][j] == 'C')
				g_total_coins++;
			else if (map[i][j] == 'E')
				e++;
		}
	}
	return (validate_component(p, e));
}

int	check_lines(char **map)
{
	int		i;
	size_t	line_len;

	line_len = ft_strlen(map[0]);
	i = 1;
	while (map[i])
	{
		if (ft_strlen(map[i]) != line_len)
			return (0);
		i++;
	}
	return (1);
}

int	validate_map(char *path, char **map, int count)
{
	int	i;
	int	err;

	i = 0;
	err = 1;
	while (path[i] != '.')
		i++;
	if (ft_strncmp(path + i, ".ber", 4))
		err = 0;
	if (!check_top_bottom_wall(map, 0) \
		|| !check_top_bottom_wall(map, count - 1))
		err = 0;
	if (!check_left_right_wall(map, 0) \
		|| !check_left_right_wall(map, ft_strlen(map[0]) - 1))
		err = 0;
	if (!check_map_components(map) || !check_lines(map))
		err = 0;
	if (!err)
		return (0);
	return (1);
}
