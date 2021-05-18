SRC_DIR	:= srcs/
OBJ_DIR	:= obj/
OBJ_DIRS = $(addprefix $(OBJ_DIR), io hooks parsing raycasting sprites tools)
PRE_SRCS = 	io/main io/exit io/init \
			hooks/hooks hooks/hooks_moves \
			parsing/parsing_errors parsing/parsing_map \
			parsing/parsing_params parsing/parsing_utils parsing/textures \
			raycasting/raycast_h_lines raycasting/raycast_v_lines \
			raycasting/raycaster raycasting/walls \
			sprites/sprites_draw sprites/sprites_map sprites/sprites \
			tools/color tools/minimap tools/save tools/tools

SRCS = $(addsuffix .c, $(addprefix $(SRC_DIR), $(PRE_SRCS)))
OBJS = $(addsuffix .o, $(addprefix $(OBJ_DIR), $(PRE_SRCS)))
NAME = cub3D
CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror
THFLAGS = -lpthread -D_REENTRANT
INC =	-I./inc

.PHONY: all clean fclean re all

all: libft	$(NAME)

libft: 
	@$(MAKE) -C ./../libft

$(NAME): $(OBJ_DIRS) $(OBJS) ./../libft/libft.a
	@$(CC) $(CFLAGS) $(THFLAGS) $(OBJS) $(INC) -L. -lmlx ../libft/libft.a -o $(NAME) 
	@echo "\033[32mCud3D done\033[0m"

$(OBJ_DIRS):
	@mkdir -p $(OBJ_DIRS)

$(OBJS) : inc/cub3d.h ../libft/libft.h

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$@ \033[32mcreated\033[0m"

clean:
	@rm -rf $(OBJ_DIR)
	@$(MAKE) clean -C ../libft

fclean: 	clean
	@rm -f $(NAME)
	@$(MAKE) fclean -C ../libft

re:		fclean all
