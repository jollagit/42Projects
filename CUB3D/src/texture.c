#include "cub3d.h"

// funzione per disegnare un pixel in una specifica posizione (x, y) su un'immagine in minilibx
void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= WIN_W || y < 0 || y >= WIN_H)
		return;
	dst = data->addr + (y *data->line_len + x *(data->bpp / 8)); // calccola l'indirizzo di memeoria del pixel a (x, y) dentro il buffer dell'immagine
	*(unsigned int *)dst = color;
}

t_texture	load_texture(void *mlx, char *path)
{
	t_texture	text;
	
	text.imge = mlx_xpm_file_to_image(mlx, path, &text.width, &text.height);
	if (!text.imge)
	{
		perror("Loading Texture Error");
		exit(0);
	}
	text.addr = mlx_get_data_addr(text.imge, &text.bpp, &text.line_len, &text.endian);
	return (text);
}

void		find_id_texture(t_game *g, int side, double raydir_x, double raydir_y)
{
	if (side == 0 && raydir_x > 0)
		g->current_text_id = 3; //EST
	else if (side == 0 && raydir_x < 0)
		g->current_text_id = 2; //OVEST
	else if (side == 1 && raydir_y > 0)
		g->current_text_id = 1; //SUD
	else if (side == 1 && raydir_y < 0)
		g->current_text_id = 0;//NORD
}

void	find_floor_position_on_wallbase(t_ray *r)
{
	if (r->side == 0 && r->raydir_x > 0)
	{
		r->floor_wall_x = r->map_x;
		r->floor_wall_y = r->map_y + r->wall_x;
	}
	else if (r->side == 0 && r->raydir_x < 0)
	{
		r->floor_wall_x = r->map_x + 1.0;
		r->floor_wall_y = r->map_y + r->wall_x;
	}
	else if (r->side == 1 && r->raydir_y > 0)
	{
		r->floor_wall_x = r->map_x + r->wall_x;
		r->floor_wall_y = r->map_y;
	}
	else if (r->side == 1 && r->raydir_y < 0)
	{
		r->floor_wall_x = r->map_x + r->wall_x;
		r->floor_wall_y = r->map_y + 1.0;
	}
}

