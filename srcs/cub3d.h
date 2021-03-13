/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yer-raki <yer-raki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 05:11:54 by yer-raki          #+#    #+#             */
/*   Updated: 2021/01/31 16:42:40 by yer-raki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <math.h>
# include <string.h>
# include "mlx.h"
# include "get_next_line.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>

# define TILE_SIZE 32
# define MINIMAP_SCALE 0.3
# define TILE_SIZE_P 15

# define FOV_ANGLE 1.0472

# define WITH_MAX 2560
# define HEIGHT_MAX 1440

# define ROTATE_LEFT 123
# define ROTATE_RIGHT 124
# define FORWARD_W 13
# define BACK_S 1
# define RIGHT_D 2
# define LEFT_A 0
# define ESC 53

typedef struct		s_sprite
{
	float			x;
	float			y;
	float			x_offset;
	float			y_offset;
	float			d;

}					t_sprite;

float	*g_ray_d;
int		g_arg_save;

typedef struct		s_data
{
	char			hit_type;
	double			h_v;
	double			h_w;
	double			v_v;
	double			v_w;
	int				nb_row;
	int				nb_col;
	char			**map;
	int				r;
	int				rx;
	int				ry;
	int				num_start_map;
	int				p;
	int				c;
	int				f;
	int				no;
	int				so;
	int				we;
	int				ea;
	int				s;
	char			*s_no;
	char			*s_so;
	char			*s_we;
	char			*s_ea;
	char			*s_s;
	int				f_rgb_r;
	int				f_rgb_g;
	int				f_rgb_b;
	int				c_rgb_r;
	int				c_rgb_g;
	int				c_rgb_b;
	void			*mlx_ptr;
	void			*mlx_win;
	void			*img;
	char			*addr;
	int				bpp;
	int				line_l;
	int				endian;
	char			n_p;
	double			px;
	double			py;
	double			p_rotationangle;
	double			p_rotationspeed;
	int				p_movespeed;
	int				turn_d;
	int				walk_d;
	int				walk_r;
	int				c_px;
	int				c_py;
	double			xinter_h;
	double			yinter_h;
	double			xinter_v;
	double			yinter_v;
	double			d_h;
	double			d_v;
	double			d;
	double			xdelta_h;
	double			ydelta_h;
	double			xdelta_v;
	double			ydelta_v;
	double			disprojplane;
	double			wallstripheight;
	int				t_wh[5];
	int				t_ht[5];
	void			*t_img[5];
	int				*addr_t_img[5];
	int				nb_sp;
	float			sp_x;
	float			sp_y;
}					t_data;

void				upload_info(char *file_name, t_data *tmp);
char				**ft_split(char const *s, char c);
int					name_map(char *str);
int					ft_strcmp(char *s1, char *s2);
char				*ft_strrchr(const char *s, int c);
void				errors_msg(int c);
int					check_point(char *str);
void				r_file(t_data *tmp, char *file_name);
void				u_resolution(char *line, t_data *tmp);
int					check_file(char *line);
int					ft_atoi(const char *s);
int					name_save(char *str);
void				u_menu(char	*line, t_data *tmp);
int					char_map(char *line);
void				copy_map(t_data *tmp, char *file_name);
int					check_line_map(t_data *tmp, char *line);
void				init(t_data *tmp);
void				check_map(t_data *tmp);
void				init_map(t_data *tmp);
void				draw_square(t_data *tmp, int i, int j, int color);
void				my_mlx_pixel_put(t_data *data, int x, int y, int color);
void				player(t_data *tmp);
void				draw_map1(t_data *tmp);
void				draw_straight(t_data *tmp);
double				fix_angle(double angle);
int					key_hook(int keycode, t_data *tmp);
void				init_straight(t_data *tmp);
char				ray_facing_ud(t_data *tmp);
char				ray_facing_rl(t_data *tmp);
double				total_nb_delta_h(t_data *tmp);
double				total_nb_delta_v(t_data *tmp);
int					check_wall(t_data *tmp, double x, double y, int keycode);
int					check_wall2(t_data *tmp, double x, double y);
int					check_wall3(t_data *tmp, double x, double y);
void				draw_rays(t_data *tmp);
void				draw_walls(t_data *tmp, int i, int j, int color);
void				u_f(char *line, t_data *tmp, int i);
void				u_c(char *line, t_data *tmp, int i);
void				minimap_player(t_data *tmp);
int					rgb_to_int(int r, int g, int b);
void				path_textures_no(char *line, t_data *tmp);
void				path_textures_so(char *line, t_data *tmp);
void				path_textures_we(char *line, t_data *tmp);
void				path_textures_ea(char *line, t_data *tmp);
char				*ft_strcpy(char *dest, char *src);
void				free_t2(char **w, int i);
void				textures(t_data *tmp);
void				count_sprites(t_data *tmp);
void				sprite_info(t_data *tmp, t_sprite *t);
void				sort_sprites(t_data *tmp, t_sprite *t);
void				sprite_calcul(t_data *tmp, t_sprite *t, int i);
void				draw_sprite(t_data *tmp, t_sprite *t, int k, float sp_size);
void				save_img(t_data *tmp);
int					ft_isdigit(char *s);
void				move_player(t_data *tmp, int keycode);
void				u_resolution2(t_data *tmp);
int					ft_strlen2(char **w);
int					get_texture_index(t_data *tmp);
void				path_textures_s(char *line, t_data *tmp);
void				u_map(char *line, t_data *tmp);
float				calcul_offset(t_data *tmp, int i);
size_t				ft_strlen3(const char *str);
#endif
