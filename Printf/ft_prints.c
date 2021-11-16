/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prints.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvarys <gvarys@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 15:26:59 by gvarys            #+#    #+#             */
/*   Updated: 2021/11/15 18:10:27 by gvarys           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_unsigned(t_print_info *info)
{
	unsigned int	unsint;

	unsint = va_arg(info->args, unsigned int);
	if (info->precision == 0 && unsint == 0 && !info->width && info->point)
		info->is_zero = 1;
	else
	{
		unsint_if(unsint, info);
		if (unsint == 0 && info->precision == 0 && info->point)
		{
			if (info->width)
				info->total_length += write(1, " ", 1);
			else
				info->total_length += write(1, "0", 1);
		}
		else
			ft_putunsnbr(unsint, info);
		if (info->width > 0 && info->dash)
			width_full(info, 0);
	}
}

void	print_number(t_print_info *info)
{
	int	number;

	number = va_arg(info->args, int);
	if (info->precision == 0 && number == 0 && !info->width && info->point)
		info->is_zero = 1;
	else
	{
		number_if(number, info);
		if_if(info, &number);
		if (number == 0 && info->precision == 0 && info->point)
		{
			if (info->width)
				info->total_length += write(1, " ", 1);
			else
				info->total_length += write(1, "0", 1);
		}
		else
			ft_putnbr(number, info);
		if (info->width > 0 && info->dash)
			width_full(info, 0);
	}
}

void	print_char(t_print_info *info)
{
	char	c;

	c = va_arg(info->args, int);
	if (info->width)
		info->width -= 1;
	if (info->width > 0 && !info->dash)
		width_full(info, 0);
	info->total_length += write(1, &c, 1);
	if (info->width > 0 && info->dash)
		width_full(info, 0);
}

void	print_str(t_print_info *info)
{
	char	*str;
	int		len;

	str = va_arg(info->args, char *);
	if (str)
		len = ft_strlen(str);
	if (info->width && str && info->precision < len && info->point
		&& info->precision >= 0)
		info->width -= info->precision;
	else if (info->width && str)
		info->width -= len;
	if (!str && info->point && info->precision < 6)
		info->width -= info->precision;
	else if (!str)
		info->width -= 6;
	if (info->width > 0 && !info->dash)
		width_full(info, 0);
	info->total_length += ft_putstr(str, info);
	if (info->width > 0 && info->dash)
		width_full(info, 0);
}
