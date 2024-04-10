#ifndef SO_LONG_H
#define SO_LONG_H

#include "../mlx_linux/mlx.h"
#include "../mlx_linux/mlx_int.h"
#include "../libft/incs/libft.h"

typedef struct s_map
{
	int		x;
	int 	y;
	char	**map;
}		t_map;


/*-----------PARSE------------*/
void	ft_parse_the_map(char *argv, t_map *map);

/*-------MAP_CHECKER----------*/
void	ft_map_validator(t_map *map);

/*-------MAP_GENERATOR--------*/
void	map_generator(t_map *map);

/*-----------EXIT-------------*/
void	ft_exit(t_map *map, char *msg);
void	ft_free_things(t_map *map);


#endif