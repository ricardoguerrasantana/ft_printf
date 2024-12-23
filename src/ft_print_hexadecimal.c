/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexadecimal.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricguerr <ricguerr@student.42adel.org.au>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 07:08:57 by ricguerr          #+#    #+#             */
/*   Updated: 2024/12/15 07:46:16 by ricguerr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hexadecimal(unsigned int nb)
{
	int	len;

	len = 0;
	if (nb <= 15)
		len += write(1, (char []){"0123456789abcdef"[nb]}, 1);
	else
	{
		len += ft_print_hexadecimal(nb / 16);
		len += ft_print_hexadecimal(nb % 16);
	}
	return (len);
}
