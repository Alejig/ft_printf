/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options_xs.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljigmon <aljigmon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 18:49:32 by aljigmon          #+#    #+#             */
/*   Updated: 2019/07/05 15:35:54 by aljigmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPTIONS_XS_H
# define OPTIONS_XS_H

int	print_value_xs(unsigned long long int nbr, t_p *var, int min);
int	wd_xs(t_p *var, int size_nbr, unsigned long long int nbr, int min);
int	pr_xs(t_p *var, int size_nbr, unsigned long long int nbr, int min);
int	w_p_xs(t_p *var, int size_nbr, unsigned long long int nbr, int min);
int	option_hashtag_xs(unsigned long long int nbr, t_p *var, int min);

#endif
