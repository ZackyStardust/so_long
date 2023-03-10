/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpereira <fpereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 18:09:28 by fpereira          #+#    #+#             */
/*   Updated: 2023/01/23 10:35:41 by fpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

t_image	image_mkr(char *path)
{
	t_image	img;

	img.img = mlx_xpm_file_to_image((*program()),
			path, &img.size, &img.size);
	return (img);
}

t_sprite	spriter(void)
{
	t_sprite	sprites;

	sprites.wall = image_mkr(S_WALL);
	sprites.floor = image_mkr(S_FLOOR);
	sprites.gem0 = image_mkr(S_GEM_0);
	sprites.gem1 = image_mkr(S_GEM_1);
	sprites.gem2 = image_mkr(S_GEM_2);
	sprites.gem3 = image_mkr(S_GEM_3);
	sprites.gem4 = image_mkr(S_GEM_4);
	sprites.gem5 = image_mkr(S_GEM_5);
	sprites.exit_close = image_mkr(S_EXIT_CLOSE);
	sprites.exit_open = image_mkr(S_EXIT_OPEN);
	sprites.player_l = image_mkr(S_PLAYER_L);
	sprites.player_r = image_mkr(S_PLAYER_R);
	sprites.player_u = image_mkr(S_PLAYER_U);
	sprites.player_d = image_mkr(S_PLAYER_D);
	sprites.enemy = image_mkr(S_ENEMY);
	return (sprites);
}

void	printer(t_sprite sprites, int keycode, t_map *map)
{
	char	*step;

	step = NULL;
	print_walls(sprites);
	print_elements(sprites);
	print_player(sprites, keycode);
	step = ft_itoa(map->steps);
	mlx_string_put((*program()), (*window()),
		16, 16, 0x00FFFFFF, step);
	free(step);
}
