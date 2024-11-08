/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: husamuel <husamuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 11:03:20 by husamuel          #+#    #+#             */
/*   Updated: 2024/11/08 11:19:38 by husamuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_char(char c)
{
	return (write(1, &c, 1));
}

int	ft_printf_string(char	*str)
{
	int	len;

	if (!str)
	{
		if (write (1, "(null)", 6) == -1)
			return (-1);
		return (6);
	}
	len = 0;
	while (*str != '\0')
	{
		if (write(1, str, 1) == -1)
			return (-1);
		len++;
		str++;
	}
	return (len);
}

int	ft_printf_pointer(void *ptr)
{
	int	len;

	if (ft_putstr("0x") == -1)
		return (-1);
	len = 2;
	ft_putnbr_hex((unsigned long)ptr, 'x');
	return (len + 8);
}

int	ft_printf_unsigned(unsigned int i)
{
	return (ft_putnbr(i));
}

int	ft_printf_hex(unsigned int n, char specifier)
{
	int	count;
	int	uppercase;

	count = 0;
	if (specifier == 'X')
		uppercase = 1;
	if (n == 0)
	{
		if (write(1, "0", 1) == -1)
			return (-1);
		return (1);
	}
	ft_putnbr_hex(n, uppercase);
	return (count);
}
