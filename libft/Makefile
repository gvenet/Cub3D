SRC_DIR	:= srcs/
OBJ_DIR	:= obj/
OBJ_DIRS = $(addprefix $(OBJ_DIR), printf gnl lib)
PRE_SRCS = 	lib/ft_atoi lib/ft_bzero lib/ft_calloc lib/ft_isalnum lib/ft_isalpha lib/ft_isascii \
			lib/ft_isdigit lib/ft_isprint lib/ft_memccpy lib/ft_memchr lib/ft_itoa lib/ft_memcmp \
			lib/ft_memcpy lib/ft_memmove lib/ft_memset lib/ft_putchar_fd lib/ft_putnbr_fd lib/ft_putendl_fd \
			lib/ft_putstr_fd lib/ft_split lib/ft_strchr lib/ft_strdup lib/ft_strjoin lib/ft_strlcat \
			lib/ft_strlcpy lib/ft_strlen lib/ft_strmapi lib/ft_strncmp lib/ft_strnstr lib/ft_strrchr \
			lib/ft_strtrim lib/ft_substr lib/ft_tolower lib/ft_toupper lib/ft_strcmp lib/ft_charchr \
			lib/ft_lstadd_back lib/ft_lstadd_front lib/ft_lstclear lib/ft_lstdelone \
			lib/ft_lstiter lib/ft_lstlast lib/ft_lstmap lib/ft_lstnew lib/ft_lstsize \
			printf/arg_c printf/arg_d printf/arg_u printf/arg_s printf/arg_x printf/arg_p \
			printf/arg_perc printf/ft_printf printf/parse printf/select_flags printf/utils \
			gnl/get_next_line gnl/get_next_line_utils

SRCS 	= $(addsuffix .c, $(addprefix $(SRC_DIR), $(PRE_SRCS)))
OBJS 	= $(addsuffix .o, $(addprefix $(OBJ_DIR), $(PRE_SRCS)))

NAME 	= libft.a
CC		= gcc
RM		= rm -rf
CFLAGS 	= -Wall -Wextra -Werror

.PHONY: all clean fclean re all

all: ${NAME}

$(NAME): $(OBJ_DIRS) $(OBJS) 
	@ar rcs ${NAME} ${OBJS}
	@echo "\033[32mlibft.a done\033[0m"

$(OBJ_DIRS):
	@mkdir -p $(OBJ_DIRS)

$(OBJS) : $(INC_DIR)libft.h	

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$@ \033[32mcreated\033[0m"

clean:
	@${RM} ${OBJ_DIR}

fclean:	clean
	@${RM} ${NAME}

re:		fclean all

