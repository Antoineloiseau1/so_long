/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrnstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anloisea <anloisea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 12:02:56 by anloisea          #+#    #+#             */
/*   Updated: 2022/10/25 12:06:45 by anloisea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = ft_strlen(haystack) - 1;
	if (!needle[i])
		return ((char *)haystack);
	else if (!haystack[i])
		return (NULL);
	while (haystack[i] && len)
	{
		j = len - 1;
		k = i;
		while (haystack[k] == needle[j] && k < len && haystack[k])
		{
			k++;
			j++;
		}
		if (needle[j] == 0)
			return ((char *)haystack + i);
		i++;
	}
	return (NULL);
}