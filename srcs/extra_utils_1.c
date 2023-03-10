/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_utils_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpereira <fpereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 12:06:41 by fpereira          #+#    #+#             */
/*   Updated: 2023/01/25 10:54:03 by fpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

int	map_playable_checker(void)
{
	int			**checked;
	t_widlen	widlen;

	widlen = widlen_fill(widlen);
	checked = checked_alloc(widlen);
	if (!checked)
		return (0);
	if (path_playable(0, 0, widlen, checked) == 0)
	{
		checked_free(checked, widlen);
		extra_leave("Error\nThe map is unplayable!\n");
	}
	checked_free(checked, widlen);
	ft_printf("Map accepted!\n");
	return (0);
}

int	argcheck(int argc, char **argv)
{
	int	fd;

	if (argc != 2)
		error("Error\nInvalid use of program. Use only 1 argument (the map).\n");
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		error("Error\nInvalid file. It does not exist or cannot be read.\n");
	if (ft_strncmp(ft_strrchr(argv[1], '.'), ".ber", 4) != 0)
		error("Error\nInvalid map extension! Use only .ber files.\n");
	return (fd);
}

int	map_ccounter(void)
{
	int	ccount;
	int	x;
	int	y;

	x = 0;
	y = 0;
	ccount = 0;
	while ((*amap())[x])
	{
		y = 0;
		while ((*amap())[x][y])
		{
			if ((*amap())[x][y] == 'C')
				ccount++;
			y++;
		}
		x++;
	}
	return (ccount);
}

t_widlen	wm(int x, int y, t_widlen widlen)
{
	widlen.c_x = x;
	widlen.c_y = y;
	return (widlen);
}

int	**checked_reset(int **checked, t_widlen widlen)
{
	int	x;
	int	y;

	x = 0;
	while (x < widlen.x)
	{
		y = 0;
		while (y < widlen.y)
		{
		checked[x][y] = 0;
			y++;
		}
		x++;
	}
	return (checked);
}
