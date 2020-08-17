/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljigmon <aljigmon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 13:13:48 by aljigmon          #+#    #+#             */
/*   Updated: 2019/06/22 13:38:03 by aljigmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_strrev(char *str, int size)
{
	int		i;
	int		tmp;

	i = 0;
	while (i < size)
	{
		tmp = str[i];
		str[i] = str[size];
		str[size] = tmp;
		size--;
		i++;
	}
}
