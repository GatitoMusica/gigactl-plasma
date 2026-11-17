# Roadmap

## First public release (1.0)

- [x] Implement the native Plasma 6 applet and its three sections.
- [x] Connect cooling and controls to the upstream gigactld project.
- [x] Read cooling telemetry from gigactld over D-Bus instead of launching gfan.
- [x] Add a Plasma-themed symbolic icon and user guide.
- [x] Document source build requirements and hardware limitations.
- [ ] Choose and test a distribution and update channel.
- [ ] Validate a clean installation and removal on a supported Plasma 6 system.
- [ ] Add repeatable build and QML/plugin checks to release automation.
- [ ] Publish release notes with tested hardware and known limitations.

## Later work

- Add a custom CPU/GPU fan curve editor using the upstream SetCurve API.
- Consider direct manual fan speed controls as an advanced Cooling option.
- Expand hardware validation beyond the development G5 KF.
- Add regression tests for D-Bus integration and UI state transitions.
- Improve packaging and upgrade handling for user-level installs.
- Evaluate further preferences only when they solve a clear user need.
