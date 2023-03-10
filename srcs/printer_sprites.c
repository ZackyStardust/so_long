/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer_sprites.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpereira <fpereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 18:20:14 by fpereira          #+#    #+#             */
/*   Updated: 2023/01/25 11:14:29 by fpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	print_player(t_sprite sprites, int input)
{
	if (input == KEY_A)
		mlx_put_image_to_window((*program()), (*window()),
			sprites.player_l.img, (*player_coord('x')) * 64,
			(*player_coord('y')) * 64);
	else if (input == KEY_W)
		mlx_put_image_to_window((*program()), (*window()),
			sprites.player_u.img, (*player_coord('x')) * 64,
			(*player_coord('y')) * 64);
	else if (input == KEY_S)
		mlx_put_image_to_window((*program()), (*window()),
			sprites.player_d.img, (*player_coord('x')) * 64,
			(*player_coord('y')) * 64);
	else if (input == KEY_D)
		mlx_put_image_to_window((*program()), (*window()),
			sprites.player_r.img, (*player_coord('x')) * 64,
			(*player_coord('y')) * 64);
}

void	print_elements(t_sprite sprites)
{
	t_widlen	xyc;

	xyc.c_x = 0;
	xyc.y = 0;
	while ((*amap())[xyc.y])
	{
		xyc.x = 0;
		while ((*amap())[xyc.y][xyc.x] != '\n')
		{
			if ((*amap())[xyc.y][xyc.x] == 'C')
				xyc = collectible_flipper(xyc, sprites);
			else if ((*amap())[xyc.y][xyc.x] == 'E')
				mlx_put_image_to_window((*program()), (*window()),
					sprites.exit_close.img, xyc.x * 64, xyc.y * 64);
			else if ((*amap())[xyc.y][xyc.x] == 'e')
				mlx_put_image_to_window((*program()), (*window()),
					sprites.exit_open.img, xyc.x * 64, xyc.y * 64);
			else if ((*amap())[xyc.y][xyc.x] == 'X')
				mlx_put_image_to_window((*program()), (*window()),
					sprites.enemy.img, xyc.x * 64, xyc.y * 64);
			xyc.x++;
		}
		xyc.y++;
	}
}

t_widlen	collectible_flipper(t_widlen xyc, t_sprite sprites)
{
	if (xyc.c_x == 0)
		mlx_put_image_to_window((*program()), (*window()),
			sprites.gem0.img, xyc.x * 64, xyc.y * 64);
	if (xyc.c_x == 1)
		mlx_put_image_to_window((*program()), (*window()),
			sprites.gem1.img, xyc.x * 64, xyc.y * 64);
	if (xyc.c_x == 2)
		mlx_put_image_to_window((*program()), (*window()),
			sprites.gem2.img, xyc.x * 64, xyc.y * 64);
	if (xyc.c_x == 3)
		mlx_put_image_to_window((*program()), (*window()),
			sprites.gem3.img, xyc.x * 64, xyc.y * 64);
	if (xyc.c_x == 4)
		mlx_put_image_to_window((*program()), (*window()),
			sprites.gem4.img, xyc.x * 64, xyc.y * 64);
	if (xyc.c_x >= 5)
	{
		mlx_put_image_to_window((*program()), (*window()),
			sprites.gem5.img, xyc.x * 64, xyc.y * 64);
	xyc.c_x = -1;
	}
	xyc.c_x++;
	return (xyc);
}

void	print_walls(t_sprite sprites)
{
	int		x;
	int		y;

	y = -1;
	while ((*amap())[++y])
	{
		x = -1;
		while ((*amap())[y][++x])
		{
			if ((*amap())[y][x] == '1')
				mlx_put_image_to_window((*program()), (*window()),
					sprites.wall.img, x * 64, y * 64);
			else
				mlx_put_image_to_window((*program()), (*window()),
					sprites.floor.img, x * 64, y * 64);
		}
	}
}
