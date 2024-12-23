/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricguerr <ricguerr@student.42adel.org.au>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 06:55:32 by ricguerr          #+#    #+#             */
/*   Updated: 2024/12/15 06:55:43 by ricguerr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_unsigned(unsigned int nb)
{
	int	len;

	len = 0;
	if (nb <= 9)
		len += write(1, (char []){'0' + nb}, 1);
	else
	{
		len += ft_print_unsigned(nb / 10);
		len += ft_print_unsigned(nb % 10);
	}
	return (len);
}
