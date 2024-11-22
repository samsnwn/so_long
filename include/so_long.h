#ifndef SO_LONG_H
# define SO_LONG_H


#include "../mlx/mlx.h"
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

#define WIDTH 1250
#define HEIGHT 800

typedef struct s_player
{
	int	y;
	int	x;

}             t_player;

typedef struct s_img
{
	void	*empty;
	void	*collectible;
	void	*wall;
	void	*exit;
	void	*player_left1;
	void	*player_right1;
	void	*player_up1;
	void	*player_down1;
	void	*player_left2;
	void	*player_right2;
	void	*player_up2;
	void	*player_down2;
	void	*enemy;
}t_img;

typedef struct s_map
{
	int			fd;
	char		*line;
	char		*file;
	char		**array;
	char		**copy;
	char		*filename;
	int			y;
	int			x;
	int			e;
	int			c;
	int			c_check;
	int			e_check;
	int			p;
	int			exit;
	int			moves;
	void		*mlx;
	void		*wnd;
	t_img		img;
	t_player	player;

}t_map;

#endif
