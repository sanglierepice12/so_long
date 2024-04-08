#ifndef SO_LONG_H
#define SO_LONG_H

#include "../mlx_linux/mlx.h"
#include "../mlx_linux/mlx_int.h"
#include "../libft/incs/libft.h"

typedef struct s_map
{
	char	**map;

}		t_map;


/*-------PARSE--------*/
void	ft_parse_the_map(char *argv);

/*-------EXIT--------*/
void	ft_exit(t_map *map);
void	ft_free_things(t_map *map);

#endif