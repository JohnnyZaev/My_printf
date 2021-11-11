/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvarys <gvarys@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 18:56:43 by gvarys            #+#    #+#             */
/*   Updated: 2021/11/11 15:24:02 by gvarys           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	mini_if(t_print_info *info, int *number)
{
	info->total_length += write(1, "-", 1);
	*number = 147483648;
	if (info->width > 0 && !info->dash)
		width_full(info, info->zero_padding);
	if (info->precision > 0)
		precision_full(info);
	info->total_length += write(1, "2", 1);
}

void	if_if(t_print_info *info, int *number)
{
	if (*number == -2147483648)
	{
		mini_if(info, number);
	}
	else if (*number < 0)
	{
		if (info->width > 0 && !info->dash && !info->zero_padding)
			width_full(info, info->zero_padding);
		if (info->width > 0 && !info->dash && info->zero_padding)
		{
			if (!info->point)
			{
				info->total_length += write(1, "-", 1);
				width_full(info, info->zero_padding);
			}
			else
			{
				width_full(info, 0);
				info->total_length += write(1, "-", 1);
			}
		}
		else 
			info->total_length += write(1, "-", 1);
		if (info->precision > 0)
			precision_full(info);
		*number *= -1;
	}
	else
	{
		if (info->width > 0 && !info->dash && !info->point)
			width_full(info, info->zero_padding);
		else if (info->width > 0 && !info->dash && info->point)
		{
				width_full(info, 0);
		}
		if (info->precision > 0)
			precision_full(info);
	}
}
