/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: string <string>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 12:51:47 by kousuzuk          #+#    #+#             */
/*   Updated: 2023/06/20 08:49:52 by string           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *buf, const void *src, size_t n)
{
	size_t	i;

	if (!buf && !src)
		return (NULL);
	i = 0;
	while (n--)
	{
		*(unsigned char *)(buf + i) = *(unsigned char *)(src + i);
		i++;
	}
	return (buf);
}

// int main()
// {
//     char buf[] = "asa";
//     // char buf2[] = "";
//     ft_memcpy(buf,NULL,0);
//     printf("ft_memcpy: コピー後のbuf文字列→%s\n",buf);
// 	char buf3[] = "asd";
// 	// char buf4[] = "";
// 	memcpy(buf3,NULL,0);
// 	printf("memcpy: コピー後のbuf文字列→%s\n",buf3);
//     return (0);
// }
