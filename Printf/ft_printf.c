/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvarys <gvarys@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 11:11:57 by gvarys            #+#    #+#             */
/*   Updated: 2021/11/11 16:54:50 by gvarys           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

t_print_info	*initialise_info(t_print_info *info)
{
	info->width = 0;
	info->precision = 0;
	info->zero_padding = 0;
	info->point = 0;
	info->dash = 0;
	info->sign = 0;
	info->is_zero = 0;
	info->percent = 0;
	info->space = 0;
	info->hash = 0;
	return (info);
}

void	print_result(t_print_info *info, const char *type, int count)
{
	if (type[count] == 'c')
		print_char(info);
	if (type[count] == 's')
		print_str(info);
	if (type[count] == 'p')
		print_pointer(info);
	if (type[count] == 'd' || type[count] == 'i')
		print_number(info);
	if (type[count] == 'u')
		print_unsigned(info);
	if (type[count] == 'x')
		print_hexal(info);
	if (type[count] == 'X')
		print_hexup(info);
	if (type[count] == '%')
		print_percent(info);
}

int	print_format(t_print_info *info, const char *format, int count)
{
	while (check_format(format, count))
	{
		if (format[count] == '-')
			info->dash = 1;
		if (format[count] == '+')
			info->sign = 1;
		if (format[count] == ' ')
			info->space = 1;
		if (format[count] == '0' && !info->point)
			info->zero_padding = 1;
		if (format[count] == '#')
			info->hash = 1;
		if (format[count] == '.')
			info->point = 1;
		count++;
	}
	if (format[count] == '*')
		count = check_wparg(info, format, count);
	else
		count = check_wp(info, format, count);
	print_result(info, format, count);
	initialise_info(info);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	int				i;
	int				result;
	t_print_info	*info;

	info = (t_print_info *)malloc(sizeof(t_print_info));
	if (!info)
		return (-1);
	initialise_info(info);
	info->total_length = 0;
	va_start(info->args, format);
	i = -1;
	result = 0;
	while (format[++i])
	{
		if (format[i] == '%')
			i = print_format(info, format, ++i);
		else
			result += write(1, &format[i], 1);
	}
	va_end(info->args);
	result += info->total_length;
	free (info);
	return (result);
}

// int main(void)
// {
// 	int		a = -4;
// 	int		b = 0;
// 	char	c = 'a';
// 	int		d = 2147483647;
// 	int		e = -2147483648;
// 	int		f = 42;
// 	int		g = 25;
// 	int		h = 4200;
// 	int		i = 8;
// 	int		j = -12;
// 	int		k = 123456789;
// 	int		l = 0;
// 	int		m = -12345678;
// 	char	*n = "abcdefghijklmnop";
// 	char	*o = "-a";
// 	char	*p = "-12";
// 	char	*q = "0";
// 	char	*r = "%%";
// 	char	*s = "-2147483648";
// 	char	*t = "0x12345678";
// 	char	*u = "-0";

// 	ft_printf("{%1.d}\n", 0);
// 	printf("{%1.d}\n", 0);
// }