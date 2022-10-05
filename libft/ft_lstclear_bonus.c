/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <antoine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 19:04:16 by anloisea          #+#    #+#             */
/*   Updated: 2022/10/05 11:32:26 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst)
{
	t_list	*tmp;

	tmp = *lst;
	while (tmp)
	{
		*lst = (*(lst))->next;
		free(tmp);
		tmp = *lst;
	}
}
