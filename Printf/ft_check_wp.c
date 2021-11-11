/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_wp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvarys <gvarys@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 17:59:36 by gvarys            #+#    #+#             */
/*   Updated: 2021/11/11 15:33:12 by gvarys           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	IFP(t_print_info *info, const char *format, int count)
{
	int	percision;

	if (format[count] == '.')
	{
		info->point = 1;
		count++;
		if (format[count] == '*')
		{
			percision = va_arg(info->args, int);
			if (percision < 0)
			{
				info->precision = 0;
				info->point = 0;
			}
			else
				info->precision = percision;
			count++;
		}
		else
		{
			while (check_format1(format, count))
			{
				info->precision = (info->precision * 10) + (format[count] - 48);
				count++;
			}
		}
	}
	return (count);
}

int	IFNP(t_print_info *info, const char *format, int count)
{
	int	percision;

	if (format[count] == '.')
	{
		info->point = 1;
		count++;
		if (format[count] == '*')
		{
			percision = va_arg(info->args, int);
			info->precision = percision;
			count++;
		}
		else
		{
			while (check_format1(format, count))
			{
				info->precision = (info->precision * 10) + (format[count] - 48);
				count++;
			}
		}
	}
	return (count);
}

int	check_wp(t_print_info *info, const char *format, int count)
{
	if (!info->point)
	{
		while (check_format2(format, count))
		{
			info->width = (info->width * 10) + (format[count] - 48);
			count++;
		}
		count = IFP(info, format, count);
	}
	else
	{
		while (check_format1(format, count))
		{
			info->precision = (info->precision * 10) + (format[count] - 48);
			count++;
		}
	}
	return (count);
}

int	check_wparg(t_print_info *info, const char *format, int count)
{
	int	width;
	int	percision;

	if (!info->point)
	{
		width = va_arg(info->args, int);
		if (width < 0)
		{
			info->dash = 1;
			width *= -1;
		}
		info->width = width;
		count++;
		count = IFNP(info, format, count);
	}
	else
	{
		percision = va_arg(info->args, int);
		if (percision < 0)
		{
			info->precision = 0;
			info->point = 0;
		}
		else
			info->precision = percision;
		count++;
	}
	return (count);
}
