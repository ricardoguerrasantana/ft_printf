/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricguerr <ricguerr@student.42adel.org.au>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 04:49:03 by ricguerr          #+#    #+#             */
/*   Updated: 2024/12/15 05:22:24 by ricguerr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_number(int i)
{
	int	len;

	len = 0;
	if (i < 0)
		len += write(1, "-", 1);
	if (i >= -9 && i < 0)
		len += ft_print_number(-i);
	if (i >= 0 && i <= 9)
		len += write(1, (char []){'0' + i}, 1);
	if (i < -9)
	{
		len += ft_print_number(-(i / 10));
		len += ft_print_number(-(i % 10));
	}
	if (i > 9)
	{
		len += ft_print_number(i / 10);
		len += ft_print_number(i % 10);
	}
	return (len);
}
