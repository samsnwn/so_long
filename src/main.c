#include "../include/so_long.h"
#include <stdio.h> // Include for fprintf
#include <sys/stat.h> // Include for stat

int	ft_close(t_map *map)
{
	mlx_destroy_window(map->mlx, map->wnd);
	exit(EXIT_SUCCESS);
	return (0);
}

int main()
{
  // t_map map;

  void  *mlx_connection;
  void  *mlx_window;
  void  *mlx_image;
  int width;  // Declare width variable
  int height; // Declare height variable

  mlx_connection = mlx_init();
  if (mlx_connection == NULL) {
      fprintf(stderr, "Error initializing MLX\n");
      return 1;
  }

  mlx_window = mlx_new_window(mlx_connection, WIDTH, HEIGHT, "My first texture");
  if (mlx_window == NULL) {
      fprintf(stderr, "Error creating window\n");
      return 1;
  }

  mlx_image = mlx_xpm_file_to_image(mlx_connection, "assets/Grass_02-128x128.xpm", &width, &height);
  if (mlx_image == NULL) {
      fprintf(stderr, "Error loading image\n");
      return 1; // Exit or handle the error appropriately
  }

  mlx_put_image_to_window(mlx_connection, mlx_window, mlx_image, 0, 0);

  // mlx_hook (mlx_connection, 17, 0, ft_close, &map);
  mlx_loop(mlx_connection);
}