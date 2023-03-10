/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpereira <fpereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 18:55:29 by fpereira          #+#    #+#             */
/*   Updated: 2023/01/27 14:28:34 by fpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	enemy_movement(t_sprite sprites)
{
	mlx_put_image_to_window((*program()), (*window()),
		sprites.floor.img, (*enemy_coord('x')) * 64,
		(*enemy_coord('y')) * 64);
	return ;
}

int	enemy_make_move(t_map map, int new_x, int new_y)
{
	t_widlen	w;

	w.x = (*enemy_coord('x'));
	w.y = (*enemy_coord('y'));
	if ((map.map)[w.y + new_y][w.x + new_x] == '1'
		|| (map.map)[w.y + new_y][w.x + new_x] == 'X'
		|| (map.map)[w.y + new_y][w.x + new_x] == 'C'
		|| (map.map)[w.y + new_y][w.x + new_x] == 'E'
		|| (map.map)[w.y + new_y][w.x + new_x] == 'e')
		return (1);
	else
	{
		enemy_movement(map.sprites);
		move_commit (map, new_x, new_y, w);
		return (1);
	}
	return (0);
}

int	are_the_guardians_lost(t_map map)
{
	int	x;
	int	y;

	y = 0;
	while (map.map[y])
	{
		x = 0;
		while (map.map[y][x] != '\n')
		{
			if (map.map[y][x] == 'X')
				return (TRUE);
			x++;
		}
		y++;
	}
	return (FALSE);
}

void	move_commit(t_map map, int new_x, int new_y, t_widlen w)
{
	if ((map.map)[w.y + new_y][w.x + new_x] == 'P')
		leave(&map);
	(map.map)[w.y + new_y][w.x + new_x] = 'X';
	(map.map)[w.y][w.x] = '0';
	(*enemy_coord('x')) = w.x + new_x;
	(*enemy_coord('y')) = w.y + new_y;
	mlx_put_image_to_window((*program()), (*window()),
		map.sprites.enemy.img, (*enemy_coord('x')) * 64,
		(*enemy_coord('y')) * 64);
}
