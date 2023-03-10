/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpereira <fpereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 12:31:24 by fpereira          #+#    #+#             */
/*   Updated: 2023/01/25 10:46:56 by fpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	checked_free(int **checked, t_widlen widlen)
{
	int	x;

	x = 0;
	while (x < widlen.x)
	{
		free(checked[x]);
		x++;
	}
	free(checked);
}
