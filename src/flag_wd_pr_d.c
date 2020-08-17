/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_wd_pr_d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljigmon <aljigmon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 21:27:22 by aljigmon          #+#    #+#             */
/*   Updated: 2019/07/06 21:44:25 by aljigmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "d_2.h"
#include "struct.h"
#include "init.h"
#include "shield_buffer.h"
#include <unistd.h>

static int	f_w_p_2(t_p *var, unsigned long long int nbr, int size_nb, int neg)
{
	int		sum;
	char	buf[4096];

	sum = 0;
	init(buf, ' ', 4096);
	var->wd > var->pr ? var->flag[' '] = 0 : var->flag[' '];
	var->wd > 4096 ? sum += shield_buffer(buf, &var->wd) : 0;
	if (var->pr > size_nb)
		sum += write(1, buf, var->wd - var->pr - (var->flag['+'] || neg
					|| var->flag[' ']) < 0 ? 0 : var->wd - var->pr
				- (var->flag['+'] || neg || var->flag[' ']));
	else
		sum += write(1, buf, var->wd - size_nb - (var->flag['+'] || neg
					|| var->flag[' ']) < 0 ? 0 : var->wd - size_nb
				- (var->flag['+'] || neg || var->flag[' ']));
	init(buf, '0', 4096);
	if (var->flag['+'] && !neg)
		sum += write(1, "+", 1);
	else if (neg)
		sum += write(1, "-", 1);
	else if (var->flag[' '])
		sum += write(1, " ", 1);
	var->pr > 4096 ? sum += shield_buffer(buf, &var->pr) : 0;
	sum += write(1, buf, var->pr - size_nb < 0 ? 0 : var->pr - size_nb);
	return (sum += print_value_d(nbr, var));
}

int			f_w_p(t_p *var, unsigned long long int nbr, int size_nb, int neg)
{
	int		sum;
	char	buf[4096];

	sum = 0;
	init(buf, '0', 4096);
	if (var->flag['-'])
	{
		var->flag['+'] && !neg ? sum += write(1, "+", 1) : 0;
		!var->flag['+'] && !neg && var->flag[' '] ? sum += write(1, " ", 1) : 0;
		neg ? sum += write(1, "-", 1) : 0;
		var->pr > 4096 ? sum += shield_buffer(buf, &var->pr) : 0;
		sum += write(1, buf, var->pr - size_nb < 0 ? 0 : var->pr - size_nb);
		sum += print_value_d(nbr, var);
		init(buf, ' ', 4096);
		var->wd > 4096 ? sum += shield_buffer(buf, &var->wd) : 0;
		if (size_nb > var->pr)
			sum += write(1, buf, var->wd - size_nb - var->flag['+'] - neg
					< 0 ? 0 : var->wd - size_nb - var->flag['+'] - neg);
		else
			sum += write(1, buf, var->wd - var->pr - var->flag['+'] - neg
					< 0 ? 0 : var->wd - var->pr - var->flag['+'] - neg);
		return (sum);
	}
	return (f_w_p_2(var, nbr, size_nb, neg));
}
