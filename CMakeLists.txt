
cmake_minimum_required(VERSION 3.20)

project(GigaControl
    VERSION 1.0.0
    LANGUAGES CXX
)

# Disable optional CMake 4.5 install preparation targets.
# ECM 6.31 does not declare BUILD_DEPENDS for generated QML type information.
if(CMAKE_VERSION VERSION_GREATER_EQUAL "4.5")
    set(CMAKE_SKIP_INSTALL_PREP_TARGETS ON)
endif()

# C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# KDE Extra CMake Modules
find_package(ECM 6.0.0 REQUIRED NO_MODULE)

set(CMAKE_MODULE_PATH ${ECM_MODULE_PATH})

include(KDEInstallDirs)
include(KDECMakeSettings)
include(KDECompilerSettings NO_POLICY_SCOPE)
include(ECMQmlModule)

# Qt dependencies
find_package(Qt6 6.5 REQUIRED COMPONENTS Core Qml DBus)

# Plasma dependencies
find_package(Plasma REQUIRED)

# C++ QML module
add_subdirectory(plugin)

# Install Plasma widget
plasma_install_package(plasma/package com.gigactl.control)

# Install its symbolic panel icon in the user's icon theme.
install(FILES plasma/package/contents/icons/io.github.smairio.gigactl-symbolic.svg
    DESTINATION ${KDE_INSTALL_ICONDIR}/hicolor/symbolic/apps)

# Native release packages. The daemon remains a separate upstream package.
set(CPACK_PACKAGE_NAME "gigactl-plasma")
set(CPACK_PACKAGE_VENDOR "GigaControl")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY
    "KDE Plasma widget for Gigabyte laptop controls")
set(CPACK_PACKAGE_VERSION ${PROJECT_VERSION})
set(CPACK_PACKAGE_CONTACT "GigaControl maintainers")
set(CPACK_PACKAGING_INSTALL_PREFIX "/usr")
set(CPACK_PACKAGE_DIRECTORY "${CMAKE_BINARY_DIR}/packages")
set(CPACK_GENERATOR "DEB;RPM")

set(CPACK_DEBIAN_PACKAGE_MAINTAINER "GigaControl maintainers")
set(CPACK_DEBIAN_PACKAGE_SECTION "kde")
set(CPACK_DEBIAN_PACKAGE_DEPENDS
    "gigactl (>= 1.0.3), plasma-workspace, qml6-module-org-kde-kirigami")
set(CPACK_DEBIAN_PACKAGE_SHLIBDEPS ON)

set(CPACK_RPM_PACKAGE_LICENSE "GPL-3.0-only")
set(CPACK_RPM_PACKAGE_GROUP "Applications/System")
set(CPACK_RPM_PACKAGE_REQUIRES "gigactld >= 1.0.3, plasma-workspace")

include(CPack)
