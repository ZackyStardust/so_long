/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_mover.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpereira <fpereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 18:41:22 by fpereira          #+#    #+#             */
/*   Updated: 2023/01/23 10:55:16 by fpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

t_map	*open_exits(t_map *map, int key)
{
	int	a;
	int	aa;

	a = 0;
	while ((map->map)[a])
	{
		aa = 0;
		while ((map->map)[a][aa])
		{
			if ((map->map)[a][aa] == 'E')
				(map->map)[a][aa] = 'e';
			aa++;
		}
		a++;
	}
	printer(map->sprites, key, map);
	return (map);
}

int	get_items(t_map *map)
{
	int	a;
	int	aa;
	int	items;

	a = 0;
	items = 0;
	while ((map->map)[a])
	{
		aa = 0;
		while ((map->map)[a][aa])
		{
			if ((map->map)[a][aa] == 'C')
				items++;
			aa++;
		}
		a++;
	}
	return (items);
}

int	refresh_position(int new_y, int new_x, t_map *map, int key)
{
	static int	items;
	int			x;
	int			y;

	items = get_items(map);
	x = (*player_coord('x'));
	y = (*player_coord('y'));
	if ((map->map)[y + new_y][x + new_x] != '1'
		&& (map->map)[y + new_y][x + new_x] != 'E')
	{
		if ((map->map)[y + new_y][x + new_x] == 'C')
			items--;
		if ((map->map)[y + new_y][x + new_x] == 'e'
			|| (map->map)[y + new_y][x + new_x] == 'X')
			leave(map);
		(map->map)[y + new_y][x + new_x] = 'P';
		(map->map)[y][x] = '0';
		(*player_coord('x')) = x + new_x;
		(*player_coord('y')) = y + new_y;
		if (items == 0)
			open_exits(map, key);
		return (1);
	}
	return (0);
}

int	move(int y, int x, t_map *map, int key)
{
	int	steps;

	steps = 0;
	steps += refresh_position(y, x, map, key);
	if (steps == 1)
	{
		mlx_clear_window((*program()), (*window()));
		printer(map->sprites, key, map);
	}
	return (steps);
}

void	make_moves(int keycode, t_map *map)
{
	if (keycode == KEY_W)
		move(-1, 0, map, keycode);
	else if (keycode == KEY_A)
		move(0, -1, map, keycode);
	else if (keycode == KEY_S)
		move(1, 0, map, keycode);
	else if (keycode == KEY_D)
		move(0, 1, map, keycode);
}
