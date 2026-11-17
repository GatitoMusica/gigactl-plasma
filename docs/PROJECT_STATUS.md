# Project status

Last reviewed: 2026-11-17

## Product

**GigaControl Plasma** is the KDE Plasma 6 frontend for the upstream
gigactld daemon. The Plasma applet's display name is **GigaControl**. The
GitHub repository: GatitoMusica/gigactl-plasma.

## Implemented

- Native Plasma 6 applet with Cooling, RGB Keyboard and Settings pages.
- C++ QML module for telemetry and system D-Bus communication.
- Cooling telemetry is read from gigactld over D-Bus at the configured interval;
  the widget no longer launches `gfan` to collect readings.
- Cooling values and upstream fan profile selection.
- Keyboard power, brightness and color controls.
- Turbo Boost control with an on-screen conflict notice.
- Plasma temperature-unit and monitoring-interval preferences.
- Theme-aware symbolic applet icon and English in-widget guide.
- CMake build, install and uninstall configuration.

## Interactive validation

The applet has been tried on the development Gigabyte G5 KF with CachyOS,
Plasma 6 and gigactld. The new D-Bus telemetry path updates temperatures, RPM
and fan duty live. Profile changes, keyboard controls, Turbo Boost changes and
the daemon-unavailable UI state have also been observed. This is one-machine
interactive validation; broader model coverage and a repeatable automated test
suite remain outstanding.

## Release preparation still needed

- Choose and publish a distribution channel (for example, AUR or a source
  release) and validate installation and removal on a clean user environment.
- Add repeatable build or QML/plugin checks to the release workflow.
- Confirm final supported hardware wording against the upstream project.
- Review third-party licensing and attribution; finalize release notes.
