/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: string <string>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 06:10:15 by kousuzuk          #+#    #+#             */
/*   Updated: 2023/06/20 08:51:29 by string           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*s;
	size_t	t;

	if (size == 0 || nmemb == 0)
		return (ft_calloc(1, 1));
	if (nmemb > SIZE_MAX / size)
		return (NULL);
	t = nmemb * size;
	if (t / nmemb != size)
		return (NULL);
	s = malloc(sizeof(void) * t);
	if (!s)
		return (NULL);
	ft_bzero(s, nmemb * size);
	return (s);
}
