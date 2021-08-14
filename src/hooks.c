/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebresser <ebresser@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 17:31:18 by ebresser          #+#    #+#             */
/*   Updated: 2021/08/14 17:57:11 by ebresser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	key_hook(int keycode, t_vars *vars)
{
    t_vars *p;

    //como pegar click do mouse?
    p = vars;

	printf("You've pressed this key: %d (see key_hook) \n", keycode);
    return (0);
}
