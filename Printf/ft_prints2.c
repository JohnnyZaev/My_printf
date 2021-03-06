/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prints2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvarys <gvarys@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 18:47:32 by gvarys            #+#    #+#             */
/*   Updated: 2021/11/15 17:49:52 by gvarys           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_pointer(t_print_info *info)
{
	unsigned long	pointer;

	pointer = va_arg(info->args, unsigned long);
	info->hex_size = 0;
	info->width -= 2;
	if (pointer != 0 || !info->point)
		ft_scannbrbase(pointer, info);
	if (info->width)
		info->width -= info->hex_size;
	if (info->width > 0 && !info->dash)
		width_full(info, info->zero_padding);
	info->total_length += write(1, "0x", 2);
	if (pointer != 0 || !info->point)
		PNB(pointer, 'x', info);
	if (info->width > 0 && info->dash)
		width_full(info, 0);
}

void	print_hexal(t_print_info *info)
{
	unsigned int	hexal;

	hexal = va_arg(info->args, unsigned int);
	info->hex_size = 0;
	ft_scannbrbase(hexal, info);
	if (info->precision == 0 && hexal == 0 && !info->width && info->point)
		info->is_zero = 1;
	else
	{
		hexal_help(info, hexal);
		if (hexal == 0 && info->precision == 0 && info->point)
		{
			if (info->width)
				info->total_length += write(1, " ", 1);
			else
				info->total_length += write(1, "0", 1);
		}
		else
			PNB(hexal, 'x', info);
		if (info->width > 0 && info->dash)
			width_full(info, 0);
	}
}

void	print_hexup(t_print_info *info)
{
	unsigned int	hexup;

	hexup = va_arg(info->args, unsigned int);
	info->hex_size = 0;
	ft_scannbrbase(hexup, info);
	if (info->precision == 0 && hexup == 0 && !info->width && info->point)
		info->is_zero = 1;
	else
	{
		hexup_help(info, hexup);
		if (hexup == 0 && info->precision == 0 && info->point)
		{
			if (info->width)
				info->total_length += write(1, " ", 1);
			else
				info->total_length += write(1, "0", 1);
		}
		else
			PNB(hexup, 'X', info);
		if (info->width > 0 && info->dash)
			width_full(info, 0);
	}
}

void	print_percent(t_print_info *info)
{
	if (info->width)
		info->width -= 1;
	if (info->width > 0 && !info->dash)
		width_full(info, info->zero_padding);
	info->total_length += write(1, "%", 1);
	if (info->width > 0 && info->dash)
		width_full(info, 0);
}
