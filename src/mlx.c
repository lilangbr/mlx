/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebresser <ebresser@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 20:12:37 by ebresser          #+#    #+#             */
/*   Updated: 2021/08/14 21:26:21 by ebresser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/cub3D.h"

static void	vars_in_heap(t_cub *cub)
{
	cub->vars = ft_calloc(1, (sizeof(t_vars) + 1)); //cub ja eh um endereço, já declarei. vars ainda n é
	//dou a ele um endereço q aponta para uma struct. +1 -> shadow bytes
	if (cub->vars == NULL)
		exit(1);
}
static void	img_in_heap(t_cub *cub)
{
	cub->img = ft_calloc(1, (sizeof(t_data) + 1)); //cub ja eh um endereço, já declarei. img ainda n é
	//dou a ele um endereço q aponta para uma struct. +1 -> shadow bytes
	if (cub->img == NULL)
		exit(1);
}

static int close_win(t_vars *vars)
{
	printf(":::::::::::WINDOW CLOSED!!::::::::::: \n");
	printf("_______Program still running________\n");
	mlx_destroy_window(vars->mlx, vars->win); //n precisa desalocar, só fecha a jan. Prog cont
	return (0);

}

static int	key_pressed(int keycode, t_vars *vars)
{
	
	printf("You've pressed this key: %d (see key_hook) \n", keycode);
	if (keycode == ESC_KEY)
		close_win (vars);
	return (0);
}

int	main(void)
{
	t_cub cub;

	vars_in_heap(&cub);
	img_in_heap(&cub);
	cub.vars->mlx = mlx_init(); //init dele alocar	
	cub.vars->win = mlx_new_window(cub.vars->mlx, 600, 600, "Vai dar certo! Confia!");
	cub.img->img = mlx_new_image(cub.vars->mlx, 600, 600);//init img
	cub.img->addr = mlx_get_data_addr(cub.img->img, &(cub.img->bits_per_pixel),\
		&(cub.img->line_length), &(cub.img->endian));
	//my_mlx_pixel_put(&img, 5, 5, 0x00FF0000); //SUBSTITUI AQUI DO TUTORIAL PELA MINHA FUNCAO DRAW
	draw_bkgd (cub.img);
	draw_square1 (cub.img); // < - MINHA FUNCAO
	draw_square2 (cub.img);
	draw_opposite (cub.img);
	draw_triangle (cub.img);
    mlx_put_image_to_window(cub.vars->mlx, cub.vars->win, cub.img->img, 0, 0);
	//mlx_key_hook(cub.vars->win, key_hook, &(cub.vars)); //função no arg é chamada sempre 
	//que um evento é disparado. corrigir minim/maximiz com mlx_loop_hook(atualiza a tela)
	
	
	//mlx_hook(cub->window_ptr, 2, 1L << 0, key_pressed, cub);
	//mlx_hook(cub->window_ptr, 3, 1L << 1, key_released, cub);
	mlx_hook(cub.vars->win, 2, 1L << 0, key_pressed, cub.vars); //instead of calling mlx_key_hook, 
	//we can also register to the KeyPress and KeyRelease events.
	mlx_hook(cub.vars->win, 33, 1L << 17, close_win, cub.vars); //AQUI DA PAU, PQ??
	


	mlx_loop(cub.vars->mlx);

	free(cub.vars->win);
	free(cub.vars->mlx);
	free(cub.vars);
	free(cub.img->img);
	free(cub.img->addr);
	free(cub.img);
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
