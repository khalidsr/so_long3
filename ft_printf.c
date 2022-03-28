/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sriyani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 20:05:46 by sriyani           #+#    #+#             */
/*   Updated: 2021/12/04 11:26:04 by sriyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

static int	ft_putstr(char *str)
{
	int	i;
	int	len;

	if (!str)
	{
		ft_putstr("(null)");
		return (6);
	}
	i = 0;
	len = 0;
	while (str[i])
	{
		write (1, &str[i], 1);
		len++;
		i++;
	}
	return (len);
}

static	int	ft_len(int nb)
{
	long int	num;
	int			len;

	num = nb;
	len = 0;
	if (num < 0)
	{
		num = num * (-1);
		len++;
	}
	if (num == 0)
		return (1);
	while (num > 0)
	{
		num /= 10;
		len++;
	}
	return (len);
}

static int	ft_putnbr(int nb)
{
	long int	nbr;

	nbr = nb;
	if (nbr < 0)
	{
		ft_putchar('-');
		nbr = nbr * (-1);
	}
	if (nbr >= 0 && nbr <= 9)
	{
		ft_putchar(nbr + '0');
	}
	else
	{
		ft_putnbr(nbr / 10);
		ft_putchar('0' + nbr % 10);
	}
	return (ft_len(nb));
}

int	ft_printfspesific(const char format, va_list args)
{
	if (format == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (format == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (format == 'd')
		return (ft_putnbr(va_arg(args, int)));
	return (1);
}

int	ft_printf(const char *format, ...)
{
	int		r;
	int		i;
	va_list	args;

	i = 0;
	r = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			r += ft_printfspesific(format[i], args);
		}
		else
		{
			r += ft_putchar(format[i]);
		}
		i++;
	}
	va_end(args);
	return (r);
}