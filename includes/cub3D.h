/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebresser <ebresser@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 20:14:07 by ebresser          #+#    #+#             */
/*   Updated: 2021/08/15 17:33:01 by ebresser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libs/libft/libft.h"
# include "../libs/minilibx-linux/mlx.h"
# include "../libs/minilibx-linux/mlx_int.h"
# include <errno.h>

# define ESC_KEY 0x00ff1b
# define W_KEY 0x0077
# define S_KEY 0x0073
# define A_KEY 0x0061
# define D_KEY 0x0064
# define RIGHT_KEY 0x00ff53
# define LEFT_KEY 0x00ff51

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct	s_cub
{
	t_vars			*vars; //map & file
	t_data			*img;
	t_data			*img2;
}				t_cub;

int	create_trgb(int t, int r, int g, int b);
int	get_opposite(int t, int r, int g, int b);
void my_mlx_pixel_put(t_data *data, int x, int y, int color);
void draw_bkgd (t_data *img);
void draw_square1 (t_data *img);
void draw_square2 (t_data *img);
void draw_triangle (t_data *img);
void draw_opposite (t_data *img);
int	key_hook(int keycode, t_vars *vars);
int close_win(t_cub *cub);
int new_frame(t_cub *cub);



#endif
