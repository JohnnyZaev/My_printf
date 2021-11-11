/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvarys <gvarys@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 11:11:37 by gvarys            #+#    #+#             */
/*   Updated: 2021/11/11 10:14:23 by gvarys           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_print_info
{
	va_list	args;
	int		width;
	int		precision;
	int		hex_size;
	int		zero_padding;
	int		point;
	int		dash;
	int		total_length;
	int		sign;
	int		is_zero;
	int		percent;
	int		space;
	int		hash;
}	t_print_info;

int				ft_printf(const char *format, ...);
int				ft_putstr(char *s, t_print_info *info);
void			print_char(t_print_info *info);
void			print_str(t_print_info *info);
void			print_pointer(t_print_info *info);
void			PNB(unsigned long long number, char x, t_print_info *info);
void			print_number(t_print_info *info);
void			ft_putnbr(int n, t_print_info *info);
void			ft_putunsnbr(unsigned int n, t_print_info *info);
void			print_unsigned(t_print_info *info);
void			print_hexup(t_print_info *info);
void			print_hexal(t_print_info *info);
int				check_wp(t_print_info *info, const char *format, int count);
int				check_wparg(t_print_info *info, const char *format, int count);
size_t			ft_strlen(const char *str);
void			width_full(t_print_info *info, int flag);
int				ft_nlen(int n);
unsigned int	ft_unlen(unsigned int n);
void			ft_scannbrbase(unsigned long long number, t_print_info *info);
void			precision_full(t_print_info *info);
int				check_format(const char *format, int count);
int				check_format1(const char *format, int count);
int				check_format2(const char *format, int count);
int				IFP(t_print_info *info, const char *format, int count);
int				IFNP(t_print_info *info, const char *format, int count);
void			mini_if(t_print_info *info, int *number);
void			if_if(t_print_info *info, int *number);
void			print_percent(t_print_info *info);

#endif