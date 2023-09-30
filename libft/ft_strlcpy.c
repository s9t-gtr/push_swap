/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: string <string>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 11:14:24 by kousuzuk          #+#    #+#             */
/*   Updated: 2023/06/20 08:48:01 by string           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	while (src[len])
		len++;
	if (dstsize != 0)
	{
		while (i < dstsize - 1 && src[i])
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (len);
}

// int main(){
// 	char *str = "1234567";
// 	char *str1 = "1234567";
// 	char *str2 = "ABCDEFG";
// 	char *dst = "42tokyo";
// 	printf("ft_: %zu, %s\n", ft_strlcpy(str, str2, 0), str);
// 	printf("lib: %zu, %s\n", strlcpy(str1, str2, 0), str1);

// 	printf("dst = %s\n", dst);
// 	printf("%zu\n", strlcpy(dst, "aiueo",2));
// 	printf("%zu\n", ft_strlcpy(NULL, "aiueo",2));
// 	printf("%zu\n", strlcpy(NULL, "aiueo",2));
// 	printf("%zu : %s\n", ft_strlcpy(dst, "aiueo",0), dst);
// 	printf("%zu\n", strlcpy(dst, "aiueo",0));
// }
