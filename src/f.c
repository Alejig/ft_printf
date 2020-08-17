/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljigmon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 02:37:40 by aljigmon          #+#    #+#             */
/*   Updated: 2019/07/21 18:06:01 by aljigmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include <unistd.h>
#include "init.h"
#include "shield_buffer.h"
#include "size_nbr.h"
#include "is_float_neg.h"
#include "print_value_f.h"

static int	width(t_p *var, int size_n)
{
	char	buffer[4096];

	var->flag['0'] && !var->flag['-'] ?
		init(buffer, '0', 4096) : init(buffer, ' ', 4096);
	if (var->wd > 4096)
		shield_buffer(buffer, &var->wd);
	return (write(1, buffer, var->wd - size_n <= 0 ? 0 : var->wd - size_n));
}

static int	flag_width(t_p *var, int size_n, long double nbr, int neg)
{
	int		sum;
	int		precision;

	sum = 0;
	precision = var->flag['.'] == 0 && var->pr == 0 ? 6 : var->pr;
	var->flag['+'] || neg || var->flag[' '] ? size_n++ : 0;
	if (var->flag['-'])
	{
		if (var->flag['+'] && !neg)
			sum += write(1, "+", 1);
		else if (neg)
			sum += write(1, "-", 1);
		else if (var->flag[' '])
			sum += write(1, " ", 1);
		sum += print_value_f(nbr, precision);
		return (sum += width(var, size_n));
	}
	!var->flag['0'] ? sum += width(var, size_n) : 0;
	if (var->flag['+'] && !neg)
		sum += write(1, "+", 1);
	else if (neg)
		sum += write(1, "-", 1);
	var->flag[' '] && !neg && !var->flag['+'] ? sum += write(1, " ", 1) : 0;
	var->flag['0'] ? sum += width(var, size_n) : 0;
	return (sum += print_value_f(nbr, precision));
}

static int	flag(t_p *var, int neg)
{
	int		sum;

	sum = 0;
	if (var->flag['+'] && !neg)
		sum += write(1, "+", 1);
	else if (var->flag[' '])
		sum += write(1, " ", 1);
	return (sum);
}

int			size_and_neg(t_p *var, long double *nbr, int precision, int *neg)
{
	int		size_n;

	p.f = (float)*nbr;
	if (*nbr != *nbr || *nbr == 1.0 / 0)
	{
		var->flag['0'] = 0;
		size_n = 3;
	}
	else if (*nbr == -1.0 / 0)
	{
		var->flag['0'] = 0;
		size_n = 4;
	}
	else if (p.u & (1 << 31))
	{
		*neg = 1;
		*nbr = *nbr * -1;
		size_n = size_nbr((unsigned long long int)*nbr)
			+ (precision > 0 ? precision + 1 : 0);
	}
	else
		size_n = size_nbr((unsigned long long int)*nbr)
			+ (precision > 0 ? precision + 1 : 0);
	return (size_n);
}

int			func_f(t_p *var)
{
	int				sum;
	long double		*nbr;
	int				precision;
	int				size_n;
	int				neg;

	sum = 0;
	neg = 0;
	precision = var->flag['.'] == 0 && var->pr == 0 ? 6 : var->pr;
	nbr = var->value;
	size_n = size_and_neg(var, nbr, precision, &neg);
	if (var->wd && (var->flag['0'] || var->flag[' ']
				|| var->flag['-'] || var->flag['+']))
		return (sum += flag_width(var, size_n, *nbr, neg));
	else if (var->flag[' '] || var->flag['+'])
		sum += flag(var, neg);
	else if (var->wd)
		sum += width(var, size_n);
	sum += neg ? write(1, "-", 1) : 0;
	sum += print_value_f(*nbr, precision);
	return (sum);
}
