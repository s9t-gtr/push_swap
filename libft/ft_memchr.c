/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: string <string>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 11:04:19 by kousuzuk          #+#    #+#             */
/*   Updated: 2023/06/20 08:50:03 by string           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ns;

	i = 0;
	ns = (unsigned char *)s;
	while (n > 0)
	{
		if (ns[i] == (unsigned char)c)
			return ((unsigned char *)(ns + i));
		i++;
		n--;
	}
	return (NULL);
}

// int main(){
// 	char str[] = "abcdef\0ghij";
// 	char *p;
// 	p = memchr(str, 'h', 12);
// 	printf("検索文字は文字列の%ld番目\n", p-str);

// 	char str2[] = "abcdef\0ghij";
// 	char *p2;
// 	p2 = ft_memchr(str2, 'h', 12);
// 	printf("検索文字は文字列の%ld番目\n", p2-str2);
// 	return (0);
// }
