/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricguerr <ricguerr@student.42adel.org.au>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 03:17:10 by ricguerr          #+#    #+#             */
/*   Updated: 2024/12/15 03:51:20 by ricguerr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_pointer(void *ptr)
{
	unsigned long	address;
	char			hex[17];
	int				len;
	int				i;
	int				start;

	if (!ptr)
		return (write(1, "0x0", 3));
	i = 15;
	address = (unsigned long)ptr;
	while (i >= 0)
	{
		hex[i] = "0123456789abcdef"[address % 16];
		address /= 16;
		i--;
	}
	hex[16] = '\0';
	start = 0;
	while (hex[start] == '0' && start < 15)
		start++;
	len = 0;
	len += write(1, "0x", 2);
	len += write(1, hex + start, 16 - start);
	return (len);
}
