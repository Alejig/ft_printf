/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljigmon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 17:23:42 by aljigmon          #+#    #+#             */
/*   Updated: 2019/06/24 10:13:53 by aljigmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"

void	init_tab_struct(t_p *ptr)
{
	ptr->flag['+'] = 0;
	ptr->flag['-'] = 0;
	ptr->flag[' '] = 0;
	ptr->flag['.'] = 0;
	ptr->flag['#'] = 0;
	ptr->flag['0'] = 0;
	ptr->wd = 0;
	ptr->pr = 0;
	ptr->type = 0;
	ptr->size = 0;
	ptr->value = 0;
}
