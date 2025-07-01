#ifndef CUB3D_H
# define CUB3D_H
# include <unistd.h>
# include <math.h>
# include <stdlib.h>
# include <mlx.h>
# include <mlx_int.h>
# include <X11/X.h>
# include <X11/keysym.h>

#define WIN_W 640
#define WIN_H 480
#define MAP_W 24
#define MAP_H 24
#define KEY_W      119
#define KEY_S      115
#define KEY_A      97
#define KEY_D      100
#define KEY_LEFT 65361
#define KEY_RIGHT 65363
#define KEY_ESC 65307
#define	MOVE_SPEED 0.05
#define ROT_SPEED 0.01
#define	CEIL_ID 4
#define	FLOOR_ID 5

typedef struct s_keys
{
	int	w;
	int	s;
	int	a;
	int	d;
	int left;
	int right;
}t_keys;

typedef struct s_texture
{
	void *imge;
	char *addr;
	int  width;
	int  height;
	int  bpp;
	int  line_len;
	int  endian;

}t_texture;

typedef struct s_ray
{
	int text_x;
	int	text_y;
	int	hit;
	int	side;
	int	map_x;
	int	map_y;
	int	step_x;
	int	step_y;
	int	height;
	int	draw_start;
	int	draw_end;
	int	floor_tex_x;
	int	floor_tex_y;
	int	ceil_tex_x;
	int	ceil_tex_y;
	double	wall_x;
	double	floor_wall_x;
	double	floor_wall_y;
	double	camera_x;
	double	raydir_x;
	double	raydir_y;
	double	sidedist_x;
	double	sidedist_y;
	double	deltadist_x;
	double	deltadist_y;
	double	walldist;
}t_ray;

typedef struct s_data // struttura usate per scrivere pixel (my_mlx_pixel_put) e passarla a (mlx_put_image_to_window) per disegnare
{
	void *img;
	char *addr; // (mlx_get_data_addr) serve per accedere/modificare i pixel
	int bpp; // bit per pixel (di solito 32, ogni pixel ha 4 byte)
	int line_len; // lunghezza in byte di una riga dell'immagine
	int endian;
}t_data;

typedef struct s_game // per gestire lo stato del gioco
{
	void *mlx;
	void *win;
	t_keys keys;
	t_data img; // contiene l'immagine su cui disegnamo -> la struttura vista sopra
	t_texture texture[6];
	int		current_text_id;
	double posX, posY;
	double dirX, dirY;
	double planeX, planeY;// definisce la larghezza del campo visivo
	int map[MAP_W][MAP_H];
	int	mouse_x;
}t_game;

void		movements(t_game *g);
int			draw_walls(t_game *g);
void		rotatation(t_game *g);
int			close_window(t_game *g);
int			check_and_move(t_game *g);
void		cast_ray(t_game *g, int x);
int			key_press(int key, t_game *g);
int			key_release(int key, t_game *g);
void		dda_algoritm(t_game *g, t_ray *r);
t_texture	load_texture(void *mlx, char *path);
void		init_ray(t_game *g, t_ray *r, int x);
void		draw_map(t_game *g, t_ray *r, int x);
void		find_floor_position_on_wallbase(t_ray *r);
void		find_wall_parameters(t_game *g, t_ray *r);
void		calculate_init_step_sidedist(t_game *g, t_ray *r);
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
void		find_id_texture(t_game *g, int side, double raydir_x, double raydir_y);

#endif