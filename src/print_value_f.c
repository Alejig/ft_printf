/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_value_f.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljigmon <aljigmon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 17:57:36 by aljigmon          #+#    #+#             */
/*   Updated: 2019/07/22 17:29:10 by aljigmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pow.h"
#include <unistd.h>
#include "init.h"
#include "size_nbr.h"

static int	print_intgr(unsigned long long int n, int reel)
{
	unsigned long long int		div;
	unsigned long long int		tempo;
	int							i;
	char						buffer[4096];

	div = 1;
	i = 0;
	tempo = n;
	while (tempo > 9)
	{
		div *= 10;
		tempo /= 10;
	}
	while (div > 0)
	{
		buffer[i] = n / div + 48;
		n = n - ((n / div) * div);
		div /= 10;
		i++;
	}
	return (reel ? write(1, buffer, i - 1) : write(1, buffer, i));
}

static void	ft_round(unsigned long long int *reel, long double nbr)
{
	if ((unsigned long long int)nbr % 2 == 0 && *reel % 10 > 5)
		*reel += 10 - *reel % 10;
	else if ((unsigned long long int)nbr % 2 != 0 && *reel % 10 >= 5)
		*reel += 10 - *reel % 10;
	else
		*reel = *reel - *reel % 10;
}

static int	print_reel(long double nbr, int preci)
{
	int						sum;
	char					buffer[4096];
	unsigned long long int	reel;
	unsigned long long int	size;

	sum = write(1, ".", 1);
	reel = (nbr - (unsigned long long int)nbr) * ft_pow(10, preci + 1);
	size = size_nbr((nbr - (unsigned long long int)nbr) * ft_pow(10, preci));
	if ((int)size < preci)
	{
		init(buffer, '0', 4096);
		if (reel % 10 >= 5)
			reel += 10 - reel % 10;
		else
			reel = reel - reel % 10;
		sum += write(1, buffer, preci - (int)size);
	}
	ft_round(&reel, nbr);
	sum += print_intgr(reel, reel == 0 ? 0 : 1);
	return (sum);
}

int			print_value_f(long double nbr, int precision)
{
	int	sum;

	sum = 0;
	if (nbr != nbr)
		return (sum += write(1, "nan", 3));
	else if (nbr == -1.0 / 0)
		return (sum += write(1, "-inf", 4));
	else if (nbr == 1.0 / 0)
		return (sum += write(1, "inf", 3));
	sum += print_intgr((unsigned long long int)nbr, 0);
	if (precision > 0)
		sum += print_reel(nbr, precision);
	return (sum);
}
