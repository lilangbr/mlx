/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebresser <ebresser@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 20:12:37 by ebresser          #+#    #+#             */
/*   Updated: 2021/08/08 18:03:30 by ebresser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/cub3D.h"


static int deal_key() //int key, void *param)
{

	ft_putendl_fd("wow!", 1);
	return (0);

}
static void event (void *win, int (*deal_key)())
{
	mlx_key_hook(win, deal_key, (void *) 0);
}

static void draw (void *mlx, void *win)
{
	int x, y, r, g;
	
	x = 150;
	y = 150;
	r = 255;
	g = 255;

	while ( y < 250 )
	{
		while ( x < 250 )
		{
			mlx_pixel_put(mlx, win, x, y, (r << 16) + (g << 8)); //very very slow!
			x = x + 1;
		}
		x = 150;
		y = y + 1;
		g = g - 2;
	}
}

static void test_mlx()
{
	void *mlx;
	void *win;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 500, 500, "cub3D");
	draw (mlx, win);
	event (win, deal_key);
	mlx_loop(mlx); //initiate the window rendering
}


int	main()
{
	
	test_mlx();	
	
	return (0);
}
