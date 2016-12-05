/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbegne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 18:50:36 by cbegne            #+#    #+#             */
/*   Updated: 2016/11/18 14:08:56 by epillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	*ft_memalloc(size_t size)
{
	char	*str;
	size_t	i;

	i = 0;
	str = malloc(size);
	if (str == NULL)
		return (NULL);
	while (i < size)
	{
		str[i] = '\0';
		i++;
	}
	return (str);
}
