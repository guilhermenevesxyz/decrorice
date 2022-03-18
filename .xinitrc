#!/bin/sh

# .xinitrc
# Shell script thet is called automatically when starting the X server
# by decrovert

X_USER_RESOURCES=$HOME/.Xresources
X_SYSTEM_RESOURCES=/etc/X11/xinit/.Xresources
X_SCRIPTS=/etc/X11/xinit/xinitrc.d

AUTOSTART_SCRIPT=$HOME/dox/scripts/x_autostart.sh

# Merge in defaults and keymaps
if [ -f $X_SYSTEM_RESOURCES ]; then
    xrdb -merge $X_SYSTEM_RESOURCES
fi

if [ -f $X_USER_RESOURCES ]; then
    xrdb -merge $X_USER_RESOURCES
fi

# Run some system scripts
if [ -d $X_SCRIPTS ]; then
    for f in $X_SCRIPTS/?*.sh; do
        [ -x $f ] && . $f
    done

    unset f
fi

# Run the autostart script
if [ -f $AUTOSTART_SCRIPT ]; then
    sh $AUTOSTART_SCRIPT
fi

# Basic Xorg configuration
xrandr --dpi 115
hsetroot -solid "#242424"
setxkbmap pt

while true; do
    xsetroot -name "$(date +"%A %d/%m/%y %H:%M")"
    sleep 30s
done &

# Window manager
exec dwm
