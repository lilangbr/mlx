/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebresser <ebresser@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 20:12:37 by ebresser          #+#    #+#             */
/*   Updated: 2021/08/14 12:50:40 by ebresser         ###   ########.fr       */
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

static int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);	
}

static int	get_opposite(int t, int r, int g, int b)
{
	
	int ro, go, bo;

	ro = g / 2 + b / 2;
	go = r / 2 + b / 2;	
	bo = r / 2 + g / 2;

	return (create_trgb(t, ro, go, bo));
}


static void	my_mlx_pixel_put(t_data *data, int x, int y, int color) //because mlx_pp is very very slow
{
	char	*dst; //acho q é o meu pixel


	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8)); //corrijo o endereço - n é contiguo!
	*(unsigned int*)dst = color; //endereço na imagem guarda valor da cor (conteudo do endereço é preenchido c valor)
}
static void draw_square1 (t_data *img) //como eu decidi a rota do meu preenchimento
{
	int x, y, r, g, b, t;
	
	x = 150;
	y = 150;
	r = 255;
	g = 255;
	b = 0;
	t = 255; //Ja coloquei 0, 100, etc, nada altera!!!!! Buglix

	while ( y < 250 )
	{
		while ( x < 250 )
		{
			my_mlx_pixel_put(img, x, y, create_trgb(t, r, g, b) ); //0x00FF0000
			my_mlx_pixel_put(img, x, y, (r << 16) + (g << 8) ); //0x00FF0000
			x = x + 1;
		}
		x = 150;
		y = y + 1;
		g = g - 2;
		//t = t - 10;
	}
}

static void draw_bkgd (t_data *img) //SOH FIZ ISSO!
{
	int x, y, t, r, b, g, aux;
	
	x = 0;
	y = 0;
	r = 10;
	b = 250;
	g = 20;
	t = 255;
	aux = 0;

	while ( y < 600 )
	{
		while ( x < 600 )
		{
			my_mlx_pixel_put(img, x, y, create_trgb(t, r, g, b) ); //very very slow! 0x00FF0000
			x = x + 1;
		}
		x = 0;
		y = y + 1;
		aux = (y % 10)/6;
		r = r + aux;

		
	}
}

static void draw_square2 (t_data *img) //SOH FIZ ISSO!
{
	int x, y, t, r, b, g;
	
	x = 250;
	y = 250;
	r = 0;
	b = 255;
	g = 255;
	t = 255;

	while ( y < 350 )
	{
		while ( x < 350 )
		{
			my_mlx_pixel_put(img, x, y, create_trgb(t, r, g, b) ); //very very slow! 0x00FF0000
			x = x + 1;
		}
		x = 250;
		y = y + 1;
		g = g - 2;
	}
}
static void draw_triangle (t_data *img) //SOH FIZ ISSO!
{
	int x, y, t, r, b, g, base, aux;
	
	x = 350;
	y = 350;
	base = 100;
	aux = 0;
	r = 10;
	b = 40;
	g = 250;
	t = 255;

	while ( y < 450 )
	{
		x = 350 - aux;
		while ( x < (350 + aux))
		{
			my_mlx_pixel_put(img, x, y, create_trgb(t, r, g, b) ); //very very slow! 0x00FF0000
			x = x + 1;
		}
		y = y + 1;	
		aux = (y - 350)/2;	
		b = b + 1;
		
	}
}

static void draw_opposite (t_data *img) //SOH FIZ ISSO!
{
	int x, y, t, r, b, g;
	
	x = 350;
	y = 150;
	r = 255;
	b = 0;
	g = 255;
	t = 255;

	while ( y < 200 )
	{
		while ( x < 450 )
		{
			my_mlx_pixel_put(img, x, y, create_trgb(t, r, g, b) ); //very very slow! 0x00FF0000
			x = x + 1;
		}
		x = 350;
		y = y + 1;		
	}
	while ( y < 250 )
	{
		while ( x < 450 )
		{
			my_mlx_pixel_put(img, x, y, get_opposite(t, r, g, b) ); //very very slow! 0x00FF0000
			x = x + 1;
		}
		x = 350;
		y = y + 1;		
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
	draw_bkgd (&img);
	draw_square1 (&img); // < - MINHA FUNCAO
	draw_square2 (&img);
	draw_opposite (&img);
	draw_triangle (&img);
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
