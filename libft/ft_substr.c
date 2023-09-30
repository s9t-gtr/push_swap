/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: string <string>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 06:18:20 by kousuzuk          #+#    #+#             */
/*   Updated: 2023/06/20 08:47:08 by string           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ss;
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	if (start > ft_strlen((char *)s))
		return (ft_strdup(""));
	if (start + len > ft_strlen((char *)s))
		len = ft_strlen((char *)s) - start;
	ss = malloc(sizeof(char) * (len + 1));
	if (!ss)
		return (NULL);
	while (i < len)
	{
		ss[i] = s[start + i];
		i++;
	}
	ss[i] = '\0';
	return (ss);
}

// int main()
// {
// 	printf("Hello : %s\n", ft_substr("HelloHello", 5, 10));
// 	printf("Hello : %s\n", ft_substr("HelloHello", 5, 5));
// 	printf("H : %s\n", ft_substr("HelloHello", 5, 1));
// 	printf(" : %s\n", ft_substr("HelloHello", 5, 1));
// 	printf("H : %s\n", ft_substr("HelloHello", 5, 1));
// 	printf(" : %s\n", ft_substr("HelloHello", 5, 0));
// 	printf(" : %s\n", ft_substr("HelloHello", 100, 0));
// 	return (0);
// }
