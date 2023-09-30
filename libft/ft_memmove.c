/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: string <string>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 08:21:19 by kousuzuk          #+#    #+#             */
/*   Updated: 2023/06/20 08:49:46 by string           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (!dest && !src)
		return (NULL);
	if (dest > src)
	{
		while (n--)
			*(unsigned char *)(dest + n) = *(unsigned char *)(src + n);
	}
	else
	{
		i = 0;
		while (n--)
		{
			*(unsigned char *)(dest + i) = *(unsigned char *)(src + i);
			i++;
		}
	}
	return (dest);
}

// int main(void)
// {
//         char str[] = "abcdefghijklmnopqrstu";
//         printf("移動前：%s\n",str);
//         memmove(str+5, str, 10);        /* 重複エリアのコピー */
//         printf("移動後：%s\n",str);

//         char str2[] = "abcdefghijklmnopqrstu";
//         printf("移動前：%s\n",str2);
//         ft_memmove(str2+5, str2, 10);        /* 重複エリアのコピー */
//         printf("移動後：%s\n",str2);
//         return (0);
// }
