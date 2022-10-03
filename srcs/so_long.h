/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anloisea <anloisea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 13:49:08 by anloisea          #+#    #+#             */
/*   Updated: 2022/10/03 17:24:53 by anloisea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include <fcntl.h>

typedef struct s_mlx
{
	void		*mlx;
	void		**textures;
	void		*win;
	char		**map;
}				t_mlx;

// typedef	struct s_map
// {
// 	char		*line;
// 	struct s_map *next;
// }				t_map;

char	**get_map(int fd);
void	free_map(char **map);


#endif