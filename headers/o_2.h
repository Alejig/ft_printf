/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o_2.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljigmon <aljigmon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 16:44:43 by aljigmon          #+#    #+#             */
/*   Updated: 2019/07/05 15:36:18 by aljigmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef O_2_H
# define O_2_H

int	print_value_o(unsigned long long int nbr, t_p *var);
int	option_hashtag_o(unsigned long long int nbr, t_p *var);
int	option_width_o(t_p *var, int siz_nb, unsigned long long int nbr);
int	option_precision_o(t_p *var, int siz_nb, unsigned long long int nbr);

#endif
