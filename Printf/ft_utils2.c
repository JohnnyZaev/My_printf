/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvarys <gvarys@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 18:44:48 by gvarys            #+#    #+#             */
/*   Updated: 2021/11/15 17:31:52 by gvarys           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *s, t_print_info *info)
{
	int		i;

	i = 0;
	if (!s)
	{
		if (!info->point)
			info->total_length += write(1, "(null)", 6);
		else
		{
			ft_putstr("(null)", info);
			info->total_length += info->precision;
		}
	}
	else
	{
		i = else_str(s, info);
	}
	return (i);
}

void	ft_scannbrbase(unsigned long long number, t_print_info *info)
{
	if (number > 15)
	{
		ft_scannbrbase(number / 16, info);
		ft_scannbrbase(number % 16, info);
	}
	else
		info->hex_size += 1;
}

void	PNB(unsigned long long number, char x, t_print_info *info)
{
	char	*base;

	if (x == 'x')
		base = "0123456789abcdef";
	if (x == 'X')
		base = "0123456789ABCDEF";
	if (number > 15)
	{
		PNB(number / 16, x, info);
		PNB(number % 16, x, info);
	}
	else
		info->total_length += write(1, &base[number], 1);
}

void	ft_putnbr(int n, t_print_info *info)
{
	if (n < 10)
	{
		n += 48;
		info->total_length += write(1, &n, 1);
	}
	else
	{
		ft_putnbr(n / 10, info);
		ft_putnbr(n % 10, info);
	}
}

void	ft_putunsnbr(unsigned int n, t_print_info *info)
{
	if (n < 10)
	{
		n += 48;
		info->total_length += write(1, &n, 1);
	}
	else
	{
		ft_putunsnbr(n / 10, info);
		ft_putunsnbr(n % 10, info);
	}
}
