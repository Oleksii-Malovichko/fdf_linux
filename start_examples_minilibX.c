/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_examples_minilibX.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 14:14:12 by alex              #+#    #+#             */
/*   Updated: 2024/12/13 20:04:50 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx-linux/mlx.h"
#include <stdio.h>
#include <stdlib.h>

int	close_window(void *param)
{
	(void)param;
	exit(0);
	return (0);
}

int main()
{
	void	*mlx;
	void	*window;
	int		sizex = 1000;
	int		sizey = 600;
	void	*img;
	char	*addr;
	int 	bpp, line_length, endian;
	int 	color = 0x0000FF; // blue
	
	mlx = mlx_init();
	if (!mlx)
		return (1);
		
	printf("x: %d; y: %d\n", sizex, sizey);
	window = mlx_new_window(mlx, 500, 300, "MiniLibX Windows");

	mlx_clear_window(mlx, window); // очистить окно от пред красок

	img = mlx_new_image(mlx, sizex, sizey);
	addr = mlx_get_data_addr(img, &bpp, &line_length, &endian);
	printf("bpp: %d, line_length: %d, endian: %d\n", bpp, line_length, endian);
	for (int j = 0; j < sizey; j++) // Цикл по высоте
    {
        for (int i = 0; i < sizex; i++) // Цикл по ширине
        {
            int pixel_pos = j * line_length + i * (bpp / 8);
            *(int *)(addr + pixel_pos) = color; // Устанавливаем цвет
        }
    }
	mlx_put_image_to_window(mlx, window, img, 0, 0);
	mlx_hook(window, 17, 0, close_window, NULL);
	mlx_loop(mlx);
	return (0);
}
	// mlx_string_put(mlx, window, 50, 50, 0x39E06B, "Hello, MiniLibX!");
	// mlx_pixel_put(mlx, window, 100, 100, 0x0000FF);
	// mlx_pixel_put(mlx, window, 150, 150, 0xFF0000);
	// mlx_pixel_put(mlx, window, 200, 200, 0x00FF00);