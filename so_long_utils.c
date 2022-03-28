/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sriyani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 14:54:48 by sriyani           #+#    #+#             */
/*   Updated: 2022/03/12 15:04:05 by sriyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void  put_exit(t_vars vars, char **s, int temp_x, int temp_y)
{
	char *filname;
	void *imag;
	int i ;
	int j ;

	i = 0;
	filname = "/Users/sriyani/Desktop/so_long/exit.XPM";
	imag = mlx_xpm_file_to_image(vars.mlx_ptr, filname, &temp_x, &temp_y);
	vars.y = 0;
	while (s[i])
	{
		vars.x = 0;
		j = 0;
		while (s[i][j])
		{	if(s[i][j] == 'E')
				mlx_put_image_to_window(vars.mlx_ptr, vars.mlx_win, imag, vars.x, vars.y);
			vars.x += 70;
			j++;
		}
		i++;
		vars.y += 70;	
	}
}
void  put_colllectible(t_vars vars, char **s, int temp_x, int temp_y)
{
	char *filname;
	void *imag;
	int i;
	int j;

	i = 0;
	filname = "/Users/sriyani/Desktop/so_long/collectible.xpm";
	imag = mlx_xpm_file_to_image(vars.mlx_ptr, filname, &temp_x, &temp_y);
	vars.y = 0;
	while (s[i])
	{
		vars.x = 0;
		j=0;
		while (s[i][j])
		{	if(s[i][j] == 'C')
				mlx_put_image_to_window(vars.mlx_ptr, vars.mlx_win, imag, vars.x, vars.y);
			vars.x += 70;
			j++;
		}
		i++;
		vars.y += 70;	
	}
}
void  put_player(t_vars vars, char **s, int temp_x, int temp_y)
{
	char *filname;
	void *imag;
	int i;
	int j;

	i = 0;
	filname = "/Users/sriyani/Desktop/so_long/player.XPM";
	imag = mlx_xpm_file_to_image(vars.mlx_ptr, filname, &temp_x, &temp_y);
	vars.y = 0;
	while (s[i])
	{
		vars.x = 0;
		j=0;
		while (s[i][j])
		{	if(s[i][j] == 'P')
				mlx_put_image_to_window(vars.mlx_ptr, vars.mlx_win, imag, vars.x, vars.y);
			vars.x += 70;
			j++;
		}
		i++;
		vars.y += 70;	
	}
}
void  put_wall(t_vars vars, char **s, int temp_x, int temp_y)
{
	char *filname;
	void *imag;
	int i;
	int j;

	i = 0;
	filname = "/Users/sriyani/Desktop/so_long/wall.XPM";
	imag = mlx_xpm_file_to_image(vars.mlx_ptr, filname, &temp_x, &temp_y);

	vars.y = 0;
	while (s[i])
	{
		vars.x = 0;
		j = 0;
		while (s[i][j])
		{	if(s[i][j] == '1')
				mlx_put_image_to_window(vars.mlx_ptr, vars.mlx_win, imag, vars.x, vars.y);
			vars.x += 70;
			j++;
		}
		vars.y += 70;
		i++;
	}
}
void put_sea(t_vars vars, int colonne, int line)
{
	
	int temp_x = colonne * 70;
	int temp_y = line * 70;
	void	*imag;
	int i;
	int j;

	char *filname = "/Users/sriyani/Desktop/so_long/sea.XPM";
	imag = mlx_xpm_file_to_image(vars.mlx_ptr, filname, &temp_x, &temp_y);
	i = 0;
	j = 0;
	vars.y = 0;
	while(i < line)
	{
		j = 0;
		vars.x = 0;
		while(j < colonne)
		{
			mlx_put_image_to_window(vars.mlx_ptr, vars.mlx_win, imag, vars.x, vars.y);
			vars.x += 70;
			j++;
		}
		vars.y += 70;
		i++;
	}
}
void put_enemy(t_vars vars, char **s, int temp_x, int temp_y)
{
	char *filname;
	void *imag;
	int i ;
	int j ;

	i = 0;
	filname= "/Users/sriyani/Desktop/so_long/enemy.xpm";
	imag = mlx_xpm_file_to_image(vars.mlx_ptr, filname, &temp_x, &temp_y);
	vars.y = 0;
	while (s[i])
	{
		vars.x = 0;
		j = 0;
		while (s[i][j])
		{	if(s[i][j] == 'N')
				mlx_put_image_to_window(vars.mlx_ptr, vars.mlx_win, imag, vars.x, vars.y);
			vars.x += 70;
			j++;
		}
		vars.y += 70;
		i++;
	}
}
int ft_map_line(char **av)
{
	
	int len = 0;
	char *ptr;
	int fd1 ;
	fd1 = open(av[1], O_RDWR, 0644);
		ft_error_fd(fd1);
	ptr = get_next_line(fd1); 
	while(ptr)
	{
		free(ptr);
		ptr = get_next_line(fd1);
		len++;
	}
	return (len);
}

int ft_map_colonne(char **av)
{
	int i;
	char *str;
	int fd2;

	fd2 = open(av[1], O_RDONLY, 0644);
		ft_error_fd(fd2);
	str = get_next_line(fd2);
	i = ft_strlen(str) - 1; 
	return (i);
}

char	**convert(t_vars *vars, char **av ,int fd)
{
	int len;

	len = ft_map_line(av);
	int i;
	i = 0;
	vars->ar = malloc(sizeof(char *) * len + 1);
	while (i < len)
	{
		vars->ar[i] = get_next_line(fd);
		i++;
	}
	vars->ar[i]= get_next_line(fd);
	return(vars->ar);
}