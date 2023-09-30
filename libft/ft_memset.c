/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: string <string>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 11:32:08 by kousuzuk          #+#    #+#             */
/*   Updated: 2023/06/20 08:49:41 by string           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (len--)
	{
		*(unsigned char *)(b + i) = (unsigned char)c;
		i++;
	}
	return (b);
}

// int main()
// {
// 	char buf[] = "ABCDEFG";
// 	memset(buf+2,1,3);
// 	ft_memset(buf+2,1,3);
// 	printf("buf文字列→%s\n", buf);

// 	return (0);
// }
