# Package preparation

The 1.0.0 package recipes are being prepared for three Linux package families:

- Debian and Ubuntu: `gigactl-plasma` depends on upstream's `gigactl` package,
  which currently contains the daemon and GTK desktop tools.
- Fedora and compatible RPM distributions: `gigactl-plasma` depends on the
  standalone `gigactld` RPM recipe in the upstream repository.
- Arch and CachyOS: `gigactl-plasma` depends on the standalone `gigactld`
  `PKGBUILD` in the upstream repository.

The Plasma repository's `v1.0.0` release workflow builds and attaches DEB, RPM
and Arch packages when that tag is pushed. Publish upstream `gigactl` `v1.0.3`
first so its D-Bus API and daemon packages are available to the Plasma packages.
GitHub also provides source-code ZIP and tar.gz archives for each tagged release.

## Local package builds

Debian package:

    cmake -S . -B build-deb -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=/usr
    cmake --build build-deb
    cpack --config build-deb/CPackConfig.cmake -G DEB

RPM package:

    cmake -S . -B build-rpm -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=/usr
    cmake --build build-rpm
    cpack --config build-rpm/CPackConfig.cmake -G RPM

Arch package:

    makepkg --syncdeps --cleanbuild

For a local Arch installation, build/install the upstream `gigactld` package
first; the Plasma package declares it as a runtime dependency. For a direct
release install, install both package files in one `pacman -U` command.

The Arch recipe uses the QML install path expected by Qt on Arch. The RPM and
Debian generators use the paths selected by their own KDE/Qt development
packages. CPack writes generated archives under the build directory's
`packages/` subdirectory.

## Daemon service behavior

The Arch and RPM `gigactld` recipes leave `gigactl.service` stopped and
disabled. Once the hardware guard has accepted a supported Gigabyte model, the
user can start it explicitly with:

    systemctl enable --now gigactl.service

Starting the daemon grants it Embedded Controller access and restores saved
hardware state. The daemon package does not install a `modules-load.d` rule;
`gigactl.service` loads `ec_sys` only when an administrator starts the service.

Debian/Ubuntu currently use upstream's full `gigactl` package, whose existing
Debian service integration starts the daemon during installation.
