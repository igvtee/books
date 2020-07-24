export XMODIFIERS="@im=fcitx"
export QT_IM_MODULE=fcitx
export GTK_IM_MODULE=fcitx

[[ -f ~/.Xresources ]] && xrdb -merge ~/.Xresources

# chinese input
fcitx-autostart

# launch unicode-rxvt daemon
urxvtd --quiet --opendisplay --fork

exec awesome
