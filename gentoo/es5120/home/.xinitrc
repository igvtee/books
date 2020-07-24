export LANG="zh_TW.UTF-8"
export LC_ALL="zh_TW.UTF-8"
export LC_CTYPE="zh_TW.UTF-8"
export XIM_PROGRAM=gcin
export GTK_IM_MODULE=gcin
export XIM=gcin
export XMODIFIERS="@im=gcin"

exec dbus-launch --sh-syntax --exit-with-session openbox-session
