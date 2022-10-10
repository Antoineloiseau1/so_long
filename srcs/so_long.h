/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <antoine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 13:49:08 by anloisea          #+#    #+#             */
/*   Updated: 2022/10/06 15:35:47 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include <fcntl.h>
# include <errno.h>
# include <mlx.h>
# include <stdio.h>

typedef struct s_mlx
{
	void		*ptr;
	void		**textures;
	void		*win;
	char		**map;
}				t_mlx;

typedef struct s_data
{
	char	**map;
	int		position;
	int		exit;
	int		items;
}			t_data;

char	**get_map(int fd);
void	free_map(char **map);
int		check_map(t_data *data);
int	tab_len(char **tab);


#endif