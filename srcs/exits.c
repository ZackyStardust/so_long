/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpereira <fpereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 17:05:03 by fpereira          #+#    #+#             */
/*   Updated: 2023/01/23 10:54:26 by fpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	error(char *error)
{
	ft_printf(error);
	ft_lstclear(map());
	exit(1);
}

void	clear(t_sprite sprites)
{
	ft_lstclear(map());
	free((*amap()));
	sprite_destroyer(sprites);
}

int	leave(t_map *map)
{
	clear(map->sprites);
	mlx_destroy_window((*program()), (*window()));
	mlx_destroy_display((*program()));
	free((*program()));
	exit(0);
	return (0);
}

int	extra_leave(char *error)
{
	ft_printf(error);
	free((*amap()));
	ft_lstclear(map());
	free((*program()));
	exit(1);
}

void	sprite_destroyer(t_sprite sprites)
{
	mlx_destroy_image((*program()), sprites.floor.img);
	mlx_destroy_image((*program()), sprites.wall.img);
	mlx_destroy_image((*program()), sprites.exit_close.img);
	mlx_destroy_image((*program()), sprites.exit_open.img);
	mlx_destroy_image((*program()), sprites.gem0.img);
	mlx_destroy_image((*program()), sprites.gem1.img);
	mlx_destroy_image((*program()), sprites.gem2.img);
	mlx_destroy_image((*program()), sprites.gem3.img);
	mlx_destroy_image((*program()), sprites.gem4.img);
	mlx_destroy_image((*program()), sprites.gem5.img);
	mlx_destroy_image((*program()), sprites.enemy.img);
	mlx_destroy_image((*program()), sprites.player_l.img);
	mlx_destroy_image((*program()), sprites.player_r.img);
	mlx_destroy_image((*program()), sprites.player_u.img);
	mlx_destroy_image((*program()), sprites.player_d.img);
}
