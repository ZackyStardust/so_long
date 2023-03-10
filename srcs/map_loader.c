/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_loader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpereira <fpereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 18:21:24 by fpereira          #+#    #+#             */
/*   Updated: 2023/01/19 11:01:11 by fpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

t_list	**map(void)
{
	static t_list	*map;

	return (&map);
}

char	***amap(void)
{
	static char	**map;

	return (&map);
}

void	matrix_map(void)
{
	t_list	*temp_map;
	int		y;

	y = 0;
	temp_map = (*map());
	(*amap()) = (char **)malloc(sizeof(char *) * (ft_lstsize(temp_map) + 1));
	if ((*amap()) == NULL)
	{
		ft_lstclear(map());
		exit(0);
	}
	while (temp_map)
	{
		(*amap())[y] = temp_map->content;
		temp_map = temp_map->next;
		y++;
	}
	(*amap())[y] = NULL;
}

void	map_checker(void)
{
	if ((*map()) == NULL)
		error("Error\nThe map is empty!\n");
	else if (check_map_build() == -1)
		error("Error\nThe map is not correctly formatated!\n");
	else if (map_len() == -1)
		error("Error\nThe map is not rectangular!\n");
	else if (check_top_bot() == -1 || check_border() == -1)
		error("Error\nThe map is not correctly closed!\n");
	else
		check_elements();
}
