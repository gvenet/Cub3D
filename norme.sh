#! /bin/sh
./clear.sh 
echo "\033[32mNorme libft*.c\033[0m"
norminette libft/srcs/printf/*.c
norminette libft/srcs/gnl/*.c
norminette libft/srcs/lib/*.c
echo "\033[32mNorme libft*.h\033[0m"
norminette libft/*.h
echo "\033[32mNorme cub3D*.c\033[0m"
norminette cub3d/srcs/*
echo "\033[32mNorme cub3D*.h\033[0m"
norminette cub3d/inc/*.h