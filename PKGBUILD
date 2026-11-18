pkgname=gigactl-plasma
pkgver=1.0.0
pkgrel=1
pkgdesc='KDE Plasma 6 widget for monitoring and controlling supported Gigabyte laptops'
arch=('x86_64')
url='https://github.com/GatitoMusica/gigactl-plasma'
license=('GPL-3.0-only')
depends=('gigactld>=1.0.3' 'plasma-workspace' 'qt6-base' 'qt6-declarative')
makedepends=('cmake' 'extra-cmake-modules' 'git')
source=("git+https://github.com/GatitoMusica/gigactl-plasma.git#tag=v${pkgver}")
sha256sums=('SKIP')

build() {
    cmake -S "$srcdir/gigactl-plasma" -B build \
        -DCMAKE_BUILD_TYPE=Release \
        -DCMAKE_INSTALL_PREFIX=/usr \
        -DKDE_INSTALL_LIBDIR=lib \
        -DKDE_INSTALL_QMLDIR=lib/qt6/qml
    cmake --build build --parallel
}

package() {
    DESTDIR="$pkgdir" cmake --install build
}
