/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: string <string>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 06:14:32 by kousuzuk          #+#    #+#             */
/*   Updated: 2023/06/20 08:48:43 by string           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *str)
{
	char	*s;
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_strlen(str);
	s = malloc(sizeof(char) * (len + 1));
	if (!s)
		return (NULL);
	while (i < len)
	{
		s[i] = (char)str[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}
