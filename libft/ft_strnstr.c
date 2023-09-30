/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: string <string>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 06:04:08 by kousuzuk          #+#    #+#             */
/*   Updated: 2023/06/20 08:47:35 by string           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	curr;

	if (len == 0 && haystack == NULL)
		return (NULL);
	if (*needle == '\0')
		return ((char *)haystack);
	if (!ft_strlen(haystack) || len < ft_strlen(needle))
		return (NULL);
	curr = 0;
	while (*haystack && curr < len)
	{
		i = 0;
		while (haystack[curr + i] && needle[i] && curr + i < len
			&& haystack[curr + i] == needle[i])
			i++;
		if (needle[i] == '\0')
			return ((char *)(haystack + curr));
		curr++;
	}
	return (NULL);
}

// int main()
// {
// 	char *str = "Hello";

// 	printf("%s : %s\n", strnstr(str, "", 6), ft_strnstr(str, "", 6));
// 	printf("%s : %s\n", strnstr(str, "a", 6), ft_strnstr(str, "a", 6));
// 	printf("%s : %s\n", strnstr(str, "i", 6), ft_strnstr(str, "i", 6));
// 	printf("%s : %s\n", strnstr(str, "eui", 6), ft_strnstr(str, "eui", 6));
// 	printf("%s : %s\n", strnstr(str, "ie", 6), ft_strnstr(str, "ie", 6));
// 	printf("%s : %s\n", strnstr(str, "uo", 6), ft_strnstr(str, "uo", 6));
// 	printf("%s : %s\n", strnstr(str, "ueo", 6), ft_strnstr(str, "ueo", 6));
// }
