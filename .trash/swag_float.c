/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swag_float.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 14:45:40 by ldevelle          #+#    #+#             */
/*   Updated: 2019/07/02 18:49:32 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

unsigned char	*s_to_bino(unsigned char *str, int length)
{
	unsigned char	*binary;
	int		actual_char;
	int		power;

	if (!(binary = (unsigned char*)ft_strnew(length * 8)))
		return (NULL);
	actual_char = -1;
	while (++actual_char < length)
	{
		power = -1;
		while (++power < 8)
			if (str[actual_char] & (unsigned char)ft_power(2, power))
				binary[(actual_char * 8) + (power)] = '1';
			else
				binary[(actual_char * 8) + (power)] = '0';
	}
	return (binary);
}

unsigned char	*ft_strrevo(unsigned char *str, size_t size)
{
	unsigned char	tmp;
	int		i;
	int		j;

	i = 0;
	if (size != 0)
		j = size - 1;
	else
		j = ft_strlen((char*)str) - 1;
	while (i < j)
	{
		tmp = str[i];
		str[i] = str[j];
		str[j] = tmp;
		j--;
		i++;
	}
	return (str);
}

void	*void_to_str(const void *myst, size_t size)
{
	char	*str;

	str = ft_strnew(size);
	ft_memmove((void*)str, (char*)myst, size);
	return (str);
}

void	print_string_to_u_char(unsigned char* converter, size_t size_thing)
{
	int			i;
	char		*tmp;

	i = size_thing;
	while (--i > -1)
	{
		tmp = ft_nb_to_a((int)converter[i], 0);
		ft_puttab(tmp, 8);
		ft_putnbr((int)converter[i]);
		ft_strdel(&tmp);
		ft_putstr(" ");
	}
	ft_putstr("\n");
	C_GREEN
	i = 0;
	while (++i <= (int)size_thing)
	{
		tmp = ft_nb_to_a(i, 0);
		ft_puttab(tmp, 8);
		ft_putnbr(i);
		ft_strdel(&tmp);
		ft_putstr(" ");
	}
	C_RESET
}

unsigned char	*print_string_to_binaryo(unsigned char *converter, size_t size_thing)
{
	int i;

	converter = s_to_bino(converter, size_thing);
	ft_strrevo(converter, (size_thing * 8));
	i = -1;
	while (++i < (int)size_thing)
	{

		ft_putnstr((const char*)converter + i * 8, 8);
		ft_putstr(" ");
	}
	return (converter);
//	ft_strdel((char**)&converter);
}

char			*get_nb_from_exp(unsigned char *exp, size_t size)
{
	int			nb;
	int			i;
	//char		*retrn;

	nb = 0;
	i = -1;
	while (++i < (int)size)
		if (exp[i] - '0')
			nb += ft_power(2, size - i - 1);
	nb -= 127;/*
	if (nb > 0)
		nb = ft_power(2, nb);
	else if (nb == 0)
		nb = 1;
	else
		char[i] = nb / 10;
		nb = nb % 10;
*/

	printf("EG%d\n", nb);
	//retrn = ft_nb_to_a(nb, 10);
	return (NULL);
}

char			*string_calc(t_float info)
{
	(void)info;
/*	get_nb_from_exp();
	get_nb_from_man();
	multiply_strings(exp, man);*/
	return (NULL);
}

void			float_out(unsigned char *converter, size_t size_thing)
{
	t_float			info;

	converter = s_to_bino(converter, size_thing);
	ft_strrevo(converter, (size_thing * 8));
	ft_bzero(&info, sizeof(info));
	ft_memmove(info.sign, converter + 8 * 6, 1);
	ft_memmove(info.exposant, converter + 8 * 6 + 1, 15);
	//ft_memmove(info.exposant, converter + 8 * 3, 24);
	ft_memmove(info.mantisse, converter + (8 * 8), 24);
	//ft_memmove(info.mantisse, converter + (8 * 6) + 1, 39);
	printf("\nSIN: %s\nEXP: %s\nMAN: %s\n", info.sign, info.exposant, info.mantisse);
	//get_nb_from_exp(info.exposant, 8);
//	return (&info);
}

void	print_thing_to_binary_and_unsigned_char(void* thing, size_t size_thing)
{
	ft_putstr("\n");
	print_string_to_u_char((unsigned char*)thing, size_thing);
	ft_putstr("\n");
	print_string_to_binaryo((unsigned char*)thing, size_thing);
	ft_putstr("\n");
	float_out((unsigned char*)thing, size_thing);
	ft_putstr("\n");
}



int			print_float(t_printf *print, long double nb)
{
	long double conv;

	conv = nb;
	print_thing_to_binary_and_unsigned_char((void*)&conv, sizeof(conv));
	//printf("plop\n");
	conv = -nb;
	print_thing_to_binary_and_unsigned_char((void*)&conv, sizeof(conv));

	// get_int_from_float(nb);
	paste_int_in_printf(print, ft_strjoin(ft_strjoin(ft_nb_to_a((int)nb, 10), "."), ft_nb_to_a((long long)((nb - (int)nb) * 1000000), 10)));
	return (0);

}
