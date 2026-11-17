# Changelog

All notable changes to GigaControl Plasma will be documented here.

The format is based on Keep a Changelog.

## [1.0.0] - 2026-11-17

### Added

- Native KDE Plasma 6 applet with Cooling, RGB Keyboard and Settings pages.
- C++ QML plugin for telemetry and communication with gigactld over D-Bus.
- Cooling telemetry, upstream fan profile selection, keyboard controls and
  Turbo Boost control.
- Plasma-themed symbolic icon, widget preferences and English user guide.
- Source installation, hardware compatibility, architecture and safety docs.

### Changed

- Read Cooling telemetry directly from the upstream gigactld D-Bus API at the
  configured interval, removing the runtime dependency on the gfan process and
  its text output format.
- Replaced the Rofi and PySide6 prototypes with the native Plasma applet.
- Removed the old prototype files from the current source tree; their history
  remains available in Git.
- Renamed the GitHub repository from gigactl-rofi to gigactl-plasma to
  match the native Plasma 6 frontend.

### Security

- Kept hardware access and safety policy in the upstream gigactld project.
- Made monitoring read-only and hardware changes explicit user actions.
- Documented possible conflicts with other Turbo Boost controls.

### Validation

- Built and installed the user plasmoid, then observed live telemetry on a
  Gigabyte G5 KF running CachyOS and KDE Plasma 6.
