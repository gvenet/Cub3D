#! /bin/sh
cd cub3d/
make
chmod 755 cub3D
./cub3D map/basic.cub | while true; do leaks cub3D; sleep 2; clear; done