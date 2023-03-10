/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_playable_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpereira <fpereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 14:14:17 by fpereira          #+#    #+#             */
/*   Updated: 2023/01/25 11:14:05 by fpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

int	check_path_e(int x, int y, int **checked, t_widlen widlen)
{
	int	dir;

	while (safety (x, y, widlen) && (*amap ())[x][y] != '1' && !checked[x][y])
	{
		checked[x][y] = 1;
		if ((*amap())[x][y] == 'E')
		{
			return (1);
		}
		dir = check_path_e(x, y - 1, checked, widlen);
		if (dir)
			return (1);
		dir = check_path_e(x, y + 1, checked, widlen);
		if (dir)
			return (1);
		dir = check_path_e(x - 1, y, checked, widlen);
		if (dir)
			return (1);
		dir = check_path_e(x + 1, y, checked, widlen);
		if (dir)
			return (1);
	}
	return (0);
}

int	precheck_path_e(int x, int y, t_widlen widlen)
{
	int	**checked;
	int	is_valid;

	checked = checked_alloc(widlen);
	if (!checked)
		return (0);
	is_valid = check_path_e(x, y, checked, widlen);
	checked_free (checked, widlen);
	return (is_valid);
}

int	possible_collectibles(int x, int y, t_widlen widlen)
{
	int	**checked2;
	int	**checked_c;
	int	ccount;

	ccount = 0;
	checked2 = checked_alloc(widlen);
	checked_c = checked_alloc(widlen);
	if (!checked2)
		return (0);
	widlen.c_x = x;
	widlen.c_y = y;
	while (check_path_c(checked2, widlen, checked_c, 0))
	{
		ccount++;
		checked2 = checked_reset(checked2, widlen);
	}
	checked_free (checked2, widlen);
	checked_free (checked_c, widlen);
	return (ccount);
}
