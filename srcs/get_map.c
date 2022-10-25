/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anloisea <anloisea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 16:15:31 by anloisea          #+#    #+#             */
/*   Updated: 2022/10/25 14:12:36 by anloisea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**get_map(int fd)
{
	t_list	*lst;
	t_list	*tmp;
	int		i;
	char	**map;

	i = 0;
	lst = ft_lstnew((char *)get_next_line(fd));
	if (lst->content == NULL)
		error(15, "MAP is empty\n");
	tmp = lst;
	while (tmp->content)
	{
		ft_lstadd_back(&lst, ft_lstnew((char *)get_next_line(fd)));
		tmp = tmp->next;
	}
	map = malloc((ft_lstsize(lst) + 1) * sizeof(*map));
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
