/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 14:37:09 by ldevelle          #+#    #+#             */
/*   Updated: 2018/11/16 18:04:16 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <unistd.h>
# include <fcntl.h>

int		ft_open(const char *av);

int		ft_read(int file_descriptor);

void	ft_puterror(char c);
int		ft_error(char *str);
char	*ft_p_error(char *str);
void	ft_putchar(char c);
void	ft_putstr(char *str);

#endif
