/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: string <string>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 12:17:57 by kousuzuk          #+#    #+#             */
/*   Updated: 2023/06/06 09:59:41 by kousuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
		return (c - 32);
	else
		return (c);
}

// int main(){
// 	printf("%c",ft_toupper('a'));
// 	printf("%c",ft_toupper('A'));
// 	printf("%c",ft_toupper('1'));
// 	printf("%c",ft_toupper('['));
// 	printf("%c",ft_toupper('Z'));
// 	printf("%c",ft_toupper('z'));
// }
