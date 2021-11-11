/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prints.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvarys <gvarys@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 15:26:59 by gvarys            #+#    #+#             */
/*   Updated: 2021/11/11 16:56:25 by gvarys           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_unsigned(t_print_info *info)
{
	unsigned int	unsint;

	unsint = va_arg(info->args, unsigned int);
	if (info->precision > 0)
		info->precision -= ft_unlen(unsint);
	if (info->width > 0 && info->precision > 0)
		info->width -= ft_unlen(unsint) + info->precision;
	else if (info->width > 0)
		info->width -= ft_unlen(unsint);
	if (info->width > 0 && !info->dash && !info->point)
		width_full(info, info->zero_padding);
	else if (info->width > 0 && !info->dash && info->point)
		width_full(info, 0);
	if (info->precision > 0)
		precision_full(info);
	if (unsint == 0 && info->precision == 0 && info->point)
		if (info->width)
			info->total_length += write(1, " ", 1);
		else
			info->is_zero = 1;
	else
		ft_putunsnbr(unsint, info);
	if (info->width > 0 && info->dash)
		width_full(info, 0);
}

void	print_number(t_print_info *info)
{
	int	number;

	number = va_arg(info->args, int);
	if (info->precision > 0 && number >= 0)
		info->precision -= ft_nlen(number);
	else if (info->precision > 0 && number < 0)
		info->precision -= ft_nlen(number) - 1;
	if (info->width > 0 && info->precision > 0)
		info->width -= ft_nlen(number) + info->precision;
	else if (info->width > 0)
		info->width -= ft_nlen(number);
	if (info->sign && number >= 0)
		info->total_length += write(1, "+", 1);
	else if (info->space && number >= 0)
		info->total_length += write(1, " ", 1);
	if_if(info, &number);
	if (number == 0 && info->precision == 0 && info->point)
		if (info->width)
			info->total_length += write(1, " ", 1);
		else
			info->is_zero = 1;
	else
		ft_putnbr(number, info);
	if (info->width > 0 && info->dash)
		width_full(info, 0);
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
	if (info->width && str && info->precision < len && info->point)
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
