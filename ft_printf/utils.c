/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sekahram <sekahram@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 14:51:59 by sekahram          #+#    #+#             */
/*   Updated: 2022/08/19 19:15:46 by sekahram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *b)
{
	int	i;

	i = 0;
	if (!b)
		b = "(null)";
	while (b[i])
	{
		write(1, &b[i], 1);
		i++;
	}
	return (i);
}

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putnbr(long int n)
{
	int	len;

	len = 0;
	if (n < 0)
	{
		len += write(1, "-", 1);
		n = n * -1;
	}
	if (n > 9)
	{
		len += ft_putnbr(n / 10);
		len += ft_putnbr(n % 10);
	}
	else if (n <= 9)
		len += ft_putchar(n + 48);
	return (len);
}

int	ft_hex(unsigned long int n, char flag)
{
	const char	value_l[] = "0123456789abcdef";
	const char	value_u[] = "0123456789ABCDEF";
	int			len;

	len = 0;
	if (n >= 16)
	{
		len += ft_hex(n / 16, flag);
		len += ft_hex(n % 16, flag);
	}
	else if (n < 16 && flag == 'x')
		len += write(1, &value_l[n % 16], 1);
	else if (n < 16 && flag == 'X')
		len += write(1, &value_u[n % 16], 1);
	return (len);
}
