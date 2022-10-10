/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anloisea <anloisea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 11:45:25 by anloisea          #+#    #+#             */
/*   Updated: 2022/10/10 13:11:23 by anloisea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error(int errnum, char *msg)
{
	ft_putstr_fd("Error\nso_long: ", 2);
	ft_putstr_fd(msg, 2);
	exit(errnum);
}

void	open_error(char *arg)
{
	ft_putstr_fd("Error\nso_long: ", 2);
	perror(arg);
	exit(3);
}

void	map_error(t_data *data, int errnum, char *msg)
{
	ft_putstr_fd("Error\nso_long: ", 2);
	ft_putstr_fd(msg, 2);
	free_data(data);
	exit(errnum);
}
