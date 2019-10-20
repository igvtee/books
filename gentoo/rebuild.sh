rm /etc/portage/package.*
rm -rf /var/log/portage/*

emerge --sync
emerge --update --newuse --deep --changed-deps --with-bdeps=y @system
etc-update
emerge -up sys-kernel/gentoo-sources
* upgrade/rebuild kernel
emerge --update --newuse --deep --changed-deps --with-bdeps=y @world
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
