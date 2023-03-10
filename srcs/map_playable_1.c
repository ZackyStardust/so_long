/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_playable_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpereira <fpereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 10:49:25 by fpereira          #+#    #+#             */
/*   Updated: 2023/01/25 11:13:42 by fpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

int	**checked_alloc(t_widlen w)
{
	int	**checked;
	int	i;

	checked = (int **)malloc(sizeof(int *) * w.x);
	if (!checked)
		return (0);
	i = 0;
	while (i < w.x)
	{
		checked[i] = (int *)ft_calloc(w.y, sizeof(int));
		if (!checked[i])
			return (0);
		i++;
	}
	return (checked);
}

int	safety(int x, int y, t_widlen w)
{
	if ((x >= 0 && x < w.x) && (y >= 0 && y < w.y))
		return (1);
	return (0);
}

/* The dir(directions) below, in order: up, down, left, right. */

int	check_path_c(int **checked2, t_widlen w, int **checked_c, int dir)
{
	if (safety (w.c_x, w.c_y, w) && ((*amap ())[w.c_x][w.c_y] != '1' &&
		(*amap ())[w.c_x][w.c_y] != 'E') && !checked2[w.c_x][w.c_y])
	{
		checked2[w.c_x][w.c_y] = 1;
		if ((*amap())[w.c_x][w.c_y] == 'C')
		{
			if (!checked_c[w.c_x][w.c_y])
				return (checked_c[w.c_x][w.c_y] = 1);
		}
		dir = check_path_c(checked2, wm(w.c_x, w.c_y - 1, w), checked_c, 0);
		if (dir)
			return (1);
		dir = check_path_c(checked2, wm(w.c_x, w.c_y + 1, w), checked_c, 0);
		if (dir)
			return (1);
		dir = check_path_c(checked2, wm(w.c_x - 1, w.c_y, w), checked_c, 0);
		if (dir)
			return (1);
		dir = check_path_c(checked2, wm(w.c_x + 1, w.c_y, w), checked_c, 0);
		if (dir)
			return (1);
	}
	return (0);
}

t_widlen	widlen_fill(t_widlen w)
{
	int	x;
	int	y;

	x = 0;
	while ((*amap())[x])
		x++;
	y = 0;
	while ((*amap())[0][y])
		y++;
	w.y = y - 1;
	w.x = x;
	return (w);
}

int	path_playable(int x, int y, t_widlen w, int **checked)
{
	int	is_valid;

	is_valid = 0;
	while (x < w.x)
	{
		y = 0;
		while (y < w.y)
		{
			if ((*amap())[x][y] == 'P')
			{
				if (!checked[x][y])
				{
					if (map_ccounter() == possible_collectibles(x, y, w)
						&& check_path_e(x, y, checked, w))
					{
						is_valid = 1;
						break ;
					}
				}
			}
			y++;
		}
		x++;
	}
	return (is_valid);
}
