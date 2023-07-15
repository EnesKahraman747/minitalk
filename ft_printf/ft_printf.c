/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sekahram <sekahram@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 13:27:48 by sekahram          #+#    #+#             */
/*   Updated: 2022/08/18 15:44:20 by sekahram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_control(va_list list, char type)
{
	int	len;	

	len = 0;
	if (type == 'c')
		len += ft_putchar(va_arg(list, int));
	else if (type == 's')
		len += ft_putstr(va_arg(list, char *));
	else if (type == 'd' || type == 'i')
		len += ft_putnbr(va_arg(list, int));
	else if (type == 'p')
	{
		len += write(1, "0x", 2);
		len += ft_hex(va_arg(list, unsigned long int), 'x');
	}
	else if (type == 'u')
		len += ft_putnbr(va_arg(list, unsigned int));
	else if (type == 'x')
		len += ft_hex(va_arg(list, unsigned int), 'x');
	else if (type == 'X')
		len += ft_hex(va_arg(list, unsigned int), 'X');
	else if (type == '%')
		len += write(1, "%", 1);
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list	variable;
	int		i;
	int		len;

	va_start(variable, str);
	len = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			len += ft_control(variable, str[++i]);
			i++;
		}
		else if (str[i] != '%')
		{
			len += write(1, &str[i], 1);
			i++;
		}
	}
	va_end(variable);
	return (len);
}
