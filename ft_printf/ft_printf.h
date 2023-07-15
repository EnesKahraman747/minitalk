/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sekahram <sekahram@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 14:42:23 by sekahram          #+#    #+#             */
/*   Updated: 2022/08/17 14:51:00 by sekahram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int	ft_putstr(char *b);
int	ft_putchar(char c);
int	ft_putnbr(long int n);
int	ft_hex(unsigned long int n, char flag);
int	ft_control(va_list list, char type);
int	ft_printf(const char *str, ...);

#endif
