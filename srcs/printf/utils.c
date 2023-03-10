/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpereira <fpereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 12:18:39 by fpereira          #+#    #+#             */
/*   Updated: 2023/01/19 11:02:33 by fpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int	ft_putchar_pf(char s, int c)
{
	int	a;

	a = write(1, &s, 1);
	(void)a;
	c++;
	return (c);
}

int	ft_putstr_pf(char *s, int c)
{
	int	i;
	int	a;

	i = 0;
	if (s == NULL)
	{
		a = write(1, "(null)", 6);
		c += 6;
		(void)a;
		return (c);
	}
	while (s[i] != '\0')
	{
		a = write (1, &s[i], 1);
		c++;
		i++;
	}
	(void)a;
	return (c);
}

int	ft_putnbr_pf(int n, int c)
{
	unsigned int	p;
	int				a;

	if (n < 0)
	{
		p = (unsigned int)(-n);
		a = write(1, "-", 1);
		c++;
	}
	else
		p = (unsigned int)n;
	if (p >= 10)
	{
		c = ft_putnbr_pf(p / 10, c);
		c = ft_putnbr_pf(p % 10, c);
	}
	else
	{
		p += 48;
		a = write(1, &p, 1);
		c++;
	}
	(void)a;
	return (c);
}

char	*ft_tolower(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			((unsigned int *)str)[i] += 32;
		i++;
	}
	return ((char *)str);
}

int	ft_pointer(unsigned long n, int c)
{
	char	*str;

	if (n == 0)
		c = ft_putstr_pf("0x0", c);
	else if (n != 0)
	{
		c = ft_putstr_pf("0x", c);
		str = ft_itoa_base_lower(n, 16);
		c = ft_putstr_pf(str, c);
		free (str);
	}
	return (c);
}
