NAME		=	fractol
BONUS		=	fractol_bonus
CC			=	cc
CFLAGS		=	-Wextra -Wall -Werror -Wunreachable-code # -Ofast -g
DFLAGS		= 	-g -fsanitize=address,undefined,integer
LIBMLX_DIR	=	./lib/MLX42
LIBFT_DIR	=	./lib/libft
GLFW_DIR	=	/usr/local/lib
LIBMLX		= 	$(LIBMLX_DIR)/build/libmlx42.a
LIBFT		=	$(LIBFT_DIR)/libft.a
LIBS		=	$(LIBMLX) -lm -lglfw -lm -lGL #-L$(GLFW_DIR) -lglfw -lm -lGL
#LIBS		=	-lm -L/usr/local/lib -lGL -lm -L$(LIBFT_DIR) -lft -lglfw # -L"/Users/$(USER)/.brew/opt/glfw/lib/" $(LIBMLX)/build/libmlx42.a -lglfw -framework OpenGL -framework IOKit
SRC_DIR		=	./srcs
SRCS		=	fractol.c		draw.c	hooks.c		math_utils.c	color.c			color_utils.c	\
				color_shift.c	error.c	zoom.c		ft_atod.c		my_put_pixel.c
INC_DIRS	= 	./incs $(LIBMLX_DIR)/include/MLX42 $(LIBFT_DIR)/libft $(LIBFT_DIR)/ft_printf/incs /usr/local/Cellar/glfw/include
INCS		=	$(foreach dir, $(INC_DIRS), -I $(dir))
OBJ_DIR		=	./objs
OBJS		=	$(SRCS:%.c=$(OBJ_DIR)/%.o)

$(OBJ_DIR)/%.o:	$(SRC_DIR)/%.c
				$(CC) $(CFLAGS) $(INCS) -c $< -o $@

all:			libmlx $(LIBFT) $(NAME)

bonus:			libmlx $(LIBFT) $(BONUS)

$(LIBMLX): 		.libmlx

.libmlx:		#clone_mlx42
				@cmake $(LIBMLX_DIR) -B $(LIBMLX_DIR)/build 
				make -C $(LIBMLX_DIR)/build -j4

clone_mlx42:
				if [ ! -d "$(LIBMLX_DIR)" ]; then \
					git clone https://github.com/codam-coding-college/MLX42.git $(LIBMLX_DIR); \
				fi

$(LIBFT):
				@make -C $(LIBFT_DIR) all

$(OBJ_DIR):
				@mkdir -p $(OBJ_DIR)

debug: 			CFLAGS += $(DFLAGS)
debug:			all

$(NAME):		$(LIBFT) $(LIBMLX) $(OBJ_DIR) $(OBJS)
				@echo "Linking $(NAME)..."
				@echo "LIBS: $(LIBS)"
				@$(CC) $(CFLAGS) $(INCS) $(OBJS) $(LIBFT) $(LIBS) -o $(NAME)

$(BONUS):		$(LIBFT) $(LIBMLX) $(OBJ_DIR) $(OBJS)
				@echo "Linking $(BONUS)..."
				@$(CC) $(CFLAGS) $(INCS) $(OBJS) $(LIBFT) $(LIBS) -o -o $(BONUS)

clean:
				@rm -rf $(OBJ_DIR)
				@make -C $(LIBFT_DIR) clean
				@rm -rf $(LIBMLX_DIR)/build

fclean:			clean
				@rm -rf $(NAME)
				@rm -rf $(BONUS)
				@make -C $(LIBFT_DIR) fclean

re:				fclean all

.PHONY: 		all bonus clean fclean re libmlx libft
