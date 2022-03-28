#ifndef SO_LONG_H
# define SO_LONG_H

#include "get_next_line.h"

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <mlx.h>

typedef struct s_vars
{
    void    *mlx_ptr;
    void    *mlx_win;
    char    *ptr;
    int     x;
    int     c_len;
    void    *img;
    int     y;
    int     k;
    int     pos_x;
    int     pos_y;
    char    **ar;
}   t_vars;

size_t	ft_strlen(char *str);
int ft_map_line(char **av);
int ft_map_colonne(char **av);
char **convert(t_vars *vars,char **av ,int fd);
void put_sea(t_vars vars,int colonne, int line);
void  put_wall(t_vars vars, char **s,int temp_x, int temp_y);
void  put_player(t_vars vars, char **s, int temp_x, int temp_y);
void  put_colllectible(t_vars vars, char **s, int temp_x, int temp_y);
void  put_exit(t_vars vars, char **s, int temp_x, int temp_y);
void put_enemy(t_vars vars,char **s, int colonne, int line);
int ft_printf(const char *format, ...);
int	ft_strstr(char *str, char *to_find);
void ft_check_map(char **s);
void ft_check_map3(char **av,char **s, int line, int colonne);
void ft_check_map4(int ac, char **av);
void ft_check_map2(char **s,int line,int collone);
void ft_perror(void);
int	key_hook(int keycode, t_vars *vars);
void ft_position(t_vars *vars, char **s);
void ft_win(t_vars *vars);
int	ft_close(int keycode, t_vars *vars);
int	ft_mouse_hook(t_vars *vars);
int ft_pos_collecte(t_vars *vars, char **s);
void ft_solong(t_vars vars, char **s, int colone, int line);
void ft_error_fd(int fd);
int	key_hook(int keycode, t_vars *vars);
int	key_hook2(int keycode, t_vars *vars);
int key_hook3(int keycode, t_vars *vars);
int key_hook4(int keycode, t_vars *vars);
void ft_lose(void);
char	*ft_itoa(int n);
int ft_count(void);
#endif