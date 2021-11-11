/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvarys <gvarys@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 17:51:36 by gvarys            #+#    #+#             */
/*   Updated: 2021/11/10 18:39:49 by gvarys           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_format(const char *format, int count)
{
	if (format[count] != 'c' && format[count] != 's' && format[count] != 'p'
		&& format[count] != 'd' && format[count] != 'i' && format[count] != 'u'
		&& format[count] != 'x' && format[count] != 'X' && format[count] != '%'
		&& format[count] != '*'
		&& !(format[count] >= '1' && format[count] <= '9'))
	{
		return (1);
	}
	return (0);
}

int	check_format1(const char *format, int count)
{
	if (format[count] != 'c' && format[count] != 's' && format[count] != 'p'
		&& format[count] != 'd' && format[count] != 'i' && format[count] != 'u'
		&& format[count] != 'x' && format[count] != 'X' && format[count] != '%'
		&& (format[count] >= '0' && format[count] <= '9'))
	{
		return (1);
	}
	return (0);
}

int	check_format2(const char *format, int count)
{
	if (format[count] != 'c' && format[count] != 's' && format[count] != 'p'
		&& format[count] != 'd' && format[count] != 'i' && format[count] != 'u'
		&& format[count] != 'x' && format[count] != 'X' && format[count] != '%'
		&& format[count] != '.'
		&& (format[count] >= '0' && format[count] <= '9'))
	{
		return (1);
	}
	return (0);
}
