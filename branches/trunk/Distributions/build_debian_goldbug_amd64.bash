#!/usr/bin/env bash
# Alexis Megas.

if [ ! -x /usr/bin/dpkg-deb ]; then
    echo "Please install dpkg-deb."
    exit
fi

if [ ! -x /usr/bin/fakeroot ]; then
    echo "Please install fakeroot."
    exit 1
fi

# Preparing ./usr/local/goldbug:

make distclean 2>/dev/null
mkdir -p ./usr/local/goldbug/Documentation
mkdir -p ./usr/local/goldbug/Lib
mkdir -p ./usr/local/goldbug/SQL
mkdir -p ./usr/local/goldbug/Sounds
mkdir -p ./usr/local/goldbug/Translations
qmake -o Makefile goldbug.pro && make -j $(nproc)
cp -p ../../libNTL/unix.d/src/.libs/libntl.so* ./usr/local/goldbug/Lib/.
cp -p ../../libNTRU/libntru.so ./usr/local/goldbug/Lib/.
cp -p ./Data/spot-on-neighbors.txt ./usr/local/goldbug/.
cp -p ./Icons/Logo/goldbug.png ./usr/local/goldbug/.
cp -p ./SQL/* ./usr/local/goldbug/SQL/.
cp -p ./Shell/spot-on-kernel.sh ./usr/local/goldbug/.
cp -p ./Shell/goldbug.sh ./usr/local/goldbug/.
cp -p ./Sounds/* ./usr/local/goldbug/Sounds/.
cp -p ./GoldBug ./usr/local/goldbug/.
cp -p ./Spot-On-Kernel ./usr/local/goldbug/.
cp -p ./Translations/*.qm ./usr/local/goldbug/Translations/.
cp -pr ./Documentation/* ./usr/local/goldbug/Documentation/.
chmod -x ./usr/local/goldbug/Lib/lib*
find ./usr/local/goldbug -type f -exec chmod g+w {} \;
rm ./usr/local/spot-on/Documentation/*.qrc

# Preparing GoldBug-x_amd64.deb:

mkdir -p goldbug-debian/usr/local
mkdir -p goldbug-debian/usr/share/applications
cp -p ./goldbug.desktop goldbug-debian/usr/share/applications/.
cp -pr ./DEBIAN-GoldBug goldbug-debian/DEBIAN
cp -r ./usr/local/goldbug goldbug-debian/usr/local/.
fakeroot dpkg-deb --build goldbug-debian GoldBug-2022.07.20_amd64.deb
make distclean
rm -fr ./goldbug-debian
rm -fr ./usr
