/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpereira <fpereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 17:43:02 by fpereira          #+#    #+#             */
/*   Updated: 2023/01/27 14:29:11 by fpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

int	key(int keycode, t_map *map)
{
	static int	rotation;

	if ((keycode == KEY_W || keycode == KEY_A
			|| keycode == KEY_S || keycode == KEY_D) && keycode == rotation)
	{
		make_moves(keycode, map);
		map->steps++;
		printer(map->sprites, keycode, map);
	}
	else if (keycode == KEY_W || keycode == KEY_A
		|| keycode == KEY_S || keycode == KEY_D)
	{
		rotation = player_rotate(keycode);
		printer(map->sprites, keycode, map);
	}
	else if (keycode == KEY_ESC)
		leave(map);
	return (0);
}

int	mouse(int keycode)
{
	if (keycode)
		printf("%d\n", keycode);
	return (0);
}

int	main(int argc, char **argv)
{
	int		fd;
	t_map	map;

	fd = argcheck(argc, argv);
	map_reader(fd);
	map_checker();
	matrix_map();
	map_playable_checker();
	close (fd);
	start_player_coord();
	(*program()) = mlx_init();
	window_start();
	map.sprites = spriter();
	map.map = (*amap());
	map.steps = 0;
	printer(map.sprites, KEY_W, &map);
	mlx_loop_hook((*program()), enter_the_gotg, &map);
	mlx_key_hook((*window()), key, &map);
	mlx_mouse_hook((*window()), mouse, &map);
	mlx_hook((*window()), 17, 0, leave, &map);
	mlx_loop((*program()));
	return (END);
}
