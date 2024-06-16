#include "so_long.h"

int	destroy(t_data *data)
{
	mlx_destroy_window(data->mlx, data->window);
	exit(0);
	return (0);
}

int	keypress(int key, t_data *data)
{
	if (key == 65307)
	{
		mlx_destroy_window(data->mlx, data->window);
		exit(0);
	}
	return (0);
}

// 65307 è l'escape key

// int	keypress(int key, t_data *data)
// {
// 	(void)data;
// 	printf("Pressed key: %d\\n", key);
// 	return (0);
// }

// int	destroy(t_data *data)
// {
// 	mlx_destroy_window(data->mlx, data->window);
// 	mlx_destroy_display(data->mlx);
// 	free(data->mlx);
// 	exit(0);
// 	return (0);
// }