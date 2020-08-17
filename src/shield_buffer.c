/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shield_buffer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljigmon <aljigmon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 13:51:50 by aljigmon          #+#    #+#             */
/*   Updated: 2019/07/05 16:13:43 by aljigmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		shield_buffer(char *buffer, int *size)
{
	int		sum;

	sum = 0;
	while (*size > 4096)
	{
		sum += write(1, buffer, 4096);
		*size -= 4096;
	}
	return (sum);
}
