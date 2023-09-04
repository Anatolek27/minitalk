/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akunegel <akunegel@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 19:33:24 by akunegel          #+#    #+#             */
/*   Updated: 2023/07/31 14:12:17 by akunegel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>
#include <stdlib.h>

int	ft_nouille(unsigned int nb)
{
	int	i;

	i = 0;
	while (nb != 0)
	{
		i++;
		nb = nb / 10;
	}
	return (i);
}

char	*ft_itoa(unsigned int nb)
{
	int		taille;
	char	*dest;

	taille = ft_nouille(nb);
	dest = (char *)malloc(sizeof(char) + (taille + 1));
	if (!dest)
		return (NULL);
	dest[taille] = '\0';
	while (nb > 0)
	{
		dest[taille - 1] = nb % 10 + 48;
		nb = nb / 10;
		taille--;
	}
	return (dest);
}

int	ft_d(unsigned int nb)
{
	int		taille;
	char	*dest;

	taille = ft_nouille(nb);
	dest = ft_itoa(nb);
	if (nb == 0)
	{
		write (1, "0", 1);
		free(dest);
		return (1);
	}
	ft_putstr_fd(dest, 1);
	free(dest);
	return (taille);
}
