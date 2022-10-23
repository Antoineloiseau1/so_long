/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <antoine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 11:45:25 by anloisea          #+#    #+#             */
/*   Updated: 2022/10/23 16:11:29 by antoine          ###   ########.fr       */
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

void	leave(t_data *data)
{
	free_mlx(data);
	free_data(data);
	exit(0);
}
