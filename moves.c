/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yed-dyb <yed-dyb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 19:47:08 by yed-dyb           #+#    #+#             */
/*   Updated: 2022/01/03 16:58:27 by yed-dyb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_down(char **map, t_Player *p)
{
	if (map[p->y + 1][p->x] != '1' && map[p->y + 1][p->x] != 'E')
		p->y = p->y + 1;
	else if (map[p->y + 1][p->x] == 'E' && g_coins == g_total_coins)
		p->y = p->y + 1;
}

void	move_up(char **map, t_Player *p)
{
	if (map[p->y - 1][p->x] != '1' && map[p->y - 1][p->x] != 'E')
		p->y = p->y - 1;
	else if (map[p->y - 1][p->x] == 'E' && g_coins == g_total_coins)
		p->y = p->y - 1;
}

void	move_left(char **map, t_Player *p)
{
	if (map[p->y][p->x + 1] != '1' && map[p->y][p->x + 1] != 'E')
		p->x = p->x + 1;
	else if (map[p->y][p->x + 1] == 'E' && g_coins == g_total_coins)
		p->x = p->x + 1;
	g_thief = "./images/thief-left.xpm";
}

void	move_right(char **map, t_Player *p)
{
	if (map[p->y][p->x - 1] != '1' && map[p->y][p->x - 1] != 'E')
		p->x = p->x - 1;
	else if (map[p->y][p->x - 1] == 'E' && g_coins == g_total_coins)
		p->x = p->x - 1;
	g_thief = "./images/thief-right.xpm";
}

int	validate_component(int p, int e)
{
	if (e < 1 || g_total_coins < 1 || p != 1)
		return (0);
	return (1);
}
