#!/bin/sh

# .xinitrc
# Shell script thet is called automatically when starting the X server
# by decrovert

xrandr --dpi 115
hsetroot -solid "#242424"
setxkbmap pt

sxhkd &
picom &

exec tinywm
