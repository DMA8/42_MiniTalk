/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syolando <syolando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 13:47:43 by syolando          #+#    #+#             */
/*   Updated: 2022/02/14 18:25:33 by syolando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

typedef struct s_byte_sending
{
	int		client_pid;
	int		byte_order;
	char	char_to_send;
}	t_byte_sending;



void	send_byte(char byte, int pid);
void	send_message(char *str, int pid);
void	ft_putnbr(int n);
void	fatal(char *str);
int		ft_atoi(const char *str);




#endif