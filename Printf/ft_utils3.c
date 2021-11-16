/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvarys <gvarys@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 18:56:43 by gvarys            #+#    #+#             */
/*   Updated: 2021/11/15 17:50:23 by gvarys           ###   ########.fr       */
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

void	giga_if(t_print_info *info, int *number)
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

void	if_if(t_print_info *info, int *number)
{
	if (*number == -2147483648)
	{
		mini_if(info, number);
	}
	else if (*number < 0)
	{
		giga_if(info, number);
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

int	else_str(char *s, t_print_info *info)
{
	int	i;

	i = 0;
	if (info->point)
	{
		while (s[i] != '\0' && i != info->precision)
		{
			write(1, &s[i], 1);
			i++;
		}
	}
	else
	{
		while (s[i] != '\0')
		{
			write(1, &s[i], 1);
			i++;
		}
	}
	return (i);
}

void	hexup_help(t_print_info	*info, unsigned int hexup)
{
	if (info->precision)
		info->precision -= info->hex_size;
	if (info->width > 0 && info->precision > 0)
		info->width -= info->hex_size + info->precision;
	else if (info->width > 0)
		info->width -= info->hex_size;
	if (info->width > 0 && !info->dash && !info->point)
		width_full(info, info->zero_padding);
	else if (info->width > 0 && !info->dash && info->point)
		width_full(info, 0);
	if (info->hash && hexup)
	{
		info->total_length += write(1, "0X", 2);
		info->width -= 2;
	}
	if (info->precision > 0)
		precision_full(info);
}
