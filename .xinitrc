#!/bin/sh

# .xinitrc
# Shell script thet is called automatically when starting the X server
# by decrovert

xrandr --dpi 115
hsetroot -solid "#242424"

# keyboard configuration
setxkbmap -layout pt,no # add layouts
setxkbmap -option
setxkbmap -option "grp:win_space_toggle"

sxhkd &
picom &

exec decrowm
