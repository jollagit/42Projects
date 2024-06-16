#include "so_long.h"

int	main(void)
{
	t_data	data;
	int		width;
	int		height;
	
	width = 0;
	height = 0;
	get_size_window(&width, &height);
	data.mlx = mlx_init();
	if (!data.mlx)
		return (1);
	data.window = mlx_new_window(data.mlx, width, height, "hi :)");
	if (!data.window)
		return (free(data.mlx), 1);
	put_image(data.mlx, data.window);
	mlx_hook(data.window, 2, 1L << 0, &keypress, &data);
	mlx_hook(data.window, 17, 0L, &destroy, &data);
	mlx_loop(data.mlx);
	return (0);
}

//". c #A4C263",

/*int	main(void)
{
	t_data	data;
	void	*image;
	void	*image2;
	int		size;

	size = 48;
	data.mlx = mlx_init();
	if (!data.mlx)
		return (1);
	data.window = mlx_new_window(data.mlx, 600, 400, "hi :)");
	if (!data.window)
		return (free(data.mlx), 1);
	image = mlx_xpm_file_to_image(data.mlx,
			"./assets/Water.xpm", &size, &size);
	if (!image)
		return (free(data.mlx), 1);
	image2 = mlx_xpm_file_to_image(data.mlx, "./assets/sprite_1.xpm", &size, &size);
	if (!image2)
		return (free(data.mlx), 1);
	mlx_put_image_to_window(data.mlx, data.window, image, 0, 0);
	mlx_put_image_to_window(data.mlx, data.window, image2, 48, 48);
	mlx_hook(data.window, 2, 1L << 0, &keypress, &data);
	mlx_hook(data.window, 17, 0L, &destroy, &data);
	mlx_loop(data.mlx);
	return (0);
}*/

/*.mlx permette di accedere all'elemento mlx nella struttura data
/ mlx_init() inizializza la mlx libreria a mette il putatore
riportato nell'elemento mlx.
collega gli eventi KeyPress e DestroyNotify alle funzioni di callback:
2 è il codice evento della finestra per KeyPress
1L<<0 è una maschera binaria, indica che vuoi ascoltare eventi di
pressione dei tasti.
17 è il codice evento della finestra per DestroyNotify
generato quando la finestra viene chiusa.
0L indica che non c'è una maschera per questo evento
viene ascoltato implicitamente.
Loop finche non incontra una condizione di termine
(come la chiusura della finestra)*/