#!bin/zsh

autoload -U colors && colors
PS1="%{$fg[red]%}(^w^)%{$reset_color%} %m|@|%~ (%T)"

defaults write com.apple.finder AppleShowAllFiles TRUE

export PATH=/Users/ccatoire/.brew/bin:/Users/ccatoire/.brew/bin:/usr/bin:/bin:/usr/sbin:/sbin:/usr/local/bin:/usr/local/munki:/Users/ccatoire/bin
export PATH=$PATH:~/bin
export EDITOR='emacs'

alias 42='sh ~/42filechecker/42FileChecker.sh'
alias ne='emacs -nw'
alias l='ls -G'
alias ls='ls -G'
alias ll='ls -Gl'
alias la='ls -Gla'
alias cd..='cd ..'
