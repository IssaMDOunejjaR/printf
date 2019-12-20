/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iounejja <iounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 15:33:50 by iounejja          #+#    #+#             */
/*   Updated: 2019/12/20 18:27:38 by iounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

int		g_count;
char	g_found;
int		g_justify;
int		g_point;
int		g_width;
int		g_precision;

int		ft_printf(const char *format, ...);
void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_putnbr(int nb);
int		ft_get_digit(const char *str, int i);
void	ft_hex(unsigned long p, char c);
int		ft_check_flags(const char *format, int index, va_list arg_list);
void	ft_flags(char c, va_list arg_list);
void	ft_string_flag(va_list arg_list);
void	ft_print_string(char *str, int l_str, int index);
int		ft_len_hex(unsigned long nb);
void	ft_print_spaces(int l_str, char c);
void	ft_hex_flags(char c, va_list arg_list);
void	ft_print_char(va_list arg_list);
void	ft_integer_flag(char c, va_list arg_list);
char	*ft_itoa_u(unsigned int n);
int		ft_is_flag(char c);
void	ft_print(int l_nbr, char c);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
int		ft_tolower(int c);
int		ft_toupper(int c);
char	*ft_itoa(int n);
int		ft_strlen(char const *s);

#endif
