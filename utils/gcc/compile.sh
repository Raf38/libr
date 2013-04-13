#!/bin/sh -ue

BINUTILS_SRC=y
BINUTILS=y
GCC_SRC=y
GCC=y
ENV_SCRIPT=y

mkdir -p src
mkdir -p build
mkdir -p toolchain
cd  toolchain
TARGET_DIR=`pwd`
cd ../

if [ $BINUTILS_SRC = 'y' ];
then
    wget -nc http://ftp.gnu.org/gnu/binutils/binutils-2.23.2.tar.bz2
    cd src
    rm -rf binutils*;
    tar jxvf ../binutils*.tar.bz2
    mv binutils* binutils
    cd ../
fi;

if [ $BINUTILS = 'y' ];
then
    rm -rf build/binutils
    mkdir -p build/binutils
    cd build/binutils
    ../../src/binutils/configure \
        --prefix=$TARGET_DIR \
        --disable-nls \
        --disable-shared \
        --disable-multilib \
        --program-prefix=libr-
    make
    make install
    cd ../../
fi;

if [ $GCC_SRC = 'y' ]
then
    wget -nc ftp://gcc.gnu.org/pub/gcc/infrastructure/mpfr-2.4.2.tar.bz2
    wget -nc ftp://gcc.gnu.org/pub/gcc/infrastructure/gmp-4.3.2.tar.bz2
    wget -nc ftp://gcc.gnu.org/pub/gcc/infrastructure/mpc-0.8.1.tar.gz
    wget -nc http://gcc-uk.internet.bs/releases/gcc-4.8.0/gcc-4.8.0.tar.bz2
    cd  src
    tar jxvf ../gcc*.tar.bz2
    tar zxvf ../mpc*.tar.gz
    tar jxvf ../gmp*.tar.bz2
    tar jxvf ../mpfr*.tar.bz2
    mv gcc* gcc
    mv mpc* gcc/mpc
    mv gmp* gcc/gmp
    mv mpfr* gcc/mpfr
    cd ../
fi;

if [ $GCC = 'y' ]
then
    rm -rf build/gcc
    mkdir -p build/gcc
    cd build/gcc
    ../../src/gcc/configure --prefix=$TARGET_DIR \
        --disable-nls \
        --disable-shared \
        --without-headers \
        --with-newlib \
        --disable-libgomp \
        --disable-libmudflap \
        --disable-libssp \
        --disable-threads \
        --enable-languages=c \
        --disable-multilib \
        --program-prefix=libr-
    make all-gcc
    make install-gcc
    cd ../../
fi;

if [ $ENV_SCRIPT = 'y' ]
then
    echo "#!/bin/sh" > environment.sh
    echo >> environment.sh
    echo "export PATH=\$PATH:$TARGET_DIR/bin" >> environment.sh
fi;
