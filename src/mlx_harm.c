/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebresser <ebresser@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 20:12:37 by ebresser          #+#    #+#             */
/*   Updated: 2021/08/10 22:16:00 by ebresser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/cub3D.h"

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

static void	my_mlx_pixel_put(t_data *data, int x, int y, int color) //because mlx_pp is very very slow
{
	char	*dst; //acho q é o meu pixel


	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8)); //corrijo o endereço - n é contiguo!
	*(unsigned int*)dst = color; //endereço na imagem guarda valor da cor (conteudo do endereço é preenchido c valor)
}
static void draw (t_data *img) //como eu decidi a rota do meu preenchimento
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
			my_mlx_pixel_put(img, x, y, (r << 16) + (g << 8) ); //0x00FF0000
			x = x + 1;
		}
		x = 150;
		y = y + 1;
		g = g - 2;
	}
}

static void draw2 (t_data *img) //SOH FIZ ISSO!
{
	int x, y, b, g;
	
	x = 250;
	y = 250;
	b = 255;
	g = 255;

	while ( y < 350 )
	{
		while ( x < 350 )
		{
			my_mlx_pixel_put(img, x, y, b + (g << 8) ); //very very slow! 0x00FF0000
			x = x + 1;
		}
		x = 250;
		y = y + 1;
		g = g - 2;
	}
}
int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 600, 600, "Vai dar certo! Confia!");
	img.img = mlx_new_image(mlx, 600, 600);//init img
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	//my_mlx_pixel_put(&img, 5, 5, 0x00FF0000); //SUBSTITUI AQUI DO TUTORIAL PELA MINHA FUNCAO DRAW
	draw (&img); // < - MINHA FUNCAO
	draw2 (&img);
    mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}

/* Guardar no coração:
void    put_pixel(t_img *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->size_l + x * (data->bpp / 8));
    *(unsigned int *)dst = color;
}

int    pick_pixel(t_img *data, int x, int y)
{
    char    *dst;

    dst = data->addr + (y * data->size_l + x * (data->bpp / 8));
    return (*(unsigned int *)dst);
}
*/
