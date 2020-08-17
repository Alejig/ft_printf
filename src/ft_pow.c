/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljigmon <aljigmon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 10:14:29 by aljigmon          #+#    #+#             */
/*   Updated: 2019/07/19 10:17:13 by aljigmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned long long int	ft_pow(unsigned long long int nbr, int pow)
{
	unsigned long long int		res;

	res = 1;
	while (pow)
	{
		res *= nbr;
		pow--;
	}
	return (res);
}
