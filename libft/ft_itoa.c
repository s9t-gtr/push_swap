/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: string <string>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 08:22:13 by kousuzuk          #+#    #+#             */
/*   Updated: 2023/06/20 08:51:17 by string           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_nbr(int n)
{
	size_t	nbr;

	nbr = 0;
	if (n < 0)
	{
		n *= -1;
		nbr++;
	}
	while (n > 0)
	{
		nbr++;
		n = n / 10;
	}
	return (nbr);
}

char	*ft_itoa(int n)
{
	size_t	nbr_cnt;
	char	*str;

	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	nbr_cnt = ft_count_nbr(n);
	str = malloc(sizeof(char) * (nbr_cnt + 1));
	if (!str)
		return (NULL);
	str[nbr_cnt] = '\0';
	if (n < 0)
	{
		n *= -1;
		str[0] = '-';
	}
	while (nbr_cnt-- && n > 0)
	{
		str[nbr_cnt] = (n % 10) + '0';
		n = n / 10;
	}
	return (str);
}
