/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: string <string>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 08:22:13 by kousuzuk          #+#    #+#             */
/*   Updated: 2023/07/02 12:59:31 by kousuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static size_t	ft_count_nbr(unsigned int n)
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

char	*ft_utoa(unsigned int n)
{
	size_t	nbr_cnt;
	char	*str;

	if (n == 0)
		return (ft_strdup("0"));
	nbr_cnt = ft_count_nbr(n);
	str = malloc(sizeof(char) * (nbr_cnt + 1));
	if (!str)
		return (NULL);
	str[nbr_cnt] = '\0';
	while (nbr_cnt-- && n > 0)
	{
		str[nbr_cnt] = (n % 10) + '0';
		n = n / 10;
	}
	return (str);
}
