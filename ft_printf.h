/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricguerr <ricguerr@student.42adel.org.au>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 06:28:38 by ricguerr          #+#    #+#             */
/*   Updated: 2024/12/15 07:41:43 by ricguerr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int	ft_printf(const char *format, ...);
int	ft_handle_conversions(char specifier, va_list *args);
int	ft_print_char(int c);
int	ft_print_string(char *str);
int	ft_print_pointer(void *ptr);
int	ft_print_number(int nb);
int	ft_print_unsigned(unsigned int nb);
int	ft_print_hexadecimal(unsigned int nb);
int	ft_print_hexadecimal_upper(unsigned int nb);

#endif // FT_PRINTF_H
