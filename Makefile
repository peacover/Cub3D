# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yer-raki <yer-raki@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/30 11:23:31 by yer-raki          #+#    #+#              #
#    Updated: 2021/03/13 12:01:02 by yer-raki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC := @gcc
FLAGS := -Wall -Wextra -Werror 
NAME := cub3D
SRC := ./srcs/get_next_line.c ./srcs/get_next_line_utils.c ./srcs/upload_info.c \
		./srcs/ft_split.c ./srcs/cub3d_utils.c ./srcs/cub3d_utils2.c ./srcs/cub3d_utils3.c \
		./srcs/errors.c ./srcs/d_map.c ./srcs/map_collision_bonus.c ./srcs/save_img.c ./srcs/cub3d_utils4.c \
		./srcs/main.c ./srcs/map.c ./srcs/read_file.c ./srcs/upload_info2.c ./srcs/sprite.c ./srcs/texture.c \
		./srcs/player.c ./srcs/rays.c ./srcs/map2.c 
MLX := -I /usr/share/man/man3 -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit
# MLX := /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit
IMG := image.bmp
all: $(NAME)

$(NAME): $(SRC)
		$(CC) $(FLAGS) $(SRC) $(MLX) -o $(NAME)
clean:
	@rm -rf $(IMG)

fclean: clean
	@rm -rf $(NAME)

re: fclean all