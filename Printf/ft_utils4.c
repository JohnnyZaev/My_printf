/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvarys <gvarys@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 17:46:43 by gvarys            #+#    #+#             */
/*   Updated: 2021/11/15 18:22:25 by gvarys           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	hexal_help(t_print_info	*info, unsigned int hexal)
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
	if (info->hash && hexal)
	{
		info->total_length += write(1, "0x", 2);
		info->width -= 2;
	}
	if (info->precision > 0)
		precision_full(info);
}

void	number_if(int number, t_print_info *info)
{
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
}

void	unsint_if(unsigned int unsint, t_print_info *info)
{
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
}

void	wparg_help(t_print_info *info)
{
	int	percision;

	percision = va_arg(info->args, int);
	if (percision < 0)
	{
		info->precision = 0;
		info->point = 0;
	}
	else
		info->precision = percision;
}

int	IFP_help(t_print_info *info, const char *format, int count)
{	
	while (check_format1(format, count))
	{
		info->precision = (info->precision * 10) + (format[count] - 48);
		count++;
	}
	return (count);
}
