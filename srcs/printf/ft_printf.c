/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpereira <fpereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 10:51:46 by fpereira          #+#    #+#             */
/*   Updated: 2023/01/19 11:18:44 by fpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int	ft_printf(const char *str, ...)
{
	va_list		ap;
	t_data_ft	dt;

	dt.i = 0;
	dt.c = 0;
	va_start(ap, str);
	if (!str)
		return (0);
	while (str[dt.i])
	{
		if (str[dt.i] == '%')
		{
			dt.c = ft_printer((char *)str, ap, dt);
			dt.i++;
		}
		else
		{
			dt.a = write (1, &str[dt.i], 1);
			(void)dt.a;
			dt.c++;
		}
	dt.i++;
	}
	va_end(ap);
	return (dt.c);
}

int	ft_printer(char *str, va_list ap, t_data_ft dt)
{	
	dt.i++;
	if (str[dt.i] == 's')
		dt.c = ft_putstr_pf(va_arg(ap, char *), dt.c);
	else if (str[dt.i] == 'd' || str[dt.i] == 'i')
		dt.c = ft_putnbr_pf(va_arg(ap, int), dt.c);
	else if (str[dt.i] == 'c')
	{
		dt.c = ft_putchar_pf(va_arg(ap, int), dt.c);
	}
	else if (str[dt.i] == '%')
	{
		dt.a = write(1, "%", 1);
		(void)dt.a;
		dt.c++;
	}
	else if (str[dt.i] == 'x' || str[dt.i] == 'X'
		|| str[dt.i] == 'p' || str[dt.i] == 'u')
		dt.c = ft_printf_bases(str, ap, dt.c, dt.i);
	return (dt.c);
}

int	ft_printf_bases(char *str, va_list ap, int c, int i)
{
	char	*changed;

	if (str[i] == 'X')
	{
		changed = ft_itoa_base(va_arg(ap, unsigned int), 16);
		c = ft_putstr_pf(changed, c);
		free(changed);
	}
	else if (str[i] == 'x')
	{
		changed = ft_itoa_base_lower(va_arg(ap, unsigned int), 16);
		c = ft_putstr_pf(changed, c);
		free(changed);
	}
	else if (str[i] == 'u')
	{
		changed = ft_itoa_base(va_arg(ap, unsigned int), 10);
		c = ft_putstr_pf(changed, c);
		free(changed);
	}
	else if (str[i] == 'p')
	{
		c = ft_pointer(va_arg(ap, unsigned long), c);
	}
	return (c);
}
