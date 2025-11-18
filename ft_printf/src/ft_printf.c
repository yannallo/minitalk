/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yallo <yallo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 11:32:03 by yallo             #+#    #+#             */
/*   Updated: 2022/12/19 13:36:05 by yallo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	check_arg(char c, va_list arg, int *count)
{
	long long unsigned int	tmp;

	if (c == 'c')
		ft_putchar(va_arg(arg, int), count);
	else if (c == 's')
		ft_putstr(va_arg(arg, char *), count);
	else if (c == 'p')
	{
		tmp = va_arg(arg, long long unsigned int);
		if (tmp == 0)
			return (ft_putstr("(nil)", count));
		ft_putstr("0x", count);
		ft_putnbr_base(tmp, "0123456789abcdef", count);
	}
	else if ((c == 'd' || c == 'i'))
		ft_putnbr(va_arg(arg, int), count);
	else if (c == 'u')
		ft_putnbr_base(va_arg(arg, unsigned int), "0123456789", count);
	else if (c == 'x')
		ft_putnbr_base(va_arg(arg, unsigned int), "0123456789abcdef", count);
	else if (c == 'X')
		ft_putnbr_base(va_arg(arg, unsigned int), "0123456789ABCDEF", count);
	else if (c == '%')
		ft_putchar('%', count);
}

int	ft_printf(const char *format, ...)
{
	int		count;
	size_t	i;
	va_list	arg;

	i = 0;
	count = 0;
	va_start(arg, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			check_arg(format[i], arg, &count);
		}
		else
			ft_putchar(format[i], &count);
		i++;
	}
	va_end(arg);
	return (count);
}
