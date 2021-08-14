/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebresser <ebresser@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 15:18:02 by ebresser          #+#    #+#             */
/*   Updated: 2021/08/14 15:22:56 by ebresser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color) //because mlx_pp is very very slow
{
	char	*dst; //acho q é o meu pixel


	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8)); //corrijo o endereço - n é contiguo!
	*(unsigned int*)dst = color; //endereço na imagem guarda valor da cor (conteudo do endereço é preenchido c valor)
}


void draw_bkgd (t_data *img) //SOH FIZ ISSO!
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
void draw_square1 (t_data *img) //como eu decidi a rota do meu preenchimento
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
void draw_square2 (t_data *img) //SOH FIZ ISSO!
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
void draw_triangle (t_data *img) //SOH FIZ ISSO!
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
void draw_opposite (t_data *img) //SOH FIZ ISSO!
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