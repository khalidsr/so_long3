#include "so_long.h"

int	key_hook(int keycode, t_vars *vars)
{
	int temp_x = 70;
	char *filname;
	char *filname2;
	void *imag;
	void *imag2;
	
	filname = "/Users/sriyani/Desktop/so_long/player.XPM";
	filname2 = "/Users/sriyani/Desktop/so_long/sea.XPM";
	imag = mlx_xpm_file_to_image(vars->mlx_ptr, filname, &temp_x, &temp_x);
	imag2 = mlx_xpm_file_to_image(vars->mlx_ptr, filname2, &temp_x, &temp_x);
	if(keycode == 13 && vars->ar[vars->pos_x - 1 ][vars->pos_y] != '1'  && vars->ar[vars->pos_x - 1 ][vars->pos_y] != 'E')
	{
		ft_count();
		mlx_put_image_to_window(vars->mlx_ptr, vars->mlx_win, imag, vars->pos_y * 70 ,(vars->pos_x * 70) - 70);
		mlx_put_image_to_window(vars->mlx_ptr, vars->mlx_win, imag2, vars->pos_y * 70 ,vars->pos_x * 70);
		vars->pos_x--;
		if(vars->ar[vars->pos_x][vars->pos_y] == 'N')
			ft_lose();
		if(vars->ar[vars->pos_x][vars->pos_y] == 'C')
			vars->c_len--;
		vars->ar[vars->pos_x][vars->pos_y] = '0';		
	}
	else if (keycode == 13 && vars->ar[vars->pos_x - 1 ][vars->pos_y] == 'E')
		ft_win(vars);
	key_hook2(keycode, vars);
	return (0);
}

int	key_hook2(int keycode, t_vars *vars)
{	
	int temp_x = 70;
	char *filname;
	char *filname2;
	void *imag;
	void *imag2;
	
	filname = "/Users/sriyani/Desktop/so_long/player.XPM";
	filname2 = "/Users/sriyani/Desktop/so_long/sea.XPM";
	imag = mlx_xpm_file_to_image(vars->mlx_ptr, filname, &temp_x, &temp_x);
	imag2 = mlx_xpm_file_to_image(vars->mlx_ptr, filname2, &temp_x, &temp_x);
	if(keycode == 1 && vars->ar[vars->pos_x + 1][vars->pos_y] != '1' && vars->ar[vars->pos_x + 1][vars->pos_y] != 'E')
	{
		ft_count();
		mlx_put_image_to_window(vars->mlx_ptr, vars->mlx_win, imag, vars->pos_y * 70 ,(vars->pos_x * 70) + 70);
		mlx_put_image_to_window(vars->mlx_ptr, vars->mlx_win, imag2, vars->pos_y * 70 ,vars->pos_x * 70);
		vars->pos_x++;
		if(vars->ar[vars->pos_x][vars->pos_y] == 'N')
			ft_lose();
		if(vars->ar[vars->pos_x][vars->pos_y] == 'C')
			vars->c_len--;
		vars->ar[vars->pos_x][vars->pos_y] = '0';
	}
	else if(keycode == 1 && vars->ar[vars->pos_x + 1][vars->pos_y] == 'E')
		ft_win(vars);
	 key_hook3(keycode, vars);
	return (0);
}

int key_hook3(int keycode, t_vars *vars)
{
	int temp_x = 70;
	char *filname;
	char *filname2;
	void *imag;
	void *imag2;

	filname = "/Users/sriyani/Desktop/so_long/player.XPM";
	filname2 = "/Users/sriyani/Desktop/so_long/sea.XPM";
	imag = mlx_xpm_file_to_image(vars->mlx_ptr, filname, &temp_x, &temp_x);
	imag2 = mlx_xpm_file_to_image(vars->mlx_ptr, filname2, &temp_x, &temp_x);
	if(keycode == 0 && vars->ar[vars->pos_x ][vars->pos_y - 1] != '1' && vars->ar[vars->pos_x ][vars->pos_y - 1] != 'E')
	{
		ft_count();
		mlx_put_image_to_window(vars->mlx_ptr, vars->mlx_win, imag, (vars->pos_y * 70) - 70 ,(vars->pos_x * 70));
		mlx_put_image_to_window(vars->mlx_ptr, vars->mlx_win, imag2, vars->pos_y * 70 ,vars->pos_x * 70);
		vars->pos_y--;
		if(vars->ar[vars->pos_x ][vars->pos_y] == 'N')
			ft_lose();
		if(vars->ar[vars->pos_x][vars->pos_y] == 'C')
			vars->c_len--;
		vars->ar[vars->pos_x][vars->pos_y] = '0';
	}
	else if(keycode == 0 &&  vars->ar[vars->pos_x ][vars->pos_y - 1] == 'E')
		ft_win(vars);
	 key_hook4(keycode, vars);
	 return 0;
}  
int key_hook4(int keycode, t_vars *vars)
{
	int temp_x = 70;
	char *filname;
	char *filname2;
	void *imag;
	void *imag2;
	
	filname = "/Users/sriyani/Desktop/so_long/player.XPM";
	filname2 = "/Users/sriyani/Desktop/so_long/sea.XPM";
	imag = mlx_xpm_file_to_image(vars->mlx_ptr, filname, &temp_x, &temp_x);
	imag2 = mlx_xpm_file_to_image(vars->mlx_ptr, filname2, &temp_x, &temp_x);
	if(keycode == 2 &&  vars->ar[vars->pos_x ][vars->pos_y + 1] != '1' &&  vars->ar[vars->pos_x ][vars->pos_y + 1] != 'E'  )
	{
		ft_count();
		mlx_put_image_to_window(vars->mlx_ptr, vars->mlx_win, imag, (vars->pos_y * 70) + 70,vars->pos_x * 70);
		mlx_put_image_to_window(vars->mlx_ptr, vars->mlx_win, imag2, vars->pos_y * 70 , vars->pos_x * 70);
		vars->pos_y++;
		if(vars->ar[vars->pos_x][vars->pos_y] == 'N')
			ft_lose();
		if(vars->ar[vars->pos_x][vars->pos_y] == 'C')
		{
			vars->c_len--;
			vars->ar[vars->pos_x][vars->pos_y] = '0';
		}
	}
	else if(keycode == 2 && vars->ar[vars->pos_x ][vars->pos_y + 1 ] == 'E')
		ft_win(vars);
	return (0);	
}

void ft_solong(t_vars vars, char **s, int colone, int line)
{

	vars.c_len = ft_pos_collecte(&vars, vars.ar);
	put_wall(vars, s, vars.x, vars.y);
	mlx_string_put(vars.mlx_ptr, vars.mlx_win, 420, 0, 0x0000FF00,ft_itoa(ft_count()));
	put_player(vars, s, vars.x, vars.y);
	put_enemy(vars, s, vars.x, vars.y);
	put_colllectible(vars, s, vars.x, vars.y);
	put_exit(vars, s, vars.x, vars.y);
	mlx_hook(vars.mlx_win, 2, 1L << 0, ft_close, &vars);
	mlx_hook(vars.mlx_win, 17, 1L << 17, &ft_mouse_hook, &vars);
	ft_position(&vars,s);
	ft_pos_collecte(&vars,s);
	mlx_key_hook(vars.mlx_win, key_hook, &vars);
	mlx_loop(vars.mlx_ptr);
	
}

int	main(int ac,char **av)
{
	
	t_vars vars;
	int line;
	char **s;
	void *img;
	int colonne;
	int fd;

	fd = open(av[1], O_RDONLY);
		ft_error_fd(fd);
	colonne = ft_map_colonne(av);
	line = ft_map_line(av);
	vars.x = (colonne * 70);
	vars.y = (line * 70);
	s = convert(&vars, av, fd);
	vars.mlx_ptr = mlx_init();
	vars.mlx_win = mlx_new_window(vars.mlx_ptr, vars.x, vars.y,"./so_long");
	vars.img = mlx_new_image(vars.mlx_ptr, vars.x, vars.y);
	ft_check_map(s);
	ft_check_map2(s,line,colonne);
	ft_check_map3(av,s, line, colonne);
	ft_check_map4(ac, av);
	put_sea(vars, colonne, line);
	ft_solong(vars, s, vars.x, vars.y);
	
return 0;
}
