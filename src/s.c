/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljigmon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 11:56:28 by aljigmon          #+#    #+#             */
/*   Updated: 2019/07/05 16:13:22 by aljigmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"
#include <unistd.h>
#include "struct.h"
#include "shield_buffer.h"

static int	ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static int	options(t_p *var, int size)
{
	char	buf[4096];
	int		sum;

	sum = 0;
	var->flag['0'] && !var->flag['-'] ? init(buf, '0', 4096)
		: init(buf, ' ', 4096);
	if (var->wd > 4096)
		sum += shield_buffer(buf, &var->wd);
	sum += write(1, buf, var->wd - size < 0 ? 0 : var->wd - size);
	return (sum);
}

int			func_s(t_p *var)
{
	int		sum;
	char	*str;
	int		size;

	sum = 0;
	str = var->value;
	if (str == NULL)
		str = "(null)";
	size = ft_strlen(str);
	size = var->flag['.'] && var->pr < size ? var->pr : size;
	if (!var->flag['-'])
	{
		sum = options(var, size);
		sum += write(1, str, size);
	}
	else
	{
		sum = write(1, str, size);
		sum += options(var, size);
	}
	return (sum);
}
