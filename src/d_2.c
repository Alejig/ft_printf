/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_2.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljigmon <aljigmon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 21:30:55 by aljigmon          #+#    #+#             */
/*   Updated: 2019/07/06 21:43:34 by aljigmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "init.h"
#include <unistd.h>
#include "shield_buffer.h"

int	print_value_d(unsigned long long int nb, t_p *var)
{
	unsigned long long int	div;
	unsigned long long int	tempo;
	int						i;
	char					buf[23];

	div = 1;
	i = 0;
	tempo = nb;
	if (nb == 0 && var->flag['.'] && !var->pr && !var->wd)
		return (0);
	if (nb == 0 && var->flag['.'] && !var->pr && var->wd)
		return (write(1, " ", 1));
	while (tempo > 9)
	{
		div *= 10;
		tempo /= 10;
	}
	while (div > 0)
	{
		buf[i] = nb / div + 48;
		nb = nb - ((nb / div) * div);
		div /= 10;
		i++;
	}
	return (write(1, buf, i));
}

int	f_p(t_p *var, unsigned long long int nbr, int size_nb, int neg)
{
	int		sum;
	char	buf[4096];

	sum = 0;
	init(buf, '0', 4096);
	if (var->flag['+'] && !neg)
		sum += write(1, "+", 1);
	else if (neg)
		sum += write(1, "-", 1);
	else if (var->flag[' '])
		sum += write(1, " ", 1);
	if (var->pr > 4096)
		sum += shield_buffer(buf, &var->pr);
	sum += write(1, buf, var->pr - size_nb < 0 ? 0 : var->pr - size_nb);
	sum += print_value_d(nbr, var);
	return (sum);
}

int	f_w(t_p *var, unsigned long long int nbr, int size_nb, int neg)
{
	int		sum;
	char	buf[4096];

	sum = 0;
	var->flag['0'] && !var->flag['-']
		? init(buf, '0', 4096) : init(buf, ' ', 4096);
	if (var->flag['+'] || neg || var->flag[' '])
		size_nb++;
	if ((var->flag['0'] || var->flag['-']) && var->flag['+'] && !neg)
		sum += write(1, "+", 1);
	else if ((var->flag['0'] || var->flag['-']) && neg)
		sum += write(1, "-", 1);
	else if ((var->flag['0'] || var->flag['-']) && var->flag[' '])
		sum += write(1, " ", 1);
	sum += var->flag['-'] ? print_value_d(nbr, var) : 0;
	sum += var->wd > 4096 ? shield_buffer(buf, &var->wd) : 0;
	sum += write(1, buf, var->wd - size_nb < 0 ? 0 : var->wd - size_nb);
	if (!var->flag['-'] && !var->flag['0'] && var->flag['+'] && !neg)
		sum += write(1, "+", 1);
	else if (!var->flag['-'] && !var->flag['0'] && neg)
		sum += write(1, "-", 1);
	else if (!var->flag['-'] && !var->flag['0'] && var->flag[' '])
		sum += write(1, " ", 1);
	sum += !var->flag['-'] ? print_value_d(nbr, var) : 0;
	return (sum);
}

int	option_flag(t_p *var, unsigned long long int nbr, int neg)
{
	int		sum;

	sum = 0;
	if (var->flag['+'] && !neg)
		sum += write(1, "+", 1);
	else if (neg)
		sum += write(1, "-", 1);
	else if (var->flag[' '] && !neg)
		sum += write(1, " ", 1);
	sum += print_value_d(nbr, var);
	return (sum);
}

int	w_p(t_p *var, unsigned long long int nbr, int size_nb, int neg)
{
	int		sum;
	char	buf[4096];

	sum = 0;
	init(buf, ' ', 4096);
	if (var->wd > 4096)
		sum += shield_buffer(buf, &var->wd);
	if (size_nb > var->pr)
		sum += write(1, buf, var->wd - size_nb - neg
				< 0 ? 0 : var->wd - size_nb - neg);
	else
		sum += write(1, buf, var->wd - var->pr - neg
				< 0 ? 0 : var->wd - var->pr - neg);
	init(buf, '0', 4096);
	if (neg)
		sum += write(1, "-", 1);
	if (var->pr > 4096)
		sum += shield_buffer(buf, &var->pr);
	sum += write(1, buf, var->pr - size_nb < 0 ? 0 : var->pr - size_nb);
	sum += print_value_d(nbr, var);
	return (sum);
}
