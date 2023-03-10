/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpereira <fpereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 17:53:04 by fpereira          #+#    #+#             */
/*   Updated: 2023/01/23 12:21:55 by fpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

int	*enemy_coord(char choice)
{
	static int	x;
	static int	y;

	if (choice == 'x')
		return (&x);
	else if (choice == 'y')
		return (&y);
	else
		return (0);
}

void	start_enemy_coord(t_map *map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while ((*amap())[y] != NULL)
	{
		x = 0;
		while ((*amap())[y][x] != '\n')
		{
			if ((*amap())[y][x] == 'X')
			{
				(*enemy_coord('x')) = x;
				(*enemy_coord('y')) = y;
				enemy_move(*map);
			}
			x++;
		}
		y++;
	}
}

void	enemy_wait(t_map map, int y, int x)
{
	static int	ii;

	while (ii < 110000)
	{
		ii += rand() % 4;
		return ;
	}
	ii = 0;
	enemy_make_move(map, y, x);
}

void	enemy_move(t_map map)
{
	int	pos;

	pos = rand() % 4;
	if (pos == 0)
		enemy_wait(map, 0, 1);
	else if (pos == 1)
		enemy_wait(map, 0, -1);
	else if (pos == 2)
		enemy_wait(map, -1, 0);
	else if (pos == 3)
		enemy_wait(map, 1, 0);
	else
		return ;
}

int	enter_the_gotg(t_map *map)
{
	if (are_the_guardians_lost(*map) != TRUE)
		return (0);
	start_enemy_coord(map);
	return (0);
}
