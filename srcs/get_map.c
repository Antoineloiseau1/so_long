/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anloisea <anloisea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 16:15:31 by anloisea          #+#    #+#             */
/*   Updated: 2022/10/11 12:04:32 by anloisea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**get_map(int fd)
{
	t_list	*lst;
	t_list	*tmp;
	int		i;
	char	**map;

	lst = ft_lstnew((char *)get_next_line(fd));
	tmp = lst;
	i = 0;
	while (tmp->content)
	{
		ft_lstadd_back(&lst, ft_lstnew((char *)get_next_line(fd)));
		tmp = tmp->next;
		i++;
	}
	map = malloc((i + 1) * sizeof(*map));
	i = 0;
	tmp = lst;
	while (tmp)
	{
		map[i] = (char *)tmp->content ;
		tmp = tmp->next;
		i++;
	}
	ft_lstclear(&lst);
	return (map);
}
