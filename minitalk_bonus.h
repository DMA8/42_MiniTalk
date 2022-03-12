/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syolando <syolando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 13:47:43 by syolando          #+#    #+#             */
/*   Updated: 2022/02/15 18:09:37 by syolando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

void	send_byte(char byte, int pid);
void	send_message(char *str, int pid);
void	ft_putnbr(int n);
void	fatal(char *str);
int		ft_atoi(const char *str);
int		is_numeric(char *str);

#endif