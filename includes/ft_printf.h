/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                    	                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpereira <fpereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 11:11:48 by fpereira          #+#    #+#             */
/*   Updated: 2022/04/19 16:22:05 by fpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>

/* Structs */
typedef struct s_data_ft
{
	int	i;
	int	c;
	int	a;
}				t_data_ft;

/* Main */

int		ft_printf(const char *str, ...);

/* Main Utils */

int		ft_printer(char *str, va_list ap, t_data_ft dt);
int		ft_printf_bases(char *str, va_list ap, int c, int i);

/* Extra Utils*/

int		ft_putchar_pf(char s, int c);
int		ft_putstr_pf(char *s, int c);
int		ft_putnbr_pf(int n, int c);
int		ft_nbr_len(long int nb, int base);
int		ft_pointer(unsigned long n, int c);
char	*ft_strdup_pf(char *str);
char	*ft_itoa_base(long int value, int base);
char	*ft_itoa_base_lower(long int value, int base);
char	*ft_tolower(const char *str);

#endif