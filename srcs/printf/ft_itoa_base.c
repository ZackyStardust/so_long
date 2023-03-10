/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpereira <fpereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 14:46:22 by fpereira          #+#    #+#             */
/*   Updated: 2023/01/19 11:18:43 by fpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int	ft_nbr_len(long int nb, int base)
{
	int	i;

	i = 0;
	if (nb < 0)
		nb *= -1;
	while (nb > 0)
	{
		nb /= base;
		i++;
	}
	return (i);
}

char	*ft_strdup_pf(char *str)
{
	int		i;
	int		len;
	char	*cpy;

	i = 0;
	len = 0;
	while (str[len] != '\0')
		len++;
	cpy = (char *)malloc(sizeof(char) * len + 1);
	if (cpy == NULL)
		return (NULL);
	while (str[i] != '\0')
	{
		cpy[i] = str[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}

char	*ft_itoa_base(long int value, int base)
{
	int		len;
	char	*hexadec;
	char	*ret;

	len = 0;
	hexadec = "0123456789ABCDEF";
	if (value == 0)
		return (ft_strdup_pf("0"));
	len = ft_nbr_len(value, base);
	ret = (char *)malloc(sizeof(char) * (len + 1));
	if (ret == NULL)
		return (NULL);
	ret[len] = '\0';
	while (len > 0)
	{
		ret[len - 1] = hexadec[value % base];
		value /= base;
		len--;
	}
	return (ret);
}

char	*ft_itoa_base_lower(long int value, int base)
{
	int		len;
	char	*hexadec;
	char	*ret;

	len = 0;
	hexadec = "0123456789abcdef";
	if (value == 0)
		return (ft_strdup_pf("0"));
	len = ft_nbr_len(value, base);
	ret = (char *)malloc(sizeof(char) * (len + 1));
	if (ret == NULL)
		return (NULL);
	ret[len] = '\0';
	while (len > 0)
	{
		ret[len - 1] = hexadec[value % base];
		value /= base;
		len--;
	}
	return (ret);
}
