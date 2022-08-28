SRCS  = ./src/cube3d_utiles/free.c ./src/cube3d_utiles/ft_isprint.c ./src/cube3d_utiles/ft_lstlast.c ./src/cube3d_utiles/ft_lstsize.c \
		./src/cube3d_utiles/ft_putstr.c ./src/cube3d_utiles/ft_strchr.c ./src/cube3d_utiles/ft_strlen.c ./src/cube3d_utiles/ft_strnstr.c \
		./src/cube3d_utiles/get_next_line.c ./src/cube3d_utiles/ft_atoi.c ./src/cube3d_utiles/ft_lstadd_back.c ./src/cube3d_utiles/ft_lstnew.c \
		./src/cube3d_utiles/ft_memset.c ./src/cube3d_utiles/ft_split.c ./src/cube3d_utiles/ft_strlcpy.c ./src/cube3d_utiles/ft_strncmp.c \
		./src/cube3d_utiles/ft_strtrim.c ./src/cube3d_utiles/get_next_line_utils.c ./src/mini_map/parse_minimap.c ./src/mini_map/minimap_utiles.c \
		./src/mini_map/print_map.c ./src/parsing_map/parcing_utiles.c ./src/parsing_map/parcing_utiles1.c ./src/raycasting/raycasting.c \
		./src/raycasting/raycasting_utils.c ./src/cube3d.c ./src/errors/error.c ./src/draw_line.c ./src/hooks/player_move.c ./src/hooks/hooks.c \
		./src/hooks/player_move_utiles.c ./src/errors/free_functions.c ./src/parsing_map/map_parcing.c ./src/raycasting/rays_distance.c \
		./src/raycasting/intersection_steps.c ./src/raycasting/raycasting_utils_2.c ./src/raycasting/render_floor_ceil.c ./src/textures/textures.c \
		./src/cube3d_utiles/ft_substr.c

OBJ = $(SRCS:.c=.o)
 
NAME= cube3d

HEADERS = includes/cube3d.h includes/structs.h

CC = cc

FLAGS = -Wall -Wextra -Werror 
MFLAGS = -lmlx -framework OpenGL -framework AppKit -lm

all: $(NAME)

%.o : %.c $(HEADERS)
	@$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJ)
	@$(CC) $(FLAGS) $(OBJ) $(MFLAGS) -o $(NAME)


clean:
	@rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: clean all

.PHONY : all clean fclean re 
