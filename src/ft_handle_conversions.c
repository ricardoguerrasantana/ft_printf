/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_conversions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricguerr <ricguerr@student.42adel.org.au>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 05:31:29 by ricguerr          #+#    #+#             */
/*   Updated: 2024/12/15 07:42:12 by ricguerr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_handle_conversions(char specifier, va_list *args)
{
	if (specifier == 'c')
		return (ft_print_char(va_arg(*args, int)));
	if (specifier == 's')
		return (ft_print_string(va_arg(*args, char *)));
	if (specifier == 'p')
		return (ft_print_pointer(va_arg(*args, void *)));
	if (specifier == 'd' || specifier == 'i')
		return (ft_print_number(va_arg(*args, int)));
	if (specifier == 'u')
		return (ft_print_unsigned(va_arg(*args, unsigned int)));
	if (specifier == 'x')
		return (ft_print_hexadecimal(va_arg(*args, unsigned int)));
	if (specifier == 'X')
		return (ft_print_hexadecimal_upper(va_arg(*args, unsigned int)));
	else
		return (write(1, &specifier, 1));
}
