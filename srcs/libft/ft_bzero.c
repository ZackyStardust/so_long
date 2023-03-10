/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpereira <fpereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 11:14:18 by fpereira          #+#    #+#             */
/*   Updated: 2023/01/19 11:01:25 by fpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	ft_bzero(void *s, size_t len)
{
	size_t	n;

	n = 0;
	while (n < len)
	{
		((unsigned char *)s)[n] = 0;
		n++;
	}
}
