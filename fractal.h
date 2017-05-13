/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alohashc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 11:04:03 by alohashc          #+#    #+#             */
/*   Updated: 2017/03/27 14:51:34 by alohashc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_H
# define FRACTAL_H
# include <stdlib.h>
# include <math.h>
# include "mlx.h"
# include <pthread.h>
# include "./libft/libft.h"
# define M 0
# define J 1
# define S 2
# define B 3
# define N 4

typedef struct		s_win
{
	void			*mlx;
	void			*win;
	void			*img;
}					t_win;

typedef struct		s_data
{
	int				x;
	int				y;
	int				z;
	int				i;
	double			min_x;
	double			min_y;
	double			max_x;
	double			max_y;
	double			pi;
	double			pr;
	double			c_im;
	double			c_re;
	double			flag;
	double			o_re;
	double			o_im;
	double			n_re;
	double			n_im;
	double			step_x;
	double			step_y;
	int				max_iter;
	int				wd;
	int				ht;
	void			*mlx;
	void			*win;
	void			*img;
	char			*data;
	int				bpp;
	int				size_l;
	int				endian;
	int				a;
	int				r;
	int				g;
	int				b;
	int				color;
	int				marker;
}					t_data;

/*
** fractal functions
*/

void				ft_create_threads(t_data **d, int marker);
void				ft_create_fractal(t_data d);
void				*ft_julia(void *data);
void				*ft_mandelbrot(void *data);
void				ft_create_julia();
void				ft_create_mandelbrot();
void				ft_create_carpet();
void				ft_create_burning();
void				ft_create_newton();
void				ft_step(t_data *d);
void				*ft_carpet(void *data);
void				*ft_burning(void *data);
void				*ft_newton(void *data);

/*
** draw functions
*/

void				draw_pixel(t_data d, int x, int y, int c);
void				ft_set_color(t_data *color);
int					ft_get_color(int i, t_data *wi);
void				ft_string_put(t_data *d);

/*
** event functions
*/

int					ft_press_key(int keycode, t_data **fr);
int					ft_mouse_press(int button, int x, int y, t_data **fr);
int					ft_mouse(int x, int y, t_data **fr);
void				ft_scale(t_data **fr, double x, double y, double mult);
void				ft_reset(t_data **fr);

/*
** math functions
*/

double				ft_raznost_kv(double a, double b);
double				ft_sum_kv(double a, double b);

#endif
