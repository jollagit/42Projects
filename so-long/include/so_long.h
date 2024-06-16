#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/mman.h>
# include <X11/Xlib.h>
# include <X11/Xutil.h>
# include <X11/X.h>
# include <X11/keysym.h> // include funzioni specifiche per keyboard input
# include <mlx_int.h>
# include <mlx.h>


typedef struct s_data
{
	void	*mlx; // puntatore mlx
	void	*window; // mlx puntatore a finestra
}	t_data;

int		destroy(t_data *data);
char	**map_to_mat(char *map);
char	*get_map(char *map_name);
size_t	*get_char_pos(char **mat);
int		keypress(int key, t_data *data);
void	put_image(void *mlx, void *window);
void	get_size_window(int *width, int *height);
char	*search_image(char **map_mat, int x, int y);

#endif