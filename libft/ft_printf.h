/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akunegel <akunegel@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 14:26:16 by akunegel          #+#    #+#             */
/*   Updated: 2023/07/31 14:13:06 by akunegel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include "libft.h"

int		ft_touille(int nb);
int		ft_d(unsigned int nb);
int		ft_s(char *str);
int		ft_type(va_list test, const char type);
int		ft_printf(const char *str, ...);
int		ft_pourcent(void);
int		ft_putchar(char c);
int		ft_hexa_min(unsigned long long nb);
int		ft_hex_maj(unsigned int nb);
int		ft_du(int nb);
int		ft_c(char c);
void	ft_putstr_fd(char *s, int fd);

#endif