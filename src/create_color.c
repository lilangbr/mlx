/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebresser <ebresser@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 15:15:18 by ebresser          #+#    #+#             */
/*   Updated: 2021/08/14 15:16:19 by ebresser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);	
}

int	get_opposite(int t, int r, int g, int b)
{
	
	int ro, go, bo;

	ro = g / 2 + b / 2;
	go = r / 2 + b / 2;	
	bo = r / 2 + g / 2;

	return (create_trgb(t, ro, go, bo));
}