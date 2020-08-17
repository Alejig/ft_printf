/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljigmon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 10:19:51 by aljigmon          #+#    #+#             */
/*   Updated: 2019/07/05 16:11:14 by aljigmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include <unistd.h>
#include "init.h"
#include "shield_buffer.h"

static int		options(t_p *var)
{
	int		sum;
	char	buffer[4096];

	sum = 0;
	if (var->wd > 0 && var->wd <= 2147483647)
	{
		var->flag['0'] && !var->flag['-']
			? init(buffer, '0', 4096) : init(buffer, ' ', 4096);
		if (var->wd > 4096)
			sum += shield_buffer(buffer, &var->wd);
		sum += write(1, buffer, var->wd - 1);
	}
	return (sum);
}

int				func_c(t_p *var)
{
	int		sum;
	int		*c;

	c = var->value;
	if (var->flag['-'])
	{
		sum = write(1, c, 1);
		sum += options(var);
	}
	else
	{
		sum = options(var);
		sum += write(1, c, 1);
	}
	return (sum);
}
