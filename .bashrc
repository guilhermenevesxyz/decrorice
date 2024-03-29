#!/bin/bash

# .bashrc
# Configuration for the bash shell
# by decrovert

# If not running interactively, don't do anything
[[ $- != *i* ]] && return

## VARIABLES ##
# Color constants
YELLOW="\e[33m"
GREEN="\e[32m"
BLUE="\e[34m"
RESET_COLOUR="\e[0m"

# PS1 variable
PS1="${GREEN}\u${RESET_COLOUR}@${BLUE}\w${RESET_COLOUR} \$ "

## ALIASES ##
# Improved commands
alias \
    ls="ls -h --color=auto --group-directories-first" \
    grep="grep --color=auto" \
    diff="diff --color=auto" \
    mkdir="mkdir -pv" \
    rm="rm -Iv" \
    mv="mv -iv" \
    cp="cp -iv" \
    pacman="pacman --color=auto"

# New command names
alias \
    cls="clear"

## FUNCTIONS (aliases will not work here) ##
# This function should be used inside every other function
# to let the user know which commands the function is running.
run_command_explicit() {
    echo -e "${YELLOW}running:${RESET_COLOUR} $*" && eval $*
}

print_bashrc() {
    run_command_explicit "cat ~/.bashrc | less"
}

pacman_remove_unused() {
    run_command_explicit "doas pacman --color=auto -Rsn $(pacman -Qdtq)"
}

# Execute commands
decrofetch
