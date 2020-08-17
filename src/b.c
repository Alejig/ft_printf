/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljigmon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 06:04:04 by aljigmon          #+#    #+#             */
/*   Updated: 2019/07/05 16:11:08 by aljigmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include <unistd.h>
#include "ft_strrev.h"

static int	print_value(unsigned long long int nbr)
{
	char	buffer[4096];
	char	*base2;
	int		i;

	i = 0;
	base2 = "01";
	while (nbr >= 1)
	{
		buffer[i] = base2[nbr % 2];
		i++;
		nbr /= 2;
	}
	ft_strrev(buffer, i - 1);
	write(1, buffer, i);
	return (i);
}

int			func_b(t_p *var)
{
	int						sum;
	unsigned long long int	*ptr;
	unsigned long long int	nbr;

	sum = 0;
	ptr = var->value;
	nbr = *ptr;
	if (nbr == 0)
		return (write(1, "0", 1));
	sum = print_value(nbr);
	return (sum);
}
