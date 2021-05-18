#! /bin/sh
cd cub3d
make | egrep -hiv 'nothing to be done|up to date'
chmod 755 cub3D
echo "\033[32mWelcome to Cub3D\033[0m"
# ./cub3D map/hardcore.cub
./cub3D map/basic.cub
# ./cub3D map/dir_map.cub