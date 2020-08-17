/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljigmon <aljigmon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 08:00:09 by aljigmon          #+#    #+#             */
/*   Updated: 2019/07/22 15:20:53 by aljigmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include <unistd.h>
#include "ft_strrev.h"

static int		print_no_printable(int c)
{
	char	buf[2];
	int		i;
	char	*base16;

	i = 0;
	base16 = "0123456789abcdef";
	write(1, "0x", 2);
	while (c > 0)
	{
		buf[i] = base16[c % 16];
		i++;
		c /= 16;
	}
	ft_strrev(buf, i - 1);
	write(1, buf, i);
	return (1);
}

int				func_r(t_p *var)
{
	int		sum;
	char	*str;
	int		i;

	sum = 0;
	i = 0;
	str = var->value;
	while (str[i])
	{
		if (str[i] > 32 && str[i] <= 126)
			sum += write(1, &str[i], 1);
		else
			sum += print_no_printable(str[i]);
		i++;
	}
	return (sum);
}
