/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebresser <ebresser@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 15:58:18 by ebresser          #+#    #+#             */
/*   Updated: 2021/08/15 17:04:44 by ebresser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int new_frame(t_cub *cub)
{   
    //texturas
    int		img_width;
	int		img_height;
    char	*relative_path = "./textures/doom_3.XPM";

    

	if (cub->vars->mlx && cub->img->img)
		mlx_destroy_image(cub->vars->mlx, cub->img->img );
	
    
    //texturas : olhar path direito!
    cub->img->img = mlx_xpm_file_to_image(cub->vars->mlx, relative_path, &img_width, &img_height);
    

    /*desenho  ok
    cub->img->img = mlx_new_image(cub->vars->mlx, 600, 600);//init img
	cub->img->addr = mlx_get_data_addr(cub->img->img, &(cub->img->bits_per_pixel),\
		&(cub->img->line_length), &(cub->img->endian));
	draw_bkgd (cub->img);
	draw_square1 (cub->img);
	draw_square2 (cub->img);
	draw_opposite (cub->img);
	draw_triangle (cub->img);
    */


    
    mlx_put_image_to_window(cub->vars->mlx, cub->vars->win, cub->img->img, 0, 0);

	return (0);
}