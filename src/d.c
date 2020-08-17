/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljigmon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 17:37:40 by aljigmon          #+#    #+#             */
/*   Updated: 2019/07/06 21:45:07 by aljigmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "init.h"
#include <unistd.h>
#include "size_nbr.h"
#include "shield_buffer.h"
#include "flag_wd_pr_d.h"
#include "d_2.h"

static int	option_w(t_p *var, unsigned long long int nbr, int size_nb, int neg)
{
	int		sum;
	char	buf[4096];

	sum = 0;
	init(buf, ' ', 4096);
	if (var->wd > 4096)
		sum += shield_buffer(buf, &var->wd);
	sum += write(1, buf, var->wd - size_nb - neg
			< 0 ? 0 : var->wd - size_nb - neg);
	if (neg)
		sum += write(1, "-", 1);
	sum += print_value_d(nbr, var);
	return (sum);
}

static int	option_p(t_p *var, unsigned long long int nbr, int size_nb, int neg)
{
	int		sum;
	char	buf[4096];

	sum = 0;
	init(buf, '0', 4096);
	if (neg)
		sum += write(1, "-", 1);
	if (var->pr > 4096)
		sum += shield_buffer(buf, &var->pr);
	sum += write(1, buf, var->pr - size_nb < 0 ? 0 : var->pr - size_nb);
	sum += print_value_d(nbr, var);
	return (sum);
}

static void	check_neg(t_p *var, int *neg, unsigned long long int *nbr)
{
	long long int			*ptr;

	ptr = var->value;
	*nbr = (unsigned long long int)*ptr;
	if (*ptr < 0)
	{
		*neg = 1;
		*nbr = *ptr * -1;
	}
	if (var->size == 'h' && (*ptr >= 32768 || *ptr <= -32768))
	{
		*nbr = (short)*ptr < 0 ? (short)*ptr * -1 : (short)*ptr;
		*neg = (short)*ptr < 0 ? 1 : 0;
	}
	else if (var->size == 'h' + 'h' && (*ptr <= -128 || *ptr >= 128))
	{
		*nbr = (char)*ptr < 0 ? (char)*ptr * -1 : (char)*ptr;
		*neg = (char)*ptr < 0 ? 1 : 0;
	}
}

static int	functions_display(t_p *var, unsigned long long int nbr, int neg)
{
	int		sum;

	sum = 0;
	if ((var->flag[' '] || var->flag['0'] || var->flag['+'] || var->flag['-'])
			&& var->pr && var->wd)
		sum += f_w_p(var, nbr, size_nbr(nbr), neg);
	else if ((var->flag[' '] || var->flag['+'] || var->flag['-']) && var->pr)
		sum += f_p(var, nbr, size_nbr(nbr), neg);
	else if ((var->flag[' '] || var->flag['0'] || var->flag['+']
				|| var->flag['-']) && var->wd)
		sum += f_w(var, nbr, size_nbr(nbr), neg);
	else if ((var->flag[' '] || var->flag['+']) && !var->wd && !var->pr)
		sum += option_flag(var, nbr, neg);
	else if (var->wd && var->pr)
		sum += w_p(var, nbr, size_nbr(nbr), neg);
	else if (var->wd)
		sum += option_w(var, nbr, size_nbr(nbr), neg);
	else if (var->pr)
		sum += option_p(var, nbr, size_nbr(nbr), neg);
	else
	{
		neg ? sum = write(1, "-", 1) : 0;
		sum += print_value_d(nbr, var);
	}
	return (sum);
}

int			func_d(t_p *var)
{
	int						neg;
	unsigned long long int	nbr;
	int						sum;

	neg = 0;
	sum = 0;
	check_neg(var, &neg, &nbr);
	sum = functions_display(var, nbr, neg);
	return (sum);
}
