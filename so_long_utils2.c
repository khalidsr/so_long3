#include "so_long.h"

int	ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	if (to_find[0] == '\0')
	{
		return (0);
	}
	i = 0;
	while (str[i] != '\0')
	{
		j = 0;
		while (to_find[j] == str[i + j])
		{
			if (to_find[j + 1] == '\0')
			{
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}
static int	ft_lenght(int n)
{
	long	len;
	long	num;

	len = 0;
	num = n;
	if (n < 0)
	{
		num = num * (-1);
		len++;
	}
	while (num > 0)
	{
		num /= 10;
		len++;
	}
	return (len);
}

char	*ft_zero(char *p)
{
	p = NULL;
	p = malloc(2 * sizeof(char));
	p[0] = '0';
	p[1] = '\0';
	return (p);
}

char	*ft_itoa(int n)
{
	char		*ptr;
	long int	num;
	long int	len;

	ptr = NULL;
	len = ft_lenght(n);
	if (n == 0)
		return (ft_zero(ptr));
	ptr = malloc ((len + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	ptr[len] = '\0';
	num = n;
	if (n < 0)
	{
		ptr[0] = '-';
		num = num * (-1);
	}
	while (len-- > 0 && num > 0)
	{
		ptr[len] = num % 10 + '0';
		num = num / 10;
	}
	return (ptr);
}

int	ft_mouse_hook(t_vars *vars)
{
	mlx_destroy_image(vars->mlx_ptr, vars->mlx_win);
	exit(0);
	return 0;
}

int	ft_close(int keycode, t_vars *vars)
{
	if(keycode == 53)
	{
		mlx_destroy_window(vars->mlx_ptr, vars->mlx_win);
		exit(0);
	}
	return (0);
}

void ft_position(t_vars *vars,char **s)
{
	int i;
	int j;
	i = 0;
	while(s[i])
	{
		j = 0;
		while(s[i][j])
		{
			if(s[i][j] == 'P')
			{
				vars->pos_x = i;
				vars->pos_y = j;
				break;
			}
			j++;
		}
		i++;
	}
}
void ft_error_fd(int fd)
{
	if(fd < 0)
	{
		perror("error from fd");
		exit(1);
	}	
}

int ft_pos_collecte(t_vars *vars, char **s)
{
	int i;
	int j;
	int len;
	i = 0;
	len = 0;
	while(s[i])
	{
		j = 0;
		while(s[i][j])
		{
			if(s[i][j] == 'C')
				len++;
			j++;
		}
		i++;
	}
	return len;
}

int ft_count(void)
{
	static int count;
	count++;
	ft_printf("|%d|\n",count);
	return count;
}

void ft_win(t_vars *vars)
{
	if(vars-> c_len == 0 && vars->ar[vars->pos_x ][vars->pos_y ] != 'E' )
	{
		ft_printf("you win\n");
		exit(0);
	}

}
void ft_lose(void) 
{
	ft_printf("you lose ! try again ;) ");
	exit(0);

}