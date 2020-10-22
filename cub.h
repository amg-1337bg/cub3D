/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamghoug <bamghoug@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 09:44:19 by bamghoug          #+#    #+#             */
/*   Updated: 2020/05/08 16:03:03 by bamghoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H
# include <stdlib.h>
# include <mlx.h>
# include <math.h>
# include <fcntl.h>
# include <unistd.h>
# include "libft/libft.h"
# include <stdio.h>
# include <string.h>

# define BUFFER_SIZE 1024

typedef struct	s_data
{
	void		*img;
	char		*img_add;
	int			bpp;
	int			ll;
	int			endian;
}				t_data;

typedef struct	s_sp
{
	int			x_map;
	int			y_map;
	float		x;
	float		y;
	float		dist;
}				t_sp;

typedef struct	s_resol
{
	int			x;
	int			y;
	char		**dimens;
	int			x_map;
	int			y_map;
	int			x_tile;
	int			y_tile;
}				t_resol;

typedef struct	s_inte
{
	float		h_xint;
	float		h_yint;
	float		v_xint;
	float		v_yint;
	float		v_xstep;
	float		v_ystep;
	float		h_xstep;
	float		h_ystep;
	float		h_dist;
	float		v_dist;
	float		sp_xinterc;
	float		sp_yinterc;
	int			l_r;
	int			up_down;
	int			vert_horz;
}				t_intercepts;

typedef struct	s_text
{
	char		*no_tex;
	char		*so_tex;
	char		*we_tex;
	char		*ea_tex;
	char		*sp_tex;
}				t_texs;

typedef struct	s_wall_cal
{
	float		wallheight;
	float		dpp;
	int			y_begin;
}				t_wall_calc;

typedef struct	s_textures
{
	void		*xp_img;
	int			*img_addr;
	int			w;
	int			h;
	int			bpp;
	int			sl;
	int			end;
	float		sp_x;
	float		sp_y;
	float		sp_dist;
}				t_textures;

typedef struct	s_error
{
	char		*map_error;
	char		*resol_error;
	char		*text_error;
	char		*color_error;
	char		*arg_error;
	char		*file_error;
	char		*other;
}				t_errors;

typedef struct	s_player
{
	float		x;
	float		y;
	int			fov;
	float		pov;
	float		pov_hit;
	int			dir;
	int			speed;
	float		move_speed;
	float		rot_speed;
}				t_player;

typedef struct	s_colors
{
	int			f_red;
	int			f_green;
	int			f_blue;
	int			f_rgb;
	int			c_red;
	int			c_green;
	int			c_blue;
	int			c_rgb;
}				t_colors;

t_sp			*g_sp;
t_data			g_data;
t_intercepts	g_inte;
t_wall_calc		g_walls;
t_textures		g_ntext;
t_textures		g_stext;
t_textures		g_wtext;
t_textures		g_etext;
t_textures		g_sptext;
t_errors		g_errors;
t_player		g_t_play;
t_resol			g_resol;
t_colors		g_colors;

int				g_first_map;
int				g_dim_ind;
float			*g_raydist;
int				g_counter;
int				g_empty_line;
int				g_on;
int				g_num_sp;
int				g_sp_index;
void			*g_init_ptr;
void			*g_win_ptr;
int				g_mheight;

int				check(char *string);
char			*before_n(char *s);
char			*after_n(char *s);
int				get_next_line(int fd, char **line);
int				work_todo(int fd, char *buf, char **line);
int				rest_check(char *res, char **line);
void			initial_interc(t_colors *colors, t_texs *text);
void			initial_errors(void);
void			initial_colors(t_colors *colors);
void			initial_text(t_texs *text);
void			get_resol(t_resol *res, char *line);
char			*get_path(char *line, char *texture);
void			get_textures(t_texs *textus, char *line);
void			get_f_colors(t_colors *colors, char *line);
void			get_c_colors(t_colors *colors, char *line);
void			get_colors(t_colors *colors, char *line);
void			check_first_map(char *line);
void			error(int i);
char			*line_filter(char *line);
void			get_map(t_resol *s_resol, char *line);
void			get_configs(t_resol *s_resol, t_texs *textus,
t_colors *colors, char *file);
void			mpp(t_data *g_data, int x, int y, int color);
int				check_next_pos(double x, double y, t_resol *s_resol);
void			angle_facing(float angle, int *left_right, int *up_down);
void			horz_inter(t_resol *s_resol, float angle);
void			vert_inter(t_resol *s_resol, float angle);
float			cast(t_resol *s_resol, float angle);
void			normalize_angle(float *angle);
void			calculations(t_resol *s_resol, float angle, float fov);
int				sprite_pos(double x, double y, t_resol *s_resol);
int				get_color(int x, int y);
void			initial_pov(char c);
int				sprite_tranc(int x, int y, int size);
void			render_sp(int x, int y, int size, int i);
void			sprites(t_resol *s_resol);
void			get_sp_coor(t_sp *sp, float angle);
void			swap(int f, int t);
void			sort(void);
void			draw(t_resol *s_resol, int x1, float y_begin, int y1);
void			handle_player(t_resol *s_resol);
int				check_next_pos(double x, double y, t_resol *s_resol);
int				deal_key(int key, t_resol *s_resol);
void			find_player_pos(t_resol *s_resol);
int				stop(int key);
void			sprite_ptr(t_texs *s_text);
void			handle_textures(t_texs *s_text);
void			ft_render(t_resol *s_resol, t_texs *s_text);
void			change_val(int key, float *a);
void			bmp_image(t_resol s_resol, t_texs *s_text);
void			create_head(t_resol s_resol, int fd, int *pad);
void			initial_configs(void);
void			update_dist(float angle);
void			initial_sp(t_resol *s_resol);
void			render_for_saving(t_resol *s_resol);
void			check_colors(t_colors *colors);
void			check_first_map(char *line);
void			check_map(t_resol *s_resol);
void			search(t_resol *s_resol, t_texs *textus,
t_colors *colors, char *line);
void			check_others(t_resol *s_resol, t_texs *textus,
t_colors *colors, int *on);
void			ignor_spaces(char *line, int *f, int *l);
void			verify(char *line, int f, int l);
void			looking_for_ones(char *line, int f, int *b, int *a);
void			space_looking(t_resol *s_resol, int i, int f, int l);
void			space_back_looking(t_resol *s_resol, int i, int f, int l);
void			check_length(t_resol *s_resol, int ind);
void			check_back_length(t_resol *s_resol, int ind);
void			check_file_name(char *file_name);
void			check_args(char *cub, char *save, int i);
int				get_resol_val(char *line);
void			first_last(char *line);
int				get_color_val(char *line, int i);
int				red_cross(int key);
void			ignor_sp_dig(char *str, int *i);
void			check_forme(char *st, int i);
void			allocation(void);
void			map_hei(t_resol *s_resol, t_texs *textus,
t_colors *colors, char *line);
void			search_map(t_resol *s_resol, char *line);
void			get_the_map(t_resol *s_resol, char *file);

#endif
