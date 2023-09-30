/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: string <string>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 12:40:37 by kousuzuk          #+#    #+#             */
/*   Updated: 2023/06/06 09:59:11 by kousuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
		return (c + 32);
	else
		return (c);
}

// int main(){
// 	printf("%c",ft_tolower('a'));
// 	printf("%c",ft_tolower('z'));
// 	printf("%c",ft_tolower('A'));
// 	printf("%c",ft_tolower('Z'));
// 	printf("%c",ft_tolower('1'));
// 	printf("%c",ft_tolower('!'));
// }
