/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudenko <arudenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 10:08:03 by arudenko          #+#    #+#             */
/*   Updated: 2018/01/15 11:01:23 by arudenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	isblank(char c)
{
	if (c <= 32)
		return (1);
	return (0);
}

static	int	is_valid(char c, int base)
{
	char	*digits;
	char	*digits2;

	digits = "0123456789abcdef";
	digits2 = "0123456789ABCDEF";
	while (base--)
		if (digits[base] == c || digits2[base] == c)
			return (1);
	return (0);
}

static	int	add(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	else if (c >= 'a' && c <= 'f')
		return (c - 'a' + 10);
	else if (c >= 'A' && c <= 'F')
		return (c - 'A' + 10);
	return (0);
}

int			ft_atoi_base(const char *str, int base)
{
	int		result;
	int		sign;

	result = 0;
	while (isblank(*str))
		str++;
	sign = (*str == '-') ? -1 : 1;
	(*str == '-' || *str == '+') ? ++str : 0;
	while (is_valid(*str, base))
		result = result * base + add(*str++);
	return (result * sign);
}
