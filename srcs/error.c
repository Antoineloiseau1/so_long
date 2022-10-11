/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anloisea <anloisea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 11:45:25 by anloisea          #+#    #+#             */
/*   Updated: 2022/10/11 13:38:23 by anloisea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error(int errnum, char *msg)
{
	ft_putstr_fd("Error\nso_long: ", 2);
	ft_putstr_fd(msg, 2);
		//system("leaks so_long");
	exit(errnum);
}

void	map_error(t_data *data, int errnum, char *msg)
{
	ft_putstr_fd("Error\nso_long: ", 2);
	ft_putstr_fd(msg, 2);
	free_data(data);
		//system("leaks so_long");
	exit(errnum);
}
