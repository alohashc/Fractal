/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alohashc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/26 18:30:09 by alohashc          #+#    #+#             */
/*   Updated: 2017/03/27 15:00:05 by alohashc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	ft_usage(void)
{
	ft_putendl("\033\e[91musage: ./fractol <name fractal>");
	ft_putendl("\033\e[91mor");
	ft_putendl("\033\e[91musage: ./fractol <name fractal> <name fractal>");
	ft_putendl("\033\e[33musage: [Mandelbrot]");
	ft_putendl("       [Julia]");
	ft_putendl("       [Carpet]");
	ft_putendl("       [Newton]");
	ft_putendl("       [Burning]");
	exit(0);
}

int		ft_check_fractal(char **av)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (++i <= 2)
	{
		if (!(ft_strcmp(av[i], "Mandelbrot") == 0))
			count++;
		if (!(ft_strcmp(av[i], "Julia") == 0))
			count++;
		if (!(ft_strcmp(av[i], "Carpet") == 0))
			count++;
		if (!(ft_strcmp(av[i], "Burning") == 0))
			count++;
		if (!(ft_strcmp(av[i], "Newton") == 0))
			count++;
	}
	if (count == 10 || count == 9)
		return (0);
	return (1);
}

void	ft_chose_fractal(char *av)
{
	if (ft_strcmp(av, "Mandelbrot") == 0)
		ft_create_mandelbrot();
	else if (ft_strcmp(av, "Julia") == 0)
		ft_create_julia();
	else if (ft_strcmp(av, "Carpet") == 0)
		ft_create_carpet();
	else if (ft_strcmp(av, "Burning") == 0)
		ft_create_burning();
	else if (ft_strcmp(av, "Newton") == 0)
		ft_create_newton();
	else
		ft_usage();
}

void	ft_create_threads(t_data **d, int marker)
{
	pthread_t	*tid;
	int			i;

	i = -1;
	tid = (pthread_t*)malloc(sizeof(pthread_t) * 8);
	while (++i < 8)
		if (marker == M)
			pthread_create(&tid[i], NULL, ft_mandelbrot, &d[i]);
		else if (marker == J)
			pthread_create(&tid[i], NULL, ft_julia, &d[i]);
		else if (marker == S)
			pthread_create(&tid[i], NULL, ft_carpet, &d[i]);
		else if (marker == B)
			pthread_create(&tid[i], NULL, ft_burning, &d[i]);
		else if (marker == N)
			pthread_create(&tid[i], NULL, ft_newton, &d[i]);
	i = -1;
	while (++i < 8)
		pthread_join(tid[i], NULL);
	mlx_put_image_to_window(d[0]->mlx, d[0]->win, d[0]->img, 0, 0);
	ft_string_put(*d);
	mlx_hook(d[0]->win, 6, 0, ft_mouse, d);
	mlx_mouse_hook(d[0]->win, ft_mouse_press, d);
	mlx_hook(d[0]->win, 2, 5, ft_press_key, d);
	mlx_loop(d[0]->mlx);
}

int		main(int ac, char **av)
{
	pid_t pid;

	if (ac == 2)
		ft_chose_fractal(av[1]);
	else if (ac == 3)
	{
		if (ft_check_fractal(av) == 1)
		{
			pid = fork();
			if (pid == -1)
				exit(EXIT_FAILURE);
			if (pid == 0)
				ft_chose_fractal(av[1]);
			else
				ft_chose_fractal(av[2]);
		}
		else
			ft_usage();
	}
	else
		ft_usage();
	return (0);
}
