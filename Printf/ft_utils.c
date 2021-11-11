/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvarys <gvarys@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 18:41:33 by gvarys            #+#    #+#             */
/*   Updated: 2021/11/10 18:41:46 by gvarys           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_nlen(int n)
{
	int	len;

	len = 1;
	if (n == -2147483648)
		return (11);
	if (n < 0)
	{
		n *= -1;
		len++;
	}
	while (n > 9)
	{
		n /= 10;
		len++;
	}
	return (len);
}

unsigned int	ft_unlen(unsigned int n)
{
	unsigned int	len;

	len = 1;
	while (n > 9)
	{
		n /= 10;
		len++;
	}
	return (len);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

void	width_full(t_print_info *info, int flag)
{
	int	i;

	i = -1;
	if (!flag)
		while (++i < info->width)
			info->total_length += write(1, " ", 1);
	else
		while (++i < info->width)
			info->total_length += write(1, "0", 1);
}

void	precision_full(t_print_info *info)
{
	int	i;

	i = -1;
	while (++i < info->precision)
		info->total_length += write(1, "0", 1);
}
