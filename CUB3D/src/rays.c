#include "cub3d.h"

void	dda_algoritm(t_game *g, t_ray *r)
{
	while (r->hit == 0)
	{
		if (r->sidedist_x < r->sidedist_y)
		{
			r->sidedist_x += r->deltadist_x;
			r->map_x += r->step_x;
			r->side = 0;
		}
		else
		{
			r->sidedist_y += r->deltadist_y;
			r->map_y += r->step_y;
			r->side = 1;
		}
		if (g->map[r->map_y][r->map_x] > 0)
			r->hit = 1;
	}
}

void	calculate_init_step_sidedist(t_game *g, t_ray *r)
{
	if (r->raydir_x < 0)
	{
		r->step_x = -1;
		r->sidedist_x = (g->posX - r->map_x) * r->deltadist_x;
	}
	else
	{
		r->step_x = 1;
		r->sidedist_x = (r->map_x + 1.0 - g->posX) * r->deltadist_x;
	}
	if (r->raydir_y < 0)
	{
		r->step_y = -1;
		r->sidedist_y = (g->posY - r->map_y) * r->deltadist_y;
	}
	else
	{
		r->step_y = 1;
		r->sidedist_y = (r->map_y + 1.0 - g->posY) * r->deltadist_y;	
	}
}

void	init_ray(t_game *g, t_ray *r, int x)
{
	r->camera_x = 2 * x / (double)WIN_W -1;
	r->raydir_x = g->dirX + g->planeX * r->camera_x;
	r->raydir_y = g->dirY + g->planeY * r->camera_x;
	r->map_x = (int)g->posX;
	r->map_y = (int)g->posY;
	r->deltadist_x = fabs(1 / r->raydir_x);
	r->deltadist_y = fabs(1 / r->raydir_y);
	calculate_init_step_sidedist(g, r);
}

void	find_wall_parameters(t_game *g, t_ray *r)
{
	if (r->side == 0)
		r->walldist = r->sidedist_x - r->deltadist_x;
	else
		r->walldist = r->sidedist_y - r->deltadist_y;
	
	if (r->side == 0)
		r->wall_x = g->posY + r->walldist * r->raydir_y;
	else
		r->wall_x = g->posX + r->walldist * r->raydir_x;
	r->wall_x -= floor(r->wall_x); //solo la parte decimale del valore 
	r->text_x = 0;
	r->height = (int)(WIN_H / r->walldist);
	r->draw_start = -r->height / 2 + WIN_H / 2;
	if (r->draw_start < 0)
		r->draw_start = 0;
	r->draw_end = r->height / 2 + WIN_H / 2;
	if (r->draw_end >= WIN_H)
		r->draw_end = WIN_H - 1;
	r->text_x = (int)(r->wall_x * (double)g->texture[g->current_text_id].width);
	if ((r->side == 0 && r->raydir_x > 0) || (r->side == 1 && r->raydir_y < 0))
		r->text_x = g->texture[g->current_text_id].width - r->text_x - 1;
}

void	cast_ray(t_game *g, int x)
{
	t_ray	r = {0};

	init_ray(g, &r, x);
	dda_algoritm(g, &r);
	find_id_texture(g, r.side, r.raydir_x, r.raydir_y);
	find_wall_parameters(g, &r);
	draw_map(g, &r, x);
}
