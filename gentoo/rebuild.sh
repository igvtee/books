rm /etc/portage/package.*
rm -rf /var/log/portage/*
* remove no need packages

emerge --sync
* upgrade/rebuild kernel
emerge -up gentoo-sources
eselect kernel set
emerge --update --newuse --deep --changed-deps --with-bdeps=y @world
* or
emerge --update --newuse --deep --changed-deps @world
etc-update
elogv
emerge --depclean
perl-cleaner --all
emerge @preserved-rebuild
eclean -d distfiles
rm -rf /usr/portage/distfiles/*
fstrim -Av

=== tips ===
emerge --ask @x11-module-rebuild
emerge --ask --autounmask-write media-sound/spotify

sys-kernel/linux-headers
sys-libs/glibc
