NAME 			= so_long
CC				=	cc
CFLAGS		=	-Wall -Werror -Wextra
RM				= rm -f

SRCS_DIR 	= src
OBJS_DIR 	= obj
INCS_DIR	= include
MLX_DIR 	= ./mlx
MLX_LIB 	= $(MLX_DIR)/libmlx_$(UNAME).a

SRCS 			= $(SRCS_DIR)/so_long.c $(SRCS_DIR)/main.c
OBJS			= $(SRCS:$(SRCS_DIR)/%.c=$(OBJS_DIR)/%.o)

ifeq ($(shell uname), Linux)
	INCLUDES = -I/usr/include -Imlx
else
	INCLUDES = -I/opt/X11/include -Imlx
endif

ifeq ($(shell uname), Linux)
	MLX_FLAGS = -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11
else
	MLX_FLAGS = -Lmlx -lmlx -L/usr/X11/lib -lXext -lX11 -framework OpenGL -framework AppKit
endif

all: $(MLX_LIB) $(NAME)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -I$(INCS_DIR) $(INCLUDES) -c $< -o $@ 

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX_FLAGS)

$(MLX_LIB):
	@make -C $(MLX_DIR)

clean:
	$(RM) -r $(OBJS_DIR)
 
fclean: clean
	$(RM) $(NAME)
	make -C $(MLX_DIR) clean

re: fclean all

.PHONY: all clean fclean re