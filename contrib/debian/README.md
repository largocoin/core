
Debian
====================
This directory contains files used to package largod/largo-qt
for Debian-based Linux systems. If you compile largod/largo-qt yourself, there are some useful files here.

## largo: URI support ##


largo-qt.desktop  (Gnome / Open Desktop)
To install:

	sudo desktop-file-install largo-qt.desktop
	sudo update-desktop-database

If you build yourself, you will either need to modify the paths in
the .desktop file or copy or symlink your largoqt binary to `/usr/bin`
and the `../../share/pixmaps/largo128.png` to `/usr/share/pixmaps`

largo-qt.protocol (KDE)

