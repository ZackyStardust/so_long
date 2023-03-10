/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windowmaker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpereira <fpereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 18:39:01 by fpereira          #+#    #+#             */
/*   Updated: 2023/01/19 11:01:11 by fpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	**program(void)
{
	static void	*mlx;

	return (&mlx);
}

void	**window(void)
{
	static void	*mlx_window;

	return (&mlx_window);
}

t_wind	wsize(char **map)
{
	t_wind	window;
	int		x;
	int		y;

	y = 0;
	x = ft_strlen(map[y]) - 1;
	while (map[y])
		y++;
	window.x = x * 64;
	window.y = y * 64;
	return (window);
}

void	window_start(void)
{
	void	*mlx;
	t_wind	size_w;

	mlx = (*program());
	size_w = wsize((*amap()));
	(*window()) = mlx_new_window(mlx, size_w.x, size_w.y,
			"Infinity War: Courtship to Death");
}
