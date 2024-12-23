/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricguerr <ricguerr@student.42adel.org.au>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 05:32:34 by ricguerr          #+#    #+#             */
/*   Updated: 2024/12/15 06:00:21 by ricguerr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		printed_chars;

	va_start(args, format);
	printed_chars = 0;
	while (*format)
	{
		if (*format == '%' && *(format + 1))
		{
			format++;
			printed_chars += ft_handle_conversions(*format, &args);
		}
		else
			printed_chars += write(1, format, 1);
		format++;
	}
	va_end(args);
	return (printed_chars);
}
