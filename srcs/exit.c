/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anloisea <anloisea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 11:45:25 by anloisea          #+#    #+#             */
/*   Updated: 2022/10/24 16:13:30 by anloisea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error(int errnum, char *msg)
{
	ft_putstr_fd("Error\nso_long: ", 2);
	ft_putstr_fd(msg, 2);
	exit(errnum);
}

void	map_error(t_data *data, int errnum, char *msg)
{
	ft_putstr_fd("Error\nso_long: ", 2);
	ft_putstr_fd(msg, 2);
	free_data(data);
	exit(errnum);
}

void	leave(void)
{
	exit(0);
}
