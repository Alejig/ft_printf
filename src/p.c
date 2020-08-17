/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljigmon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 09:49:01 by aljigmon          #+#    #+#             */
/*   Updated: 2019/07/05 16:11:49 by aljigmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include <unistd.h>
#include "init.h"
#include "ft_strrev.h"
#include "shield_buffer.h"

static int		width(t_p *var, int size_digits)
{
	int		sum;
	char	buf[4096];

	sum = 0;
	init(buf, ' ', 4096);
	if (var->wd > 4096)
		sum += shield_buffer(buf, &var->wd);
	sum += write(1, buf, var->wd - size_digits < 0
			? 0 : var->wd - size_digits);
	return (sum);
}

static int		size_digits(unsigned long long int nbr)
{
	int		i;

	i = 2;
	while (nbr > 0)
	{
		nbr /= 16;
		i++;
	}
	return (i);
}

static int		print_value(unsigned long long nbr, t_p *var)
{
	char	buf[4096];
	char	*base16;
	int		i;

	if (nbr == 0 && var->flag['.'] && !var->pr)
		return (write(1, "0x", 2));
	else if (nbr <= 0)
		return (write(1, "0x0", 3));
	base16 = "0123456789abcdef";
	i = 2;
	buf[0] = '0';
	buf[1] = 'x';
	while (nbr > 0)
	{
		buf[i] = base16[nbr % 16];
		nbr /= 16;
		i++;
	}
	ft_strrev(&buf[2], i - 3);
	return (write(1, buf, i));
}

int				func_p(t_p *var)
{
	int					sum;
	unsigned long long	*ptr;
	unsigned long long	address;
	int					size_digits_ptr;

	sum = 0;
	ptr = var->value;
	address = (unsigned long long)ptr;
	size_digits_ptr = address == 0 ? 3 : size_digits(address);
	if (var->flag['-'])
	{
		sum = print_value(address, var);
		sum += width(var, size_digits_ptr);
	}
	else
	{
		sum = width(var, size_digits_ptr);
		sum += print_value(address, var);
	}
	return (sum);
}
