/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: husamuel <husamuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 11:07:00 by husamuel          #+#    #+#             */
/*   Updated: 2024/11/08 11:21:00 by husamuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(const char *str)
{
	int	len;

	len = 0;
	if (!str)
		return (-1);
	while (str[len] != '\0')
	{
		if (write(1, &str[len], 1) == -1)
			return (-1);
		len++;
	}
	return (len);
}

void	ft_putnbr_hex(unsigned int n, int uppercase)
{
	char	*hex_digits_lower;
	char	*hex_digits_upper;
	char	*hex_digits;

	hex_digits_lower = "0123456789abcdef";
	hex_digits_upper = "0123456789ABCDEF";
	if (uppercase)
		hex_digits = hex_digits_upper;
	else
		hex_digits = hex_digits_lower;
	if (n >= 16)
		ft_putnbr_hex(n / 16, uppercase);
	write(1, &hex_digits[n % 16], 1);
}

int	ft_putnbr(long nb)
{
	long		num;
	int			len;
	int			aux;

	len = 0;
	if (nb < 0)
	{
		if (write(1, "-", 1) == -1)
			return (-1);
		len += 1;
		nb *= -1;
	}
	num = nb % 10 + '0';
	if (nb > 9)
	{
		aux = ft_putnbr(nb / 10);
		if (aux == -1)
			return (-1);
		len += aux;
	}
	if (write(1, &num, 1) == -1)
		return (-1);
	len += 1;
	return (len);
}
