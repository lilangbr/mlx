/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebresser <ebresser@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 13:51:32 by ebresser          #+#    #+#             */
/*   Updated: 2021/08/15 15:57:10 by ebresser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int close_win(t_cub *cub)
{
	printf(":::::::::::WINDOW CLOSED!!::::::::::: \n");
	printf("___________Program finished___________\n");
    mlx_destroy_window(cub->vars->mlx, cub->vars->win); //desaloca win
    
	free(cub->vars->mlx);
	free(cub->vars);
	//free(cub->img->img);
	//free(cub->img->addr);
	//free(cub->img);
		
	//return (0);
    

	exit (0);

}