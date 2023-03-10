/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpereira <fpereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 14:39:03 by fpereira          #+#    #+#             */
/*   Updated: 2023/01/19 11:01:11 by fpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	check_elements(void)
{
	t_elements	elem;
	t_list		*temp;
	char		*content_temp;

	elem.c = 0;
	elem.e = 0;
	elem.p = 0;
	temp = (*map());
	while (temp->next != NULL)
	{
		content_temp = temp->next->content;
		while (*content_temp != '\n')
		{
			if (*content_temp == 'C')
				elem.c++;
			else if (*content_temp == 'E')
				elem.e++;
			else if (*content_temp == 'P')
				elem.p++;
			content_temp++;
		}
		temp = temp->next;
	}
	errors_elements(elem);
}

void	errors_elements(t_elements elem)
{
	if (elem.c == 0)
		error("Error\nThe map needs at least 1 collectible!\n");
	else if (elem.e == 0)
		error("Error\nThe map needs at least 1 exit!\n");
	else if (elem.p == 0)
		error("Error\nThe map needs at least 1 starting position!\n");
	else if (elem.p > 1)
		error("Error\nToo many starting positions! Use only 1.\n");
	else if (elem.e > 1)
		error("Error\nToo many exits! Use only 1.\n");
}
