#include "cub3d.h"

void	rotatation(t_game *g)
{
	double	angle;
	double	oldplane_x;
	double	oldDir_x;

	if (g->keys.left || g->keys.right)
	{
		oldDir_x = g->dirX;
		angle = (g->keys.left - g->keys.right) * ROT_SPEED;
		g->dirX = g->dirX * cos(angle) - g->dirY * sin(angle);
		g->dirY = oldDir_x * sin(angle) + g->dirY * cos(angle);
		oldplane_x = g->planeX;
		g->planeX = g->planeX * cos(angle) - g->planeY * sin(angle);
		g->planeY = oldplane_x * sin(angle) + g->planeY * cos(angle);
	}
	else
		return;
}

void	move_forward_backward(t_game *g)
{
	if (g->keys.w)
	{
		if (!g->map[(int)(g->posY)][(int)(g->posX + g->dirX * MOVE_SPEED)])
			g->posX += g->dirX * MOVE_SPEED;
		if (!g->map[(int)(g->posY + g->dirY * MOVE_SPEED)][(int)(g->posX)])
			g->posY += g->dirY *MOVE_SPEED;
	}
	else if (g->keys.s)
	{
		if (!g->map[(int)(g->posY)][(int)(g->posX - g->dirX * MOVE_SPEED)])
			g->posX -= g->dirX * MOVE_SPEED;
		if (!g->map[(int)(g->posY - g->dirY * MOVE_SPEED)][(int)(g->posX)])
			g->posY -= g->dirY * MOVE_SPEED;
	}
	else
		return;
}

void	movements(t_game *g)
{
	move_forward_backward(g);
	if (g->keys.a)
	{
		if (!g->map[(int)(g->posY)][(int)(g->posX -g->planeX * MOVE_SPEED)])
			g->posX -= g->planeX * MOVE_SPEED;
		if (!g->map[(int)(g->posY - g->planeY * MOVE_SPEED)][(int)(g->posX)])
			g->posY -= g->planeY * MOVE_SPEED;
	}
	else if (g->keys.d)
	{
		if (!g->map[(int)(g->posY)][(int)(g->posX + g->planeX * MOVE_SPEED)])
			g->posX += g->planeX * MOVE_SPEED;
		if (!g->map[(int)(g->posY + g->planeY * MOVE_SPEED)][(int)(g->posX)])
			g->posY += g->planeY * MOVE_SPEED;
	}
	else
		return;
}

//player movement AND rotation
int	check_and_move(t_game *g)
{
	movements(g);
	rotatation(g);
	mlx_destroy_image(g->mlx, g->img.img);
	g->img.img = mlx_new_image(g->mlx, WIN_W, WIN_H);
	g->img.addr = mlx_get_data_addr(g->img.img, &g->img.bpp, &g->img.line_len, &g->img.endian);
	draw_walls(g);
	mlx_put_image_to_window(g->mlx, g->win, g->img.img, 0, 0);
	return (0);
}