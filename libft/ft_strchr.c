/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: string <string>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 12:46:53 by kousuzuk          #+#    #+#             */
/*   Updated: 2023/06/20 08:48:50 by string           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	if ((char)c == '\0')
		return ((char *)(s + i));
	return (NULL);
}

//int main(){
//	char str[] =  "abcdefghijklmnabcdefghijklmn", *p, *p2;
//	int c;
//
//	printf("検索文字入力");
//	c = getchar();
//
//	printf("----------strchr--------");
//	p = strchr(str, c);
//	if(p != NULL){
//		printf("%cは文字列の%ld番目にあります。\n",c,p-str);
//		printf("以降の文字列は%sです。\n", p);
//	}
//	else
//		printf("%cは見つかりませんでした\n",c);
//	printf("----------ft_strchr--------");
//	p2 = ft_strchr(str, c);
//	if(p2 != NULL){
//		printf("%cは文字列の%ld番目にあります。\n",c,p2-str);
//		printf("以降の文字列は%sです。\n", p2);
//	}
//	else
//		printf("%cは見つかりませんでした\n",c);
//	return (0);
//}
