/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isa_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljigmon <aljigmon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 15:31:22 by aljigmon          #+#    #+#             */
/*   Updated: 2019/06/26 13:43:59 by aljigmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		isint(char c)
{
	return (c == 'd' || c == 'i' || c == 'c');
}

int		isunsigned(char c)
{
	return (c == 'o' || c == 'u' || c == 'x'
			|| c == 'X' || c == 'b' || c == 'U');
}

int		isdouble(char c)
{
	return (c == 'f');
}

int		isptrchar(char c)
{
	return (c == 's' || c == 'p' || c == 'r');
}

int		issize(char c)
{
	return (c == 'h' || c == 'l' || c == 'L' || c == 'j' || c == 'z');
}
