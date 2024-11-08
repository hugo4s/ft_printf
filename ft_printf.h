/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: husamuel <husamuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 21:19:34 by husamuel          #+#    #+#             */
/*   Updated: 2024/11/08 11:14:23 by husamuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

int		ft_printf(const char *format, ...);
int		ft_printf_char(char c);
int		ft_printf_string(char	*str);
int		ft_printf_pointer(void *ptr);
int		ft_printf_unsigned(unsigned int i);
int		ft_printf_hex(unsigned int n, char specifier);
int		ft_putstr(const char *str);
int		ft_putnbr(long nb);
void	ft_putnbr_hex(unsigned int n, int uppercase);

#endif
