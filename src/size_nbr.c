/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_nbr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljigmon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 06:54:50 by aljigmon          #+#    #+#             */
/*   Updated: 2019/06/12 03:22:11 by aljigmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		size_nbr(unsigned long long int nbr)
{
	int		size_number;

	size_number = 1;
	while (nbr > 9)
	{
		nbr /= 10;
		size_number++;
	}
	return (size_number);
}
