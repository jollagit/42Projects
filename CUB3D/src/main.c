#include "cub3d.h"

int	draw_walls(t_game *g)
{
	int	x;

	x = 0;
	while (x < WIN_W)
	{
		cast_ray(g, x);
		x++;
	}
	return (0);
}

t_game	init_struct_game(void)
{
	t_game	g = {0};

	g.posX = 12;
	g.posY = 12;
	g.dirX = -1;
	g.dirY = 0;
	g.planeX = 0;
	g.planeY = 0.66;

	g.mlx = mlx_init();
	g.win = mlx_new_window(g.mlx, WIN_W, WIN_H, "cub3d - base raycasting");
	g.img.img = mlx_new_image(g.mlx, WIN_W, WIN_H);
	g.img.addr = mlx_get_data_addr(g.img.img, &g.img.bpp, &g.img.line_len, &g.img.endian);

	g.texture[0] = load_texture(g.mlx, "./images/wall1.xpm");
	g.texture[1] = load_texture(g.mlx, "./images/wall2.xpm");
	g.texture[2] = load_texture(g.mlx, "./images/wall3.xpm");
	g.texture[3] = load_texture(g.mlx, "./images/wall4.xpm");
	g.texture[4] = load_texture(g.mlx, "./images/ceil.xpm");
	g.texture[5] = load_texture(g.mlx, "./images/floor.xpm");
	g.current_text_id = 0;
	return (g);
}

int main (void)
{
	int	x;
	int	y;
	t_game g;

	// inizializzazione
	x = 0;
	y = 0;
	g = init_struct_game();
	int worldMap[MAP_W][MAP_H] = { // la mappa comunque la ricevo dal parsing
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,1,0,0,1,1,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,1,1,1,0,0,0,1,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,1,1,0,0,1,0,1},
		{1,0,0,0,0,0,1,0,0,0,0,0,1,1,1,0,0,1,0,0,0,1,0,1},
		{1,0,1,1,1,0,0,0,0,0,1,0,1,0,0,0,0,1,1,1,0,1,1,1},
		{1,1,1,0,0,0,1,1,1,0,1,0,0,0,1,1,1,1,0,0,0,0,0,1},
		{1,0,0,0,0,0,1,0,0,0,0,1,1,1,1,0,0,0,0,1,1,0,0,1},
		{1,0,1,1,1,1,1,0,0,1,0,0,0,0,1,0,1,1,0,1,1,0,0,1},
		{1,0,0,0,0,1,1,0,0,1,1,1,1,0,0,0,1,1,0,1,1,1,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	};

	while (y < MAP_H)
	{
		x = 0;
		while (x < MAP_W)
		{
			g.map[y][x] = worldMap[y][x];
			x++;
		}
		y++;
	}

	mlx_loop_hook(g.mlx, check_and_move, &g);
	mlx_hook(g.win, 2, 1L<<0, key_press, &g);
	mlx_hook(g.win, 3, 1L<<1, key_release, &g);
	mlx_hook(g.win, 17, 0, close_window, &g);
	mlx_loop(g.mlx);
	//free_map(&g);
	return (0);
}

