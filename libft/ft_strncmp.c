/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: string <string>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 08:44:54 by kousuzuk          #+#    #+#             */
/*   Updated: 2023/06/20 08:47:41 by string           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	while (s1[i] && s2[i] && i < (n - 1)
		&& (unsigned char)s1[i] == (unsigned char)s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

// int main()
// {
// 	char str[] = "ABC";
// 	printf("========strncmp==========");
// 	printf("ABC:ABD = %d\n", strncmp(str,"ABD",2));
// 	printf("ABC:ABC = %d\n", strncmp(str,"ABC",2));
// 	printf("ABC:AAA = %d\n", strncmp(str,"AAA",2));
// 	printf("ABC:ABCD = %d\n", strncmp(str,"ABCD",2));
// 	printf("ABC:AB = %d\n", strncmp(str,"AB",2));
// 	printf("ABC:B = %d\n", strncmp(str,"B",2));
// 	printf("ABC:A = %d\n", strncmp(str,"",2));

// 	printf("========ft_strncmp==========");
// 	printf("ABC:ABD = %d\n", ft_strncmp(str,"ABD",2));
// 	printf("ABC:ABC = %d\n", ft_strncmp(str,"ABC",2));
// 	printf("ABC:AAA = %d\n", ft_strncmp(str,"AAA",2));
// 	printf("ABC:ABCD = %d\n", ft_strncmp(str,"ABCD",2));
// 	printf("ABC:AB = %d\n", ft_strncmp(str,"AB",2));
// 	printf("ABC:B = %d\n", ft_strncmp(str,"B",2));
// 	printf("ABC:A = %d\n", ft_strncmp(str,"",2));
// }
