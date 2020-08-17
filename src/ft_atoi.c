/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljigmon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 11:24:36 by aljigmon          #+#    #+#             */
/*   Updated: 2019/07/21 15:29:56 by aljigmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static void		init(long long *a, int *b, int *c)
{
	*a = 0;
	*b = 0;
	*c = 0;
}

int				ft_atoi(const char *str, int *index)
{
	long long		nbr;
	int				neg;
	int				i;

	init(&nbr, &neg, &i);
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		neg = 1;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		nbr = (nbr * 10) + (long long)str[i] - 48;
		if (nbr == 2147483648)
			nbr = 0;
		i++;
	}
	*index += i - 1;
	return ((neg) ? (int)-nbr : (int)nbr);
}
