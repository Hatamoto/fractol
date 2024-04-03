NAME		=	fractol
BONUS		=	fractol_bonus
CC			=	cc
CFLAGS		=	-Wextra -Wall -Werror -Wunreachable-code -Ofast -g
DFLAGS		= 	-g
LIBMLX		=	./lib/MLX42
LIBS		=	-lm -lglfw -L "/Users/$(USER)/.brew/opt/glfw/lib/" $(LIBMLX)/build/libmlx42.a -framework OpenGL -framework OpenGL -framework IOKit
INC_DIRS	= 	./incs ./lib/MLX42/include/MLX42 ./lib/libft/libft ./lib/libft/ft_printf/incs
INCS		=	$(foreach dir, $(INC_DIRS), -I $(dir))
SRC_DIR		=	./srcs
SRCS		=	fractol.c		draw.c	hooks.c		math_utils.c	color.c			color_utils.c	\
				color_shift.c	error.c	zoom.c		ft_atod.c		my_put_pixel.c
OBJ_DIR		=	./objs
OBJS		=	$(SRCS:%.c=$(OBJ_DIR)/%.o)
LIBFT_DIR	=	./lib/libft
LIBFT		=	$(LIBFT_DIR)/libft.a

$(OBJ_DIR)/%.o:	$(SRC_DIR)/%.c
				$(CC) $(CFLAGS) $(INCS) -c $< -o $@

all:			libmlx $(NAME)

bonus:			libmlx $(BONUS)

clone_mlx42:
				if [ ! -d "$(LIBMLX)" ]; then \
					git clone https://github.com/codam-coding-college/MLX42.git "$(LIBMLX)"; \
				fi

libmlx:			clone_mlx42
				@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

debug: 			CFLAGS += $(DFLAGS)
debug:			all

$(NAME):		$(LIBFT) $(OBJ_DIR) $(OBJS)
				@$(CC) $(OBJS) $(LIBFT) $(LIBS) $(CFLAGS) -o $(NAME)

$(BONUS):		$(LIBFT) $(OBJ_DIR) $(OBJS)
				@$(CC) $(OBJS) $(LIBFT) $(LIBS) $(CFLAGS) -o $(BONUS)

$(LIBFT):
				make -C $(LIBFT_DIR) all

$(OBJ_DIR):
				mkdir -p $(OBJ_DIR)

clean:
				rm -rf $(OBJ_DIR)
				make -C $(LIBFT_DIR) clean
				@rm -rf $(LIBMLX)

fclean:			clean
				@rm -rf $(NAME)
				@rm -rf $(BONUS)
				rm -f $(LIBFT)

re:				fclean all

.PHONY: 		all bonus clean fclean re libmlx libft