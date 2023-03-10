/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpereira <fpereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 18:14:29 by fpereira          #+#    #+#             */
/*   Updated: 2023/01/23 10:42:54 by fpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

int	*player_coord(char c)
{
	static int	x;
	static int	y;

	if (c == 'x')
		return (&x);
	else if (c == 'y')
		return (&y);
	else
		return (ERROR);
}

int	start_player_coord(void)
{
	int	x;
	int	y;

	y = 0;
	while ((*amap())[y] != NULL)
	{
		x = 0;
		while ((*amap())[y][x] != '\n')
		{
			if ((*amap())[y][x] == 'P')
			{
				(*player_coord('x')) = x;
				(*player_coord('y')) = y;
			}
			x++;
		}
		y++;
	}
	return (END);
}

int	player_rotate(int keycode)
{
	int	rotation;

	rotation = -1;
	if (keycode == KEY_W)
		rotation = KEY_W;
	else if (keycode == KEY_A)
		rotation = KEY_A;
	else if (keycode == KEY_S)
		rotation = KEY_S;
	else if (keycode == KEY_D)
		rotation = KEY_D;
	return (rotation);
}
