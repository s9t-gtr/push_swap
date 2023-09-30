/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: string <string>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 09:05:04 by kousuzuk          #+#    #+#             */
/*   Updated: 2023/06/23 06:40:46 by kousuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_trimming(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set && set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

void	ft_initializer(size_t *i, size_t *start, size_t *end, char const *s1)
{
	*start = 0;
	*end = ft_strlen(s1) - 1;
	*i = 0;
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*s;
	size_t	start;
	size_t	end;
	size_t	i;

	if (!s1 || !set)
		return (NULL);
	if (ft_strlen(s1) == 0)
		return ("");
	ft_initializer(&i, &start, &end, s1);
	while (ft_trimming(s1[start], set))
		start++;
	if (start == ft_strlen(s1))
		return (ft_strdup(""));
	while (ft_trimming(s1[end], set))
		end--;
	s = malloc(sizeof(char) * (end - start + 2));
	if (!s)
		return (NULL);
	while (s1[start] && start <= end)
		s[i++] = s1[start++];
	s[i] = '\0';
	return (s);
}
